#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "../CommandBase.h"

class TurnDegrees : public CommandBase {
private:
	float _turnDegrees;
public:
	TurnDegrees(float turnDegrees);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // Turn90Degrees_H


