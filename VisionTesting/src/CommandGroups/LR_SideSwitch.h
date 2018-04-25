#ifndef LR_SideSwitch_H
#define LR_SideSwitch_H

//include Needed Commands
#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"
#include "Commands/spitOutCube.h"

class LR_SideSwitch : public CommandGroup {
private:
	int turnDirection;
public:
	LR_SideSwitch(std::string scoreSide);
};

#endif  // LR_SideSwitch_H
