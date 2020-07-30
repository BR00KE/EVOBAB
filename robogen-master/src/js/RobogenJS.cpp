/*
 * @(#) EmscriptenTest.cpp   1.0   Aug 11, 2015
 *
 * Guillaume Leclerc (guillaume.leclerc@epfl.ch)
 * Joshua Auerbach (joshua.auerbach@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2012-2016 Guillaume Leclerc, Joshua Auerbach
 *
 * Laboratory of Intelligent Systems, EPFL
 *
 * This file is part of the ROBOGEN Framework.
 *
 * The ROBOGEN Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License (GPL)
 * as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @(#) $Id$
 */

/*
 * robogen_js.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: guillaume3
 */
#include <iostream>
#include <emscripten/bind.h>
#include <emscripten.h>
#include "utils/JSUtils.h"

#include <viewer/JSViewer.h>
#include <scenario/JSScenario.h>

#include "model/objects/BoxObstacle.h"
#include <vector>

/***** WARNING ******
 * WE ARE INCLUDING .cpp files !!
 * This file is "merging" cpp files and expose functions to the javascript world
 ********************/

void sendJSEvent(std::string name, std::string jsonData) {

	std::string command = "self.cppEvent(\"";
	command += name;
	command += "\", ";
	command += jsonData;
	command += ")";
#ifdef EMSCRIPTEN
	emscripten_run_script(command.c_str());
#else
	std::cout << command << std::endl;
#endif
}

int main(int argc, char** argv) {
	std::cout << "A robogenJS worker has started, he is waiti"
			"ng for any task"
			<< std::endl;
	return 0;
}

#ifdef EMSCRIPTEN
#include <Evolver.cpp>
#include <viewer/FileViewer.cpp>

double EMSCRIPTEN_KEEPALIVE evaluate(int ptr, int length) {
	unsigned char* data = (unsigned char*) ptr;
	boost::random::mt19937 rng;
	rng.seed(ptr);

	ProtobufPacket<robogenMessage::EvaluationRequest> packet;
	std::vector<unsigned char> payloadBuffer;
	for (unsigned int i = ProtobufPacket<robogenMessage::EvaluationRequest>::HEADER_SIZE ; i < length; ++i) {
		payloadBuffer.push_back(data[i]);
	}
	packet.decodePayload(payloadBuffer);
	// ---------------------------------------
	//  Decode configuration file
	// ---------------------------------------

	boost::shared_ptr<RobogenConfig> configuration =
	ConfigurationReader::parseRobogenMessage(
			packet.getMessage()->configuration());
	if (configuration == NULL) {
		std::cerr
		<< "Problems parsing the configuration file. Quit."
		<< std::endl;
		exitRobogen(EXIT_FAILURE);
		return -1;
	}

	// ---------------------------------------
	// Setup environment
	// ---------------------------------------

	boost::shared_ptr<Scenario> scenario =
	ScenarioFactory::createScenario(configuration);
	if (!scenario) {
		exitRobogen(EXIT_FAILURE);
		return -1;
	}

	std::cout
	<< "-----------------------------------------------"
	<< std::endl;

	// ---------------------------------------
	// Run simulations
	// ---------------------------------------

	JSViewer* viewer = new JSViewer();

	unsigned int simulationResult = runSimulations(scenario,
			configuration, packet.getMessage()->robot(),
			viewer, rng);

	delete viewer;

	if (simulationResult == SIMULATION_FAILURE) {
		exitRobogen(EXIT_FAILURE);
		return -1;
	}

	// ---------------------------------------
	// Compute fitness
	// ---------------------------------------
	double fitness;
	if (simulationResult == CONSTRAINT_VIOLATED) {
		fitness = MIN_FITNESS;
	} else {
		fitness = scenario->getFitness();
	}
	std::cout << "Fitness for the current solution: " << fitness
	<< std::endl << std::endl;
	return fitness;
}

struct ScenarioWrapper : public emscripten::wrapper<JSScenario> {
    EMSCRIPTEN_WRAPPER(ScenarioWrapper);
    double getFitness() {
        return call<double>("getFitness");
    }

    bool endSimulationJS() {
    	return call<bool>("endSimulation");
    }

    bool setupSimulation() {
    	return call<bool>("setupSimulation");
    }

    bool afterSimulationStep() {
    	return call<bool>("afterSimulationStep");
    }


};

#define TEST_EM
#ifdef TEST_EM
#include "js/EmscriptenTest.cpp"
#endif

// file utils for loading remote files

bool fileExists(std::string fileName) {
	return boost::filesystem::exists( fileName );
}

void saveFile(std::string fileName, std::string contents) {

	const boost::filesystem::path filePath(fileName);

	try{
		boost::filesystem::create_directories(filePath.parent_path());
	} catch(const boost::filesystem::filesystem_error &err){
		js::log(err.what());
		return;
	}

	std::ofstream out;


	out.open(fileName.c_str());
	if (!out.is_open()){
		js::log("Can't open " + fileName);
		return;
	}

	out << contents;
	out.close();

}


