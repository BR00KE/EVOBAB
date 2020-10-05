/*
 * @(#) BrainEvolver.cpp   1.0   Sep 2, 2013
 *
 * Titus Cieslewski (dev@titus-c.ch)
 * Joshua Auerbach (joshua.auerbach@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2013-2016 Titus Cieslewski, Joshua Auerbach
 *
 * Laboratory of Intelligent Systems, EPFL
 *
 * This file is part of the ROBOGEN Framework.
 *
 * The ROBOGEN Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Pcomplexity += ublic License (GPL)
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

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/lexical_cast.hpp>
#include "config/EvolverConfiguration.h"
#include "evolution/representation/RobotRepresentation.h"
#include "evolution/engine/EvolverLog.h"
#include "evolution/engine/Population.h"
#include "evolution/engine/Selector.h"
#include "evolution/engine/Mutator.h"
#include "evolution/engine/selectors/DeterministicTournament.h"

#include "evolution/engine/neat/NeatContainer.h"
#include <random>
#ifdef EMSCRIPTEN
#include <emscripten/bind.h>
#include "emscripten.h"
#include <utils/network/FakeJSSocket.h>
#include <sstream>

#endif

namespace robogen {
void init(unsigned int seed, std::string outputDirectory,
		std::string confFileName, bool overwrite, bool saveAll, bool complexityCost);

void printUsage(char *argv[]) {
	std::cout << std::endl << "USAGE: " << std::endl << "      "
			<< std::string(argv[0])
			<< " <SEED, INTEGER> <OUTPUT_DIRECTORY, STRING> "
			<< "<CONFIGURATION_FILE, STRING> [<OPTIONS>]" << std::endl
			<< std::endl << "WHERE: " << std::endl
			<< "      <SEED> is a number to seed "
			<< "the pseudorandom number generator." << std::endl << std::endl
			<< "      <OUTPUT_DIRECTORY> is the directory to write output "
			<< "files to." << std::endl << std::endl
			<< "      <CONFIGURATION_FILE> is the evolution"
			<< " configuration file to use." << std::endl << std::endl
			<< "OPTIONS: " << std::endl << "      --help" << std::endl
			<< "          Print all configuration options and exit."
			<< std::endl << std::endl << "      --overwrite" << std::endl
			<< "          Overwrite existing output file directory if it "
			<< "exists." << std::endl
			<< "          (Default is to keep creating new output "
			<< "directories with incrementing suffixes)." << std::endl
			<< std::endl << "      --save-all" << std::endl
			<< "          Save all individuals instead of just the generation"
			<< "best." << std::endl << std::endl;

}

void printHelp() {
	boost::shared_ptr<EvolverConfiguration> conf = boost::shared_ptr<
			EvolverConfiguration>(new EvolverConfiguration());
	conf->init("help");
	std::cout << std::endl;
	boost::shared_ptr<RobogenConfig> robotConf =
			ConfigurationReader::parseConfigurationFile("help");
}

//BK - novelty - probabalistically maintain an archive of max 50 individuals
std::vector<boost::shared_ptr<RobotRepresentation> > noveltyArchive;
void addToArchive(boost::shared_ptr<RobotRepresentation> & individual){
	boost::shared_ptr<RobotRepresentation> clone = boost::make_shared<RobotRepresentation>(RobotRepresentation(*individual));

	if(noveltyArchive.size()<50){
		noveltyArchive.push_back(clone);
	}
	//replace individual at random position in the archive
	else{ 

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(0,noveltyArchive.size()); // guaranteed unbiased

		int random_integer = uni(rng);
		noveltyArchive[random_integer]=clone;
	}
}

boost::shared_ptr<Population> population;
IndividualContainer children;
boost::shared_ptr<NeatContainer> neatContainer;
boost::shared_ptr<RobogenConfig> robotConf;
boost::shared_ptr<EvolverConfiguration> conf;
boost::shared_ptr<EvolverLog> log;
bool neat;
boost::shared_ptr<Selector> selector;
boost::shared_ptr<Mutator> mutator;
unsigned int generation;
boost::random::mt19937 rng;


std::vector<Socket*> sockets;

void parseArgsThenInit(int argc, char* argv[]) {

	startRobogen();

	// ---------------------------------------
	// verify usage and load configuration
	// ---------------------------------------
	if (argc > 1 && std::string(argv[1]) == "--help") {
		printUsage(argv);
		printHelp();
		exitRobogen(EXIT_SUCCESS);
	}

	if ((argc < 4)) {
		printUsage(argv);
		std::cout << "RUN: " << std::endl << std::endl
				<< "      " << std::string(argv[0])
				<< " --help to see all configuration options."
				<< std::endl << std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	unsigned int seed = atoi(argv[1]);

	std::string outputDirectory = std::string(argv[2]);
	std::string confFileName = std::string(argv[3]);

	bool overwrite = false;
	bool saveAll = false;
	// CH - added a complexity cost flag to command line arguments to indicate if experiment should be run with or without a complexity cost
	bool complexityCost = false;
	int currentArg = 4;
	for (; currentArg < argc; currentArg++) {
		if (std::string("--help").compare(argv[currentArg]) == 0) {
			printUsage(argv);
			printHelp();
			exitRobogen(EXIT_SUCCESS);
		} else if (std::string("--overwrite").compare(argv[currentArg]) == 0) {
			overwrite = true;
		} else if (std::string("--save-all").compare(argv[currentArg]) == 0) {
			saveAll = true;
		} else if (std::string("--complexity-cost").compare(argv[currentArg]) == 0) {
			complexityCost = true;
		}
		else {
			std::cerr << std::endl << "Invalid option: " << argv[currentArg]
							 << std::endl << std::endl;
			printUsage(argv);
			exitRobogen(EXIT_FAILURE);
		}

	}

	init(seed, outputDirectory, confFileName, overwrite, saveAll, complexityCost);

}

void init(unsigned int seed, std::string outputDirectory,
		std::string confFileName, bool overwrite, bool saveAll, bool complexityCost) {

	// Seed random number generator
	rng.seed(seed);

	conf.reset(new EvolverConfiguration());
	if (!conf->init(confFileName)) {
		std::cerr << "Problems parsing the evolution configuration file. Quit."
				<< std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	robotConf = ConfigurationReader::parseConfigurationFile(
			conf->simulatorConfFile);

	if (robotConf == NULL) {
		std::cerr << "Problems parsing the robot configuration file. Quit."
				<< std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	// ---------------------------------------
	// Set up evolution
	// ---------------------------------------

	if (conf->selection == conf->DETERMINISTIC_TOURNAMENT) {
		selector.reset(new DeterministicTournament(conf->tournamentSize, rng));
	} else {
		std::cerr << "Selection type id " << conf->selection << " unknown."
				<< std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	mutator.reset(new Mutator(conf, rng));
	log.reset(new EvolverLog());
	try {
		if (!log->init(conf, robotConf, outputDirectory, overwrite, saveAll)) {
			std::cerr << "Error creating evolver log. Aborting." << std::endl;
			exitRobogen(EXIT_FAILURE);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		exitRobogen(EXIT_FAILURE);
	} catch (...) {
		std::cerr << "non standard exception " << std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	// ---------------------------------------
	// parse robot from file & initialize population
	// ---------------------------------------

	boost::shared_ptr<RobotRepresentation> referenceBot(
			new RobotRepresentation());
	bool growBodies = false;
	if (conf->evolutionMode == EvolverConfiguration::BRAIN_EVOLVER
			&& conf->referenceRobotFile.compare("") == 0) {
		std::cerr << "Trying to evolve brain, but no robot file provided."
				<< std::endl;
		exitRobogen(EXIT_FAILURE);
	} else if (conf->referenceRobotFile.compare("") != 0) {
		if (!referenceBot->init(conf->referenceRobotFile)) {
			std::cerr << "Failed interpreting robot from text file"
					<< std::endl;
			exitRobogen(EXIT_FAILURE);
		}
	} else { //doing body evolution and don't have a reference robot
		if (referenceBot->init()) {
			growBodies = true;
		} else {
			std::cerr << "Failed creating base robot for body evolution"
					<< std::endl;
			exitRobogen(EXIT_FAILURE);
		}
	}
	// set neat to True or False based on config files
	neat = (conf->evolutionaryAlgorithm == EvolverConfiguration::HYPER_NEAT);
	population.reset(new Population()); //Population() calls IndividualContainer() which just sets evaluated sorted and evaluated both false
	// initialise the robot population from randomly mutated versions of the reference robot specified in the config
	if (!population->init(referenceBot, conf->mu, mutator, growBodies,
			((conf->useBrainSeed || neat)), conf )) { 
		std::cerr << "Error when initializing population!" << std::endl;
		exitRobogen(EXIT_FAILURE);
	}
	// initialise the corresponding population of CPPNs (1 per robot)
	if (neat) {
		neatContainer.reset(new NeatContainer(conf, population, seed, rng));
		// initialise population of HyperNEAT CPPNs based on robot population
		std::vector<NEAT::Genome> initialNEATPop = neatContainer->getInitialGenomePop();
		int c=0;
		// assign CPPNs to each robot and then query the CPPN for the robot's ANN connection weight information
		for(Population::iterator i = population->begin(); i!=population->end(); i++){
			boost::shared_ptr<RobotRepresentation> rep = *i;
			rep->neatGenome = initialNEATPop[c];
			// set the robot's ANN connection weight map based on CPPN query
			rep->setWeightMap(neatContainer->queryCppn(rep->getNeatGenomePointer(),rep)->getWeightMap());
			c++;
		}
	}
	
	// ---------------------------------------
	// open sockets for communication with simulator processes
	// ---------------------------------------
#ifndef EMSCRIPTEN
	sockets.resize(conf->sockets.size());
	for (unsigned int i = 0; i < conf->sockets.size(); i++) {
		sockets[i] = new TcpSocket;
#ifndef FAKEROBOTREPRESENTATION_H // do not bother with sockets when using
		// benchmark
		if (!sockets[i]->open(conf->sockets[i].first,
				conf->sockets[i].second)) {
			std::cerr << "Could not open connection to simulator" << std::endl;
			exitRobogen(EXIT_FAILURE);
		}
#endif
	}
#endif

	// ---------------------------------------
	// run evolution TODO stopping criterion
	// ---------------------------------------


	if(neat) {
		if(!neatContainer->fillPopulationWeights(population)) {
			std::cerr << "Filling weights from NEAT failed." << std::endl;
		 	exitRobogen(EXIT_FAILURE);
		}
	}

	generation = 1;
	// evaluate the complexity of each robot in the population
	population->evaluateComplexity(complexityCost);
	// evaluate the fitness of each robot in the population
	population->evaluate(robotConf, sockets); 

	// if config file specifies novelty search, calculate the novelty score of each member of the population and add members to novelty archive
	if(conf->noveltySearch){
		//probabalistically add members of population to novelty archive
		std::vector<boost::shared_ptr<RobotRepresentation> > pop(population->begin(),population->end());
		std::vector<boost::shared_ptr<RobotRepresentation> >::iterator It = pop.begin();
		std::random_device rd;     
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(0,11); 
		while(It!=pop.end()){
			int random_integer = uni(rng);
			if(random_integer<=3){
				addToArchive(*It);
			}
			It++;
		}		
		population->evaluateNovelty(noveltyArchive, pop);//changed to a call for second novelty metric
		std::sort(population->begin(),population->end(),
					[](boost::shared_ptr<RobotRepresentation> & a, boost::shared_ptr<RobotRepresentation> & b)
					{return a->getNoveltyScore()>b->getNoveltyScore();});
	}

}//end of init

void mainEvolutionLoop();

void postEvaluateNEAT() {
	population->sort(true); 
	mainEvolutionLoop();
}

void postEvaluateStd() {

	// comma or plus?
	if (conf->replacement == conf->PLUS_REPLACEMENT) {
		children += *population.get();
	}

	// replace
	population.reset(new Population());
	if (!population->init(children, conf->mu,conf->noveltySearch)) {
		std::cout << "Error when initializing population!" << std::endl;
		exitRobogen(EXIT_FAILURE);
	}
	mainEvolutionLoop();
}

void triggerPostEvaluate() {
	if (generation == 1) {
		mainEvolutionLoop();
	} else {
		// CH - added a post evaluate method for the case when co-evolution uses HyperNEAT for neural evolution
		if (neat && conf->evolutionMode == EvolverConfiguration::FULL_EVOLVER) {
			postEvaluateStd();
		}
		else if(neat){
			postEvaluateNEAT();
		} else {
			postEvaluateStd();
		}
	}
}

void mainEvolutionLoop() {
#ifdef EMSCRIPTEN
	std::stringstream ss;
	double best, average, stddev;
	population->getStat(best, average, stddev);
	ss << "{best : " << best << ", average : " << average << ", stddev : "
			<< stddev << ", generation : " << generation << "}";
	sendJSEvent("stats", ss.str());
#endif

	std::cout << "mainEvolutionLoop" << std::endl;
	if(conf->noveltySearch){
		population->sort(true);
	}
	if (!log->logGeneration(generation, *population.get())) {
		exitRobogen(EXIT_FAILURE);
	}
	if(conf->noveltySearch){
		population->sort(true,conf->noveltySearch);
	}

	generation++;

	// main evolution loop
	// repeat until number of generations specified in config reached
	if (generation <= conf->numGenerations) {
		std::cout << "Generation " << generation << std::endl;
		children.clear();

		// select parents fit for reproduction and produce offspring
		if (neat) { 
			// initialise a deterministic tournament selector 
			selector->initPopulation(population);
			unsigned int numOffspring = 0;
			// keep creating children until the number of offsping (lambda) in the config is reached
			while (numOffspring < conf->lambda) {

				std::pair<boost::shared_ptr<RobotRepresentation>,
						boost::shared_ptr<RobotRepresentation> > selection;
				// Select two distinct parents
				if (!selector->select(selection.first)) {
					std::cerr << "Selector::select() failed." << std::endl;
					exitRobogen(EXIT_FAILURE);
				}
				unsigned int tries = 0;
				do {
					if (tries > 10000) {
						std::cerr << "Selecting second parent failed after "
								"10000 tries, giving up.";
						exitRobogen(EXIT_FAILURE);
					}
					if (!selector->select(selection.second)) {
						std::cerr << "Selector::select() failed." << std::endl;
						exitRobogen(EXIT_FAILURE);
					}
					tries++;
				} while (selection.first == selection.second);
				// mate parents to produce offspring
				std::vector<boost::shared_ptr<RobotRepresentation> > offspring
					= mutator->createOffspringHyperNEAT(selection.first,
											   selection.second);
				// fill the offspring's brains based on the new CPPN 
				for(boost::shared_ptr<RobotRepresentation> rep:offspring){
					if(!neatContainer->fillBrain(rep->getNeatGenomePointer(),rep)) {
						std::cerr << "Filling offspring weights from NEAT failed." << std::endl;
						exitRobogen(EXIT_FAILURE);
					}
					// set the offspring's ANN connection weight map by querying CPPN
					rep->setWeightMap(neatContainer->queryCppn(rep->getNeatGenomePointer(),rep)->getWeightMap());
				}
				
				// no crossover, or can fit both new individuals
				if ( (numOffspring + offspring.size()) <= conf->lambda ) {
					children.insert(children.end(), offspring.begin(),
													offspring.end() );
					numOffspring += offspring.size();
				} else { // crossover, but can only fit one
					children.push_back(offspring[0]);
					numOffspring++;
				}
			}
			// evaluate the complexity of newly created offspring
			children.evaluateComplexity(robotConf->getComplexityCost());
			// evaluate the fitness of newly created offspring
			children.evaluate(robotConf, sockets);
			// evaluate the novelty of newly created offspring
			if(conf->noveltySearch){
				std::vector<boost::shared_ptr<RobotRepresentation> > pop(population->begin(),population->end());
				children.evaluateNovelty(noveltyArchive,pop);//probabalistically add children to novelty archive
				std::vector<boost::shared_ptr<RobotRepresentation> >::iterator childIt = children.begin();
				std::random_device rd;     
				std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
				std::uniform_int_distribution<int> uni(0,11); 
				while(childIt!=children.end()){
					int random_integer = uni(rng);
					if(random_integer<=3){
						addToArchive(*childIt);
					}
					childIt++;
				}
			}

		} else { // robogen standard logic
			selector->initPopulation(population);
			unsigned int numOffspring = 0;
			while (numOffspring < conf->lambda) {

				std::pair<boost::shared_ptr<RobotRepresentation>,
						boost::shared_ptr<RobotRepresentation> > selection;
				if (!selector->select(selection.first)) {
					std::cerr << "Selector::select() failed." << std::endl;
					exitRobogen(EXIT_FAILURE);
				}
				unsigned int tries = 0;
				do {
					if (tries > 10000) {
						std::cerr << "Selecting second parent failed after "
								"10000 tries, giving up.";
						exitRobogen(EXIT_FAILURE);
					}
					if (!selector->select(selection.second)) {
						std::cerr << "Selector::select() failed." << std::endl;
						exitRobogen(EXIT_FAILURE);
					}
					tries++;
				} while (selection.first == selection.second);

				std::vector<boost::shared_ptr<RobotRepresentation> > offspring
					= mutator->createOffspring(selection.first,
											   selection.second);

				// no crossover, or can fit both new individuals
				if ( (numOffspring + offspring.size()) <= conf->lambda ) {
					children.insert(children.end(), offspring.begin(),
													offspring.end() );
					numOffspring += offspring.size();
				} else { // crossover, but can only fit one
					children.push_back(offspring[0]);
					numOffspring++;
				}
			}
			children.evaluate(robotConf, sockets);
		}
#ifndef EMSCRIPTEN
		triggerPostEvaluate();
#endif
	} else {
#ifdef EMSCRIPTEN
		sendJSEvent("evolutionTerminated", "{}");
#endif

	}
}

#ifdef EMSCRIPTEN
void EMSCRIPTEN_KEEPALIVE evaluationResultAvailable(int ptr, double fitness) {
	RobotRepresentation* robot = (RobotRepresentation*) ptr;
	robot->asyncEvaluateResult(fitness);
}

void EMSCRIPTEN_KEEPALIVE evaluationIsDone() {
	triggerPostEvaluate();
}
#endif

}

using namespace robogen;

#ifndef EMSCRIPTEN
int main(int argc, char *argv[]) {
parseArgsThenInit(argc, argv);
triggerPostEvaluate();
// Clean up sockets
for (unsigned int i = 0; i < conf->sockets.size(); i++) {
	delete sockets[i];
}
exitRobogen(EXIT_SUCCESS);
}
#else
std::string EMSCRIPTEN_KEEPALIVE runEvolution(unsigned int seed, std::string outputDirectory, std::string confFileName,
	bool overwrite, bool saveAll) {
try {
	init(seed, outputDirectory, confFileName, overwrite, saveAll);
} catch (std::exception &e) {
	std::cerr << "Evolution failed" << std::endl;
	return "{\"error\" : \"Error\"}";
}
return "{}";
}
#endif

