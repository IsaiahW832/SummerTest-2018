#include "LR_SideScaleTwice.h"

LR_SideScaleTwice::LR_SideScaleTwice(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = 1;
	}
	else if (scoreSide == "R") {
		turnDirection = -1;
	}

//	AddParallel(new DriveDistance(LR_SCALE_FIRST_DISTANCE));
//	AddSequential(new AutoLift2(LIFTING_TO_SCALE_UPPER_1, LIFT_UP_DIRECTION));
	AddParallel(new AutoLift2(LIFTING_TO_SCALE_UPPER_1, LIFT_UP_DIRECTION));
	AddSequential(new DriveDistance(LR_SCALE_FIRST_DISTANCE));

	AddSequential(new TurnDegrees(turnDirection * TURN_70_DEGREES * 0.86));
	AddSequential(new spitOutCube());

	AddSequential(new AutoLift2(LIFTING_TO_SCALE_LOWER_2, LIFT_DOWN_DIRECTION));
	AddParallel(new AutoLift1(LIFTING_TO_SCALE_UPPER_1, LIFT_DOWN_DIRECTION));
	AddSequential(new TurnDegrees(turnDirection * TURN_110_DEGREES * 0.86));
	AddSequential(new DriveDistance(LR_SCALE_TWICE_AWAY_FROM_SCALE));
	AddSequential(new TurnDegrees(-1 * turnDirection * TURN_39_POINT_44_DEGREES * 0.86));
	AddParallel(new SuckInCube(5));
	AddSequential(new DriveDistance(LR_SCALE_TWICE_DRIVE_TO_CUBE));
}
