#ifndef LR_SideScale_H
#define LR_SideScale_H

//Include needed commands
#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"
#include "Commands/AutoLift1.h"
#include "Commands/AutoLift2.h"
#include "Commands/spitOutCube.h"

class LR_SideScale : public CommandGroup {
private:
	int turnDirection;
public:
	LR_SideScale(std::string scoreSide);
};

#endif  // LR_SideScale_H
