#ifndef AutoLift2_H
#define AutoLift2_H

#include "../CommandBase.h"

class AutoLift2 : public CommandBase {
private:
	float _heightToRaiseLift2;
	int _direction;
public:
	AutoLift2(float heightToRaiseLift2, int screwDirection2);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif // AutoLift2_H