// helper functions

emscripten::val getMotorId(boost::shared_ptr<Motor> motor) {
	emscripten::val result(emscripten::val::object());
	ioPair id = motor->getId();
	result.set("partId", id.first);
	result.set("ioId", id.second);
	return result;
}

template<typename VectorType>
emscripten::val toArray(std::vector<VectorType> v) {
	emscripten::val result(emscripten::val::array());
	for(size_t i = 0; i < v.size(); ++i) {
		result.set(i, v[i]);
	}
	return result;
}


emscripten::val getModelSensors(boost::shared_ptr<Model> model) {
	std::vector<boost::shared_ptr<Sensor> > sensors;
	if( boost::dynamic_pointer_cast<PerceptiveComponent>(model) ) {
		boost::dynamic_pointer_cast<PerceptiveComponent>(model
												)->getSensors(sensors);
	}
	return toArray< boost::shared_ptr<Sensor> >(sensors);
}

emscripten::val getAABB(boost::shared_ptr<Robot> robot) {
	double minX, maxX, minY, maxY, minZ, maxZ;
	robot->getAABB(minX, maxX, minY, maxY, minZ, maxZ);
	emscripten::val aabb(emscripten::val::object());
	aabb.set("minX", minX);
	aabb.set("maxX", maxX);
	aabb.set("minY", minY);
	aabb.set("maxY", maxY);
	aabb.set("minZ", minZ);
	aabb.set("maxZ", maxZ);
	return aabb;
}

emscripten::val getBodyParts(boost::shared_ptr<Robot> robot) {
	return toArray< boost::shared_ptr<Model> >(robot->getBodyParts());
}

emscripten::val getRobotSensors(boost::shared_ptr<Robot> robot) {
	return toArray< boost::shared_ptr<Sensor> >(robot->getSensors());
}

emscripten::val getMotors(boost::shared_ptr<Robot> robot) {
	return toArray< boost::shared_ptr<Motor> >(robot->getMotors());
}

emscripten::val getLightSources(boost::shared_ptr<Environment> environment) {
	return toArray< boost::shared_ptr<LightSource> >(
										environment->getLightSources());
}

emscripten::val getObstacles(boost::shared_ptr<Environment> environment) {
	return toArray< boost::shared_ptr<Obstacle> >(environment->getObstacles());
}

void setLightSourcePosition(boost::shared_ptr<LightSource> lightSource,
		float x, float y, float z) {
	lightSource->setPosition(osg::Vec3(x,y,z));
}

