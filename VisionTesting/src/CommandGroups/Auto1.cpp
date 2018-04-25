#include "Auto1.h"

Auto1::Auto1() {
	AddSequential(new DriveDistance(10));
	AddSequential(new TurnDegrees(180));
	AddParallel(new spitOutCube());
	AddSequential(new DriveDistance(10));
}
