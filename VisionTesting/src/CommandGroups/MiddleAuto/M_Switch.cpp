#include "M_Switch.h"

M_Switch::M_Switch(std::string scoreSide) {
	//Tells whether to turn Left or Right
	if (scoreSide == "L") {
		turnDirection = -45;
		amountOfDistanceOne = 1;
	}
	else if (scoreSide == "R") {
		turnDirection = 32;
		amountOfDistanceOne = 1;
	}
	AddSequential(new DriveDistance(M_DRIVE_OFF_WALL));
	AddSequential(new TurnDegrees(0.9 * turnDirection)); //Turn toward our switch side
	AddSequential(new DriveDistance(amountOfDistanceOne * M_SWITCH_DISTANCE_1)); // Drive to Switch
	AddSequential(new TurnDegrees(0.9 * -1 * turnDirection)); //Align back to straight
	AddSequential(new DriveDistance(M_SWITCH_DISTANCE_2)); // Drive to Switch Wall
	AddSequential(new spitOutCube());
}
