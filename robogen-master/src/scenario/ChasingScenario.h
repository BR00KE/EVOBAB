/*
 * @(#) ChasingScenario.h   1.0   Mar 20, 2013
 *
 * Andrea Maesani (andrea.maesani@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2012-2013 Andrea Maesani
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
#ifndef ROBOGEN_CHASING_SCENARIO_H_
#define ROBOGEN_CHASING_SCENARIO_H_

#include <osg/Vec3>
#include "scenario/Scenario.h"

namespace robogen {

/**
 * Chasing Scenario.
 * The robot that can reach and stay close to the light source int the given simulation time wins.
 * The distance is computed as the euclidean distance from the light source to robot computed using as
 * reference the core component.
 */
class ChasingScenario: public Scenario {

public:

	/**
	 * Initializes a RacingScenario
	 */
	ChasingScenario(boost::shared_ptr<RobogenConfig> robogenConfig);

	/**
	 * Destructor
	 */
	virtual ~ChasingScenario();

	/**
	 * Methods inherited from {@link #Scenario}
	 */
	virtual bool setupSimulation();
	virtual bool afterSimulationStep();
	virtual bool endSimulation();
	virtual double getFitness();
	virtual bool remainingTrials();
	virtual bool init(dWorldID odeWorld, dSpaceID odeSpace, boost::shared_ptr<Robot> robot);
	virtual int getCurTrial() const;

private:

	std::vector<double> distances_;
	unsigned int curTrial_;

};

}

#endif /* ROBOGEN_CHASING_SCENARIO_H_ */
