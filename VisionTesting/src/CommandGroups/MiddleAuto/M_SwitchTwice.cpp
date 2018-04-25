/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "M_SwitchTwice.h"

M_SwitchTwice::M_SwitchTwice(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnAngleInitial = -45;
		turnDirection = -1;
		amountOfDistanceOne = 1;
	}
	else if (scoreSide == "R") {
		turnAngleInitial = 32;
		turnDirection = 1;
		amountOfDistanceOne = 1;
	}
	//Score in Switch from Middle Starting Position
	AddSequential(new DriveDistance(M_DRIVE_OFF_WALL));
	AddSequential(new TurnDegrees(0.9 * turnAngleInitial)); //Turn toward our switch side
	AddSequential(new DriveDistance(amountOfDistanceOne * M_SWITCH_DISTANCE_1)); // Drive to Switch
	AddSequential(new TurnDegrees(0.9 * -1 * turnAngleInitial)); //Align back to straight
	AddSequential(new DriveDistance(M_SWITCH_DISTANCE_2)); // Drive to Switch Wall
	AddSequential(new spitOutCube());

	//Grab Second Cube
	AddParallel(new AutoLift1(40, LIFT_DOWN_DIRECTION)); //bring the lift down
	AddSequential(new DriveDistance(M_SWITCH_TWICE_1)); // Drive away from Switch Wall
	AddSequential(new TurnDegrees(-1 * turnDirection * M_SWITCH_TWICE_ANGLE)); //Align with Cube in front of Switch(corner cube)
	AddParallel(new SuckInCube(3));
	AddSequential(new DriveDistance(amountOfDistanceOne * M_SWITCH_TWICE_2)); //Drive to Grab Cube

	//Drive back to Switch to Score Again
	AddParallel(new AutoLift1(40, LIFT_UP_DIRECTION)); //bring the lift back up
	AddSequential(new DriveDistance(-1 * amountOfDistanceOne * M_SWITCH_TWICE_2)); //Drive backwards from cube pile
	AddSequential(new TurnDegrees(turnDirection * M_SWITCH_TWICE_ANGLE)); //Align with Switch Again
	AddSequential(new DriveDistance((-1 * M_SWITCH_TWICE_1) + 5)); // Drive Towards Switch Wall(add 5 inches to be sure to hit the wall)
	AddSequential(new spitOutCube());
}
