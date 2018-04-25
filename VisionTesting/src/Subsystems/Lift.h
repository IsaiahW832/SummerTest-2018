#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "..\RobotMap.h"

class Lift : public frc::Subsystem {
private:
	Spark* _acmeScrew1;
	Spark* _acmeScrew2;

	frc::Encoder* _screw1Encoder;
	frc::Encoder* _screw2Encoder;

public:
	Lift();
	void InitDefaultCommand();
	void Lift1Operate(int direction);
	void Lift2Operate(double direction);

	void ResetEncoder2();
	void ResetEncoder1();

	double GetEncoder2();
	double GetEncoder1();
};

#endif  // Lift_H
