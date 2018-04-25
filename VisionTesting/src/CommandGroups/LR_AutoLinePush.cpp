#include "LR_AutoLinePush.h"

LR_AutoLinePush::LR_AutoLinePush(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = 1;
	}
	else if (scoreSide == "R") {
		turnDirection = -1;
	}

	AddSequential(new DriveDistance(LR_AUTOLINE_PUSH_DISTANCE_1));
	AddSequential(new TurnDegrees(turnDirection * TURN_90_DEGREES));
	AddSequential(new DriveDistance(LR_AUTOLINE_PUSH_DISTANCE_2));
}
