#ifndef R_LeftScale_H
#define R_LeftScale_H

#include <Commands/DriveDistance.h>
#include <Commands/TurnDegrees.h>
#include <Commands/spitOutCube.h>
#include <Commands/AutoLift1.h>
#include <Commands/LiftTime.h>

class R_LeftScale : public CommandGroup {
public:
	R_LeftScale();
};

#endif  // R_LeftScale_H