EMSCRIPTEN_BINDINGS(my_module) {
	emscripten::function("simulationViewer", &simulationViewer);
	emscripten::function("runEvolution", &runEvolution);
	emscripten::function("evaluate", &evaluate);
	emscripten::function("evaluationResultAvailable", &evaluationResultAvailable);
	emscripten::function("evaluationIsDone", &evaluationIsDone);

	//emscripten::register_vector<boost::shared_ptr<LightSource> >("LightSourceVector");


	// not sure why the casting is necessary, but would not compile without it
	// and works like this
	// exposes x,y,z as read only properties
	emscripten::class_<osg::Vec3>("Vec3")
			//.constructor<float, float, float>()
			.property("x",static_cast<osg::Vec3::value_type(osg::Vec3::*)() const>(&osg::Vec3::x))
			.property("y",static_cast<osg::Vec3::value_type(osg::Vec3::*)() const>(&osg::Vec3::y))
			.property("z",static_cast<osg::Vec3::value_type(osg::Vec3::*)() const>(&osg::Vec3::z))
			;

	emscripten::class_<osg::Quat>("Quat")
			//.constructor<float, float, float>()
			.property("x",static_cast<osg::Quat::value_type(osg::Quat::*)() const>(&osg::Quat::x))
			.property("y",static_cast<osg::Quat::value_type(osg::Quat::*)() const>(&osg::Quat::y))
			.property("z",static_cast<osg::Quat::value_type(osg::Quat::*)() const>(&osg::Quat::z))
			.property("w",static_cast<osg::Quat::value_type(osg::Quat::*)() const>(&osg::Quat::w))
			;


	emscripten::class_<Model>("Model")
		.smart_ptr<boost::shared_ptr<Model> >("shared_ptr<Model>")
		.function("getId", &Model::getId)
		.function("getRootPosition", &Model::getRootPosition)
		.function("getRootAttitude", &Model::getRootAttitude)
		.function("getSensors", &getModelSensors)
		.function("getType", &RobogenUtils::getPartType)
		;

	emscripten::class_<Sensor>("Sensor")
		.smart_ptr<boost::shared_ptr<Sensor> >("shared_ptr<Sensor>")
		.function("getLabel", &Sensor::getLabel)
		.function("read", &Sensor::read)
		.function("getType", &RobogenUtils::getSensorType)
		;

	emscripten::class_<Motor>("Motor")
		.smart_ptr<boost::shared_ptr<Motor> >("shared_ptr<Motor>")
		.function("getVelocity", &Motor::getVelocity)
		.function("getPosition", &Motor::getPosition)
		.function("getTorque", &Motor::getTorque)
		.function("getId", &getMotorId)
		;

	emscripten::class_<Robot>("Robot")
		.smart_ptr<boost::shared_ptr<Robot> >("shared_ptr<Robot>")
		.function("getBodyParts", &getBodyParts)
		.function("getCoreComponent", &Robot::getCoreComponent)
		.function("getSensors", &getRobotSensors)
		.function("getMotors", &getMotors)
		.function("getAABB", &getAABB)
		;


	emscripten::class_<Scenario>("Scenario")
		.function("getRobot", &Scenario::getRobot)
		.function("getEnvironment", &Scenario::getEnvironment)
		.function("stopSimulationNow", &Scenario::stopSimulationNow)
		;

	emscripten::class_<JSScenario, emscripten::base<Scenario>>("JSScenario")
        .function("getFitness", &JSScenario::getFitness, emscripten::pure_virtual())
        .function("afterSimulationStep",
        		emscripten::optional_override([](JSScenario& self) {
							return self.JSScenario::afterSimulationStep();
						}))
		.function("setupSimulation",
				emscripten::optional_override([](JSScenario& self) {
							return self.JSScenario::setupSimulation();
						}))
		.function("endSimulation",
				emscripten::optional_override([](JSScenario& self) {
							return self.JSScenario::endSimulationJS();
						}))
        .function("setId", &JSScenario::setId)
        .function("getId", &JSScenario::getId)
        .function("printRobotPosition", &JSScenario::printRobotPosition)
        .function("getCurTrial", &JSScenario::getCurTrial)
        .function("vectorDistance", &JSScenario::vectorDistance)
        .allow_subclass<ScenarioWrapper>("ScenarioWrapper")
		;

	emscripten::class_<PositionObservable>("PositionObservable")
		.smart_ptr<boost::shared_ptr<PositionObservable> >("shared_ptr<PositionObservable>")
		.function("getPosition", &PositionObservable::getPosition)
		.function("getAttitude", &PositionObservable::getAttitude)
		;

	emscripten::class_<LightSource,  emscripten::base<PositionObservable>>("LightSource")
		.smart_ptr<boost::shared_ptr<LightSource> >("shared_ptr<LightSource>")
		.function("getIntensity", &LightSource::getIntensity)
		.function("setPosition", &setLightSourcePosition)
		.function("setIntensity", &LightSource::setIntensity);
		;

	emscripten::class_<Obstacle,  emscripten::base<PositionObservable>>("Obstacle")
		.smart_ptr<boost::shared_ptr<Obstacle> >("shared_ptr<Obstacle>")
		;

	emscripten::class_<BoxObstacle,  emscripten::base<Obstacle>>("BoxObstacle")
		.smart_ptr<boost::shared_ptr<BoxObstacle> >("shared_ptr<BoxObstacle>")
		.function("getSize", &BoxObstacle::getSize)
		;

	emscripten::class_<Environment>("Environment")
		.smart_ptr<boost::shared_ptr<Environment> >("shared_ptr<Environment>")
		//.function("getTimeElapsed")
		.function("getLightSources", &getLightSources)
		//.function("getLightSourcesVector", &Environment::getLightSources)
		.function("getAmbientLight", &Environment::getAmbientLight)
		.function("getObstacles", &getObstacles)
		;

	emscripten::function("fileExists", &fileExists);
	emscripten::function("saveFile", &saveFile);

#ifdef TEST_EM

	//emscripten::class_<Base>("Base")
	//	.function("doSomething", &Base::doSomething);
	//	;


	emscripten::class_<Derived>("Derived")
	    .constructor()
	    .function("doSomething",static_cast<void(Derived::*)()>(&Base::doSomething))//;// &Base::doSomething)
	    ;

	emscripten::function("testReturnVec3", &testReturnVec3);

	emscripten::function("testPassVal", &testPassVal);

	emscripten::function("testReturnVector", &testReturnVector);
	emscripten::function("testReturnArray", &testReturnArray);
	emscripten::function("testReturnSharedPtr", &testReturnSharedPtr);
	emscripten::function("testReturnRawPtr", &testReturnRawPtr, emscripten::allow_raw_pointers());
	emscripten::function("runEmBindTest", &runEmBindTest);
	emscripten::function("printTestStruct", &printTestStruct, emscripten::allow_raw_pointers());

	emscripten::class_<TestStruct>("TestStruct")
			//.constructor<float>()
			.property("a", &TestStruct::a)
			.smart_ptr<boost::shared_ptr<TestStruct> >("shared_ptr<TestStruct>");


	emscripten::function("ls", &ls);

#endif

}
#endif

