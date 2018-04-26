#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include "../CommandBase.h"
#include "Vision.h"

class DriveWithJoystick: public CommandBase {
private:
	bool firstIteration;
public:
	DriveWithJoystick();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // DriveWithJoystick_H/
