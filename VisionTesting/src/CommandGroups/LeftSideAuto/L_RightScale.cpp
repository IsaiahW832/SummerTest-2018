#include "L_RightScale.h"

L_RightScale::L_RightScale() {
	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_SECOND_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_LEFT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_THIRD_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_LEFT_DEGREES));

	AddParallel(new AutoLift1(LIFTING_TO_SCALE_LOWER_2, LIFT_UP_DIRECTION));
	AddSequential(new DriveDistance(LR_OPPOSITE_SCALE_FOURTH_DISTANCE));
	AddSequential(new spitOutCube());
}
