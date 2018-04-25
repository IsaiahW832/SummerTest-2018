#ifndef Grabber_H
#define Grabber_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre\Phoenix.h"
#include "..\RobotMap.h"


class Grabber : public Subsystem {
private:

	#ifdef SECONDARY_ROBOT
	frc::VictorSP* _leftGrabber;
	frc::VictorSP* _rightGrabber;
	#endif
	#ifndef SECONDARY_ROBOT
	WPI_VictorSPX* _leftGrabber;
	WPI_VictorSPX* _rightGrabber;
	#endif

public:
	Grabber();
	void InitDefaultCommand();

	void RunLeftGrabber(int direction, float speed);

	void RunRightGrabber(int direction, float speed);

	void RunGrabber(int direction, float speed);
};

#endif  // Grabber_H
