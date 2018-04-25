#ifndef LiftWithJoystick_H
#define LiftWithJoystick_H

#include "../CommandBase.h"

class LiftWithJoystick : public CommandBase {
public:
	LiftWithJoystick();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // LiftWithJoystick_H
