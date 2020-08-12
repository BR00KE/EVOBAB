/*
 * @(#) FileViewer.cpp   1.0   Mar 5, 2013
 *
 * Andrea Maesani (andrea.maesani@epfl.ch)
 * Titus Cieslewski (dev@titus-c.ch)
 * Joshua Auerbach (joshua.auerbach@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2012-2016 Andrea Maesani, Titus Cieslweski, Joshua Auerbach
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
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>

#include "config/ConfigurationReader.h"
#include "config/RobogenConfig.h"
#include "evolution/representation/RobotRepresentation.h"
#include "scenario/Scenario.h"
#include "scenario/ScenarioFactory.h"
#include "utils/network/ProtobufPacket.h"
#include "utils/network/TcpSocket.h"
#include "utils/RobogenCollision.h"
#include "utils/RobogenUtils.h"
#include "viewer/FileViewerLog.h"
#include "Models.h"
#include "RenderModels.h"
#include "Robogen.h"
#include "Robot.h"
#include "robogen.pb.h"
#include "viewer/IViewer.h"

#include "Simulator.h"

#ifdef QT5_ENABLED
#include <QCoreApplication>
#endif

using namespace robogen;

#ifdef EMSCRIPTEN
#include <vector>
#include <boost/lexical_cast.hpp>
#include "emscripten.h"
#include <viewer/JSViewer.h>


int fakeMain(int argc, char *argv[]);

std::string EMSCRIPTEN_KEEPALIVE simulationViewer(int tab, std::string robotFileString,
		std::string configFile, int startPosition, std::string outputDirectory,
		int seed, bool enableWebGLLog, bool overwriteLogs) {

	boost::shared_ptr<RobogenConfig> configuration = NULL;
	try {
		configuration = ConfigurationReader::parseConfigurationFile(configFile);
	} catch (std::exception &e) { }
	if (configuration == NULL) {
		std::cerr << "Problems parsing the configuration file. Quit."
		<< std::endl;
		return "{\"error\" : \"ConfError\"}";
	}

	robogenMessage::Robot robotMessage;


	if (startPosition
			> configuration->getStartingPos()->getStartPosition().size()) {
		std::cerr << "Specified desired starting position " << startPosition
				<< " does not index a starting position. Aborting..."
				<< std::endl;
		return "{\"error\" : \"ConfError\"}";
	}
	// like for desktop version, should come in 1...n
	startPosition--;

	bool createRobotSuccess = false;
	try {
		createRobotSuccess = RobotRepresentation::createRobotMessageFromFile(
				robotMessage, robotFileString);
	} catch(std::exception &e) { }
	if (!createRobotSuccess) {
		std::cerr << "Problems parsing the robot file. Quit." << std::endl;
		return "{\"error\" : \"RobotError\"}";
	}

	// ---------------------------------------
	// Setup environment
	// ---------------------------------------
	boost::shared_ptr<Scenario> scenario = NULL;
	try {
		scenario = ScenarioFactory::createScenario(
				configuration);
	}
	catch (...) {}
	if (scenario == NULL) {
		return "{\"error\" : \"ScenarioError\"}";
	}
	scenario->setStartingPosition(startPosition);

	// ---------------------------------------
	// Set up log files
	// ---------------------------------------

	boost::shared_ptr<FileViewerLog> log;

	if (outputDirectory != "") {
		log.reset(
				new FileViewerLog(robotFileString, configFile,
						configuration->getObstacleFile(),
						configuration->getStartPosFile(),
						configuration->getLightSourceFile(),
						configuration->getScenarioFile(),
						std::string(outputDirectory), overwriteLogs,
						enableWebGLLog));
	}

	boost::random::mt19937 rng;
	if (seed != -1)
	rng.seed(seed);

	// ---------------------------------------
	// Run simulations
	// ---------------------------------------
	IViewer *viewer = new JSViewer();

	unsigned int simulationResult = runSimulations(scenario, configuration,
			robotMessage, viewer, rng, true, log);

	if (viewer != NULL) {
		delete viewer;
	}

	if (simulationResult == SIMULATION_FAILURE) {
		return "{\"error\" : \"SimulationError\"}";
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
	return "{\"fitness\" : \"" + boost::lexical_cast<std::string>(fitness) + "\"}";
}


#else
#include "viewer/Viewer.h"
#endif

// ODE World
dWorldID odeWorld;

// Container for collisions
dJointGroupID odeContactGroup;

bool interrupted;

bool fixed_is_directory(std::string path) {
	boost::system::error_code errorCode;
	bool result = boost::filesystem::is_directory(path, errorCode);
	if (errorCode.value() != 0) {
		//this second call will fire the correct exception
		return boost::filesystem::is_directory(path);
	} else {
		return result;
	}
}

void printUsage(char *argv[]) {
	std::cout << std::endl << "USAGE: " << std::endl << "      "
			<< std::string(argv[0]) << " <ROBOT_FILE, STRING> "
			<< "<CONFIGURATION_FILE, STRING> "
			<< "[<START_POSITION, INTEGER>] [<OPTIONS>]" << std::endl
			<< std::endl << "WHERE: " << std::endl
			<< "      <ROBOT_FILE> is the name of a file containing "
			<< "the robot description (either .json or .txt)." << std::endl
			<< std::endl << "      <CONFIGURATION_FILE> is the name of the "
			<< "corresponding simulation configuration file." << std::endl
			<< std::endl
			<< "      <START_POSITON> optionally specifies the starting "
			<< "position 1..n" << std::endl << std::endl << "OPTIONS: "
			<< std::endl << "      --debug" << std::endl
			<< "          Run in debug visualization mode." << std::endl
			<< std::endl << "      --help" << std::endl
			<< "          Print these usage instructions." << std::endl
			<< std::endl << "      --no-visualization" << std::endl
			<< "          Evaluate an individual without visualization."
			<< std::endl << std::endl << "      --pause" << std::endl
			<< "          Starts the simulation paused." << std::endl
			<< std::endl << "      --output <DIR, STRING>" << std::endl
			<< "          Generates output files: sensor logs and "
			<< "Arduino files." << std::endl << std::endl << "      --overwrite"
			<< std::endl
			<< "          Overwrite existing output file directory if it "
			<< "exists." << std::endl
			<< "          (Default is to keep creating new output "
			<< "directories with incrementing suffixes)." << std::endl
			<< std::endl << "      --record <N, INTEGER> <DIR, STRING>"
			<< std::endl
			<< "          Save frames to file (for video rendering)."
			<< std::endl
			<< "          Saves every <N>th simulation step in directory "
			<< "<DIR>." << std::endl << std::endl
			<< "      --seed <A, INTEGER> " << std::endl
			<< "          Set the seed A for the random number generator "
			<< "for noisy evaluations." << std::endl << std::endl
			<< "      --speed <S, FLOAT>" << std::endl
			<< "          Run visualization at S * real time "
			<< "(default is 1)." << std::endl << std::endl
			<< "      --webgl"
			<< std::endl
			<< "          Record json file for use with the WebGL "
			<< "visualizer (only valid if --output is specified)." << std::endl
			<< std::endl
			<< "      Notes: " << std::endl
			<< "        (a) Without visualization you cannot record frames,"
			<< " and setting speed has no effect "
			<< "(will always run as fast possible)." << std::endl
			<< "        (b) Speed will be capped by the rate at which your"
			<< " system is capable of running the simulation." << std::endl
			<< "              For complex simulations this may be slower "
			<< "than real time." << std::endl
			<< "        (c) Recording frames may make simulation run slower"
			<< " than requested speed." << std::endl << std::endl << std::endl;
}

void printHelp() {
	ConfigurationReader::parseConfigurationFile("help");
}

/**
 * Decodes a robot saved on file and visualize it
 */
