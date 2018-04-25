#ifndef M_SwitchTwice_H
#define M_SwitchTwice_H

//include Needed Commands
#include "Commands/DriveDistance.h"
#include "Commands/TurnDegrees.h"
#include "Commands/spitOutCube.h"
#include "Commands/SuckInCube.h"
#include "Commands/AutoLift1.h"

class M_SwitchTwice : public CommandGroup {
private:
	int turnAngleInitial;
	int amountOfDistanceOne;
	int turnDirection;
public:
	M_SwitchTwice(std::string scoreSide);
};

#endif  // M_Switch_H

