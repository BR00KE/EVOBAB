/*
 * @(#) ParametricBrickModel.h   1.0   Feb 14, 2013
 *
 * Andrea Maesani (andrea.maesani@epfl.ch)
 * Joshua Auerbach (joshua.auerbach@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2012-2015 Andrea Maesani, Joshua Auerbach
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
#ifndef ROBOGEN_PARAMETRIC_BRICK_MODEL_H_
#define ROBOGEN_PARAMETRIC_BRICK_MODEL_H_

#include "model/Model.h"

namespace robogen {

/**
 * A parametric brick is modelled with 4 boxes and a cylinder
 */
class ParametricBrickModel: public Model {

public:

	static const float MASS_SLOT;
	static const float MASS_CONNECTION_PER_M;
	static const float SLOT_WIDTH;
	static const float SLOT_THICKNESS;
	static const float CYLINDER_RADIUS;
	static const float CONNECTION_PART_THICKNESS;
	static const float CONNECTION_PART_WIDTH;
	static const float FIXED_BAR_LENGTH;

	static const unsigned int SLOT_A = 0;
	static const unsigned int SLOT_B = 1;

	static const unsigned int B_SLOT_A_ID = 0;
	static const unsigned int B_SLOT_B_ID = 1;
	static const unsigned int B_CONNECTION_PART_ID = 2; // variable bar
	static const unsigned int B_FIXED_BAR__ID = 3;
	static const unsigned int B_CYLINDER_ID = 4;

	/**
	 * Initialize a parametric brick model
	 *
	 * @param odeWorld
	 * @param odeSpace
	 * @param connectionPartLength in m
	 * @param angleA in radians
	 * @param angleB in radians
	 */
	ParametricBrickModel(dWorldID odeWorld, dSpaceID odeSpace, std::string id,
			float connectionPartLength, float angleA, float angleB);

	virtual ~ParametricBrickModel();

	virtual bool initModel();

	virtual boost::shared_ptr<SimpleBody> getRoot();

	virtual boost::shared_ptr<SimpleBody> getSlot(unsigned int i);

	virtual osg::Vec3 getSlotPosition(unsigned int i);

	virtual osg::Vec3 getSlotOrientation(unsigned int i);

	virtual osg::Vec3 getSlotAxis(unsigned int i);

	inline float getConnectionLength() {
		return connectionPartLength_;
	}

	inline float getAngleA() {
		return angleA_;
	}

	inline float getAngleB() {
		return angleB_;
	}

private:

	float connectionPartLength_;
	float angleA_;
	float angleB_;

	boost::shared_ptr<SimpleBody> brickRoot_, brickTail_;

};

}

#endif /* ROBOGEN_PARAMETRIC_BRICK_MODEL_H_ */
