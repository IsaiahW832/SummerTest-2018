#pragma once

//Include needed commands
#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"
#include "Commands/AutoLift1.h"
#include "Commands/AutoLift2.h"
#include "Commands/spitOutCube.h"
#include "Commands/SuckInCube.h"

class LR_SideScaleTwice : public CommandGroup {
private:
	int turnDirection;
public:
	LR_SideScaleTwice(std::string scoreSide);
};

