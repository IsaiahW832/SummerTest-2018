#pragma once

#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"

class LR_AutoLinePush : public CommandGroup {
private:
	int turnDirection;
public:
	LR_AutoLinePush(std::string scoreSide);
};

