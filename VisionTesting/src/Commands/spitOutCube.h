#ifndef spitOutCube_H
#define spitOutCube_H

#include "../CommandBase.h"

class spitOutCube : public CommandBase {
public:
	spitOutCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // spitOutCube_H