#ifndef EMSCRIPTEN
int main(int argc, char *argv[]) {
	startRobogen();

#ifdef QT5_ENABLED
	QCoreApplication a(argc, argv);
#endif

	if (argc > 1 && std::string(argv[1]) == "--help") {
		printUsage(argv);
		printHelp();
		exitRobogen(EXIT_SUCCESS);
	}

	if (argc < 3) {
		printUsage(argv);
		exitRobogen(EXIT_FAILURE);
	}

	// Decode configuration file
	boost::shared_ptr<RobogenConfig> configuration =
			ConfigurationReader::parseConfigurationFile(std::string(argv[2]));
	if (configuration == NULL) {
		std::cerr << "Problems parsing the configuration file. Quit."
				<< std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	// verify desired start position is specified in configuration
	unsigned int desiredStart = 0;
	unsigned int recordFrequency = 0;
	bool recording = false;
	std::string recordDirectoryName = "";

	bool writeLog = false;
	char *outputDirectoryName;

	bool writeWebGL = false;
	bool overwrite = false;

	int currentArg = 3;
	if (argc >= 4 && !boost::starts_with(argv[3], "--")) {
		std::stringstream ss(argv[3]);
		currentArg++;
		ss >> desiredStart;
		--desiredStart; // -- accounts for parameter being 1..n
		if (ss.fail()) {
			std::cerr << "Specified desired starting position \"" << argv[3]
					<< "\" is not an integer. Aborting..." << std::endl;
			exitRobogen(EXIT_FAILURE);
		}
		if (desiredStart
				>= configuration->getStartingPos()->getStartPosition().size()) {
			std::cout << "Specified desired starting position " << argv[3]
					<< " does not index a starting position. Aborting..."
					<< std::endl;
			exitRobogen(EXIT_FAILURE);
		}
	}
	bool visualize = true;
	bool startPaused = false;
	double speed = 1.0;
	bool debug = false;
	int seed = -1;
	for (; currentArg < argc; currentArg++) {
		if (std::string("--help").compare(argv[currentArg]) == 0) {
			printUsage(argv);
			printHelp();
			exitRobogen(EXIT_FAILURE);
		} else if (std::string("--record").compare(argv[currentArg]) == 0) {
			if (argc < (currentArg + 3)) {
				std::cerr << "In order to record frames, must provide frame "
						<< "frequency and target directory."
						<< std::endl;
				exitRobogen(EXIT_FAILURE);
			}
			recording = true;
			currentArg++;
			std::stringstream ss(argv[currentArg]);
			ss >> recordFrequency;
			if (ss.fail()) {
				std::cerr << "Specified record frequency \"" << argv[currentArg]
						<< "\" is not an integer. Aborting..." << std::endl;
				exitRobogen(EXIT_FAILURE);
			}
			currentArg++;

			recordDirectoryName = std::string(argv[currentArg]);
			int curIndex = 0;
			std::string tempPath = recordDirectoryName;
			while (fixed_is_directory(tempPath)) {
				std::stringstream newPath;
				newPath << recordDirectoryName << "_" << ++curIndex;
				tempPath = newPath.str();
			}

			recordDirectoryName = tempPath;

			boost::filesystem::path recordDirectory(
					recordDirectoryName.c_str());

			if (recording
					&& !boost::filesystem::is_directory(recordDirectory)) {
				boost::filesystem::create_directories(recordDirectory);
			}

		} else if (std::string("--output").compare(argv[currentArg]) == 0) {
			if (argc < (currentArg + 2)) {
				std::cerr << "In order to write output files, must provide "
										<< "directory."
										<< std::endl;
				exitRobogen(EXIT_FAILURE);

			}
			writeLog = true;
			currentArg++;

			outputDirectoryName = argv[currentArg];
		} else if (std::string("--no-visualization").compare(argv[currentArg])
				== 0) {
			visualize = false;
		} else if (std::string("--pause").compare(argv[currentArg]) == 0) {
			startPaused = true;
		} else if (std::string("--speed").compare(argv[currentArg]) == 0) {
			if (argc < (currentArg + 2)) {
				std::cerr << "Must specify a speed factor with option --speed."
						<< std::endl;
				exitRobogen(EXIT_FAILURE);
			}
			currentArg++;
			std::stringstream ss(argv[currentArg]);
			ss >> speed;
		} else if (std::string("--debug").compare(argv[currentArg]) == 0) {
			debug = true;
		} else if (std::string("--seed").compare(argv[currentArg]) == 0) {
			if (argc < (currentArg + 2)) {
				std::cerr << "Must specify a seed value with option --seed."
						<< std::endl;
				exitRobogen(EXIT_FAILURE);
			}
			currentArg++;
			std::stringstream ss(argv[currentArg]);
			ss >> seed;
		} else if (std::string("--webgl").compare(argv[currentArg]) == 0) {
			writeWebGL = true;
		} else if (std::string("--overwrite").compare(argv[currentArg]) == 0) {
			overwrite = true;
		}

	}

	if (recording && !visualize) {
		std::cerr << "Cannot record without visualization enabled!" <<
				std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	if (startPaused && !visualize) {
		std::cerr << "Cannot start paused without visualization enabled." <<
				std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	if (writeWebGL && (!writeLog)) {
		std::cerr << "Cannot write json file for WebGL visualizer without " <<
				"specifying output directory." << std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	if (overwrite && (!writeLog)) {
		std::cerr << "No output directory was specified, so there is " <<
				"nothing to overwrite." << std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	boost::random::mt19937 rng;
	if (seed != -1)
		rng.seed(seed);

	// ---------------------------------------
	// Robot decoding
	// ---------------------------------------
	robogenMessage::Robot robotMessage;
	std::string robotFileString(argv[1]);

	if(!RobotRepresentation::createRobotMessageFromFile(robotMessage,
			robotFileString)) {
		exitRobogen(EXIT_FAILURE);
	}

	// ---------------------------------------
	// Setup environment
	// ---------------------------------------

	boost::shared_ptr<Scenario> scenario = ScenarioFactory::createScenario(
			configuration);
	if (scenario == NULL) {
		exitRobogen(EXIT_FAILURE);
	}
	scenario->setStartingPosition(desiredStart);

	// ---------------------------------------
	// Set up log files
	// ---------------------------------------

	boost::shared_ptr<FileViewerLog> log;

	if (writeLog) {
		log.reset(
				new FileViewerLog(std::string(argv[1]), std::string(argv[2]),
						configuration->getObstacleFile(),
						configuration->getStartPosFile(),
						configuration->getLightSourceFile(),
						configuration->getScenarioFile(),
						std::string(outputDirectoryName), overwrite,
						writeWebGL));
	}

	// ---------------------------------------
	// Run simulations
	// ---------------------------------------
	IViewer *viewer = NULL;
	if (visualize) {
		viewer = new Viewer(startPaused, debug,
				speed, recording, recordFrequency,
				recordDirectoryName);
	}

	unsigned int simulationResult = runSimulations(scenario, configuration,
			robotMessage, viewer, rng, true, log);

	if (viewer != NULL) {
		delete viewer;
	}

	if (simulationResult == SIMULATION_FAILURE) {
		exitRobogen(EXIT_FAILURE);
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
	std::cout << "Fitness for the current solution: " << fitness << std::endl
			<< std::endl;

	exitRobogen(EXIT_SUCCESS);
}

#endif
