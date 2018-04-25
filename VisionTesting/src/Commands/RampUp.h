#pragma once

#include <Commands/Command.h>
#include "../CommandBase.h"


class RampUp : public CommandBase {
public:
	RampUp();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

