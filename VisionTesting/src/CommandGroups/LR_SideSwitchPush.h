#pragma once

//include Needed Commands
#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"
#include "Commands/spitOutCube.h"

#include <Commands/CommandGroup.h>

class LR_SideSwitchPush : public CommandGroup {
private:
	int turnDirection;
public:
	LR_SideSwitchPush(std::string scoreSide);
};

