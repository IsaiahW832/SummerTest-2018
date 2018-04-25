#include "R_LeftSwitch.h"

R_LeftSwitch::R_LeftSwitch() {
	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(R_TURN_LEFT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_SECOND_DISTANCE));
	AddSequential(new TurnDegrees(R_TURN_RIGHT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_THIRD_DISTANCE));
	AddSequential(new spitOutCube());
}
