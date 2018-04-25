/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LR_SideSwitchPush.h"

LR_SideSwitchPush::LR_SideSwitchPush(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = 1;
	}
	else if (scoreSide == "R") {
		turnDirection = -1;
	}

	//Score in Switch
	AddSequential(new DriveDistance(LR_FIRST_DISTANCE_SWITCH_OFF_FENCE));//in inches
	AddSequential(new TurnDegrees(turnDirection * TURN_90_DEGREES));//in degrees
	AddSequential(new DriveDistance(LR_SECOND_DISTANCE_SWITCH_OFF_FENCE));//in inches
	AddSequential(new spitOutCube());

	AddSequential(new DriveDistance(-LR_SECOND_DISTANCE_SWITCH_OFF_FENCE));
	AddSequential(new TurnDegrees(-1 * turnDirection * TURN_90_DEGREES));//in degrees
	AddSequential(new DriveDistance(LR_SIDE_SWITCH_PUSH_DISTANCE_2));
}
