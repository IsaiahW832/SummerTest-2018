#include "R_LeftScale.h"

R_LeftScale::R_LeftScale() {
	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FIRST_DISTANCE));
		AddSequential(new TurnDegrees(R_TURN_LEFT_DEGREES));

		AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_SECOND_DISTANCE));
		AddSequential(new TurnDegrees(R_TURN_RIGHT_DEGREES));

		AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_THIRD_DISTANCE));
		AddSequential(new TurnDegrees(R_TURN_RIGHT_DEGREES));

		AddParallel(new AutoLift1(LIFTING_TO_SCALE_LOWER_2, LIFT_UP_DIRECTION));
		AddParallel(new LiftTime());
		AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FOURTH_DISTANCE));
		AddSequential(new spitOutCube());
}
