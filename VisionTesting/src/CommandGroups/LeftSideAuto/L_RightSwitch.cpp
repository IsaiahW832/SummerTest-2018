#include "L_RightSwitch.h"

L_RightSwitch::L_RightSwitch() {
	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_FIRST_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_SECOND_DISTANCE));
	AddSequential(new TurnDegrees(L_TURN_RIGHT_DEGREES));

	AddSequential(new DriveDistance(LR_OPPOSITE_SWITCH_THIRD_DISTANCE));
	AddSequential(new spitOutCube());
}
