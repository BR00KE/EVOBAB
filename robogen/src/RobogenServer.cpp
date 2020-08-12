/*
 * @(#) RobogenServer.cpp   1.0   Mar 5, 2013
 *
 * Andrea Maesani (andrea.maesani@epfl.ch)
 * Joshua Auerbach (joshua.auerbach@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2012-2014 Andrea Maesani, Joshua Auerbach
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
#include <iostream>

#include "config/ConfigurationReader.h"
#include "config/RobogenConfig.h"
#include "scenario/Scenario.h"
#include "scenario/ScenarioFactory.h"
#include "utils/network/ProtobufPacket.h"
#include "utils/network/TcpSocket.h"
#include "utils/RobogenCollision.h"
#include "utils/RobogenUtils.h"
#include "Models.h"
#include "RenderModels.h"
#include "Robogen.h"
#include "Robot.h"
#include "robogen.pb.h"

#include "viewer/Viewer.h"
#include "Simulator.h"

#ifdef QT5_ENABLED
#include <QCoreApplication>
#endif

using namespace robogen;

// ODE World
dWorldID odeWorld;

// Container for collisions
dJointGroupID odeContactGroup;

bool interrupted;

int main(int argc, char* argv[]) {

	startRobogen();

	interrupted = false;

	if (argc < 2) {
		std::cerr << "Please, provide server port." << std::endl;
		exitRobogen(EXIT_FAILURE);
	} 

	// Parameters: <PORT>
	int port = std::atoi(argv[1]);
	if (!port) {
		std::cerr << "The first argument must be a server port." << std::endl;
		exitRobogen(EXIT_FAILURE);
	}

	bool visualize = false;	
	bool startPaused = false;
	for (int currentArg=2; currentArg<argc; currentArg++) {
		if (std::string(argv[currentArg]).compare("--visualization") == 0) {
			visualize = true;
		} else if (std::string(argv[currentArg]).compare("--pause") == 0) {
			startPaused = true;
		}
	}

	if (startPaused && !visualize) {
		std::cerr << "Cannot start paused without visualization enabled." <<
				std::endl;
		exitRobogen(EXIT_FAILURE);
	}


	TcpSocket socket;
	bool rc = socket.create(port);
	if (!rc) {
		std::cerr << "Cannot listen for incoming connections on port " << port
				<< std::endl;
		exitRobogen(EXIT_FAILURE);
	}


	boost::random::mt19937 rng;
	rng.seed(port);

#ifdef QT5_ENABLED
	QCoreApplication a(argc, argv);
#endif


	while (!interrupted) {

		// Wait for client to connect
		std::cout << "Waiting for clients..." << std::endl;

		rc = socket.accept();

		if (rc) {

			std::cout << "Client connected..." << std::endl;

			while (true) {

				try {

					// ---------------------------------------
					// Decode solution
					// ---------------------------------------

					ProtobufPacket<robogenMessage::EvaluationRequest> packet;

					// 1) Read packet header
					std::vector<unsigned char> headerBuffer;
					socket.read(headerBuffer,
							ProtobufPacket<robogenMessage::EvaluationRequest>::HEADER_SIZE);
					unsigned int packetSize = packet.decodeHeader(headerBuffer);

					// 2) Read packet size
					std::vector<unsigned char> payloadBuffer;
					socket.read(payloadBuffer, packetSize);
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
					}

					// ---------------------------------------
					// Setup environment
					// ---------------------------------------

					boost::shared_ptr<Scenario> scenario =
							ScenarioFactory::createScenario(configuration);
					if (scenario == NULL) {
						exitRobogen(EXIT_FAILURE);
					}

					std::cout
							<< "-----------------------------------------------"
							<< std::endl;

					// ---------------------------------------
					// Run simulations
					// ---------------------------------------
					Viewer *viewer = NULL;
					if(visualize) {
						viewer = new Viewer(startPaused);
					}

					unsigned int simulationResult = runSimulations(scenario,
							configuration, packet.getMessage()->robot(),
							viewer, rng);

					if(viewer != NULL) {
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
					std::cout << "Fitness for the current solution: " << fitness
							<< std::endl << std::endl;

					// ---------------------------------------
					// Send reply to EA
					// ---------------------------------------
					boost::shared_ptr<robogenMessage::EvaluationResult> evalResultPacket(
							new robogenMessage::EvaluationResult());
					evalResultPacket->set_fitness(fitness);
					evalResultPacket->set_id(packet.getMessage()->robot().id());
					ProtobufPacket<robogenMessage::EvaluationResult> evalResult;
					evalResult.setMessage(evalResultPacket);

					std::vector<unsigned char> sendBuffer;
					evalResult.forge(sendBuffer);

					socket.write(sendBuffer);

				} catch (boost::system::system_error& e) {
					socket.close();
					exitRobogen(EXIT_FAILURE);
				}

			}

		} else {
			std::cerr << "Cannot connect to client. Exiting." << std::endl;
			socket.close();
			exitRobogen(EXIT_FAILURE);
		}

	}

	exitRobogen(EXIT_SUCCESS);
}
