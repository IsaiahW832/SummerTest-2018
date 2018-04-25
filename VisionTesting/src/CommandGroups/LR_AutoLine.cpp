#include "LR_AutoLine.h"

LR_AutoLine::LR_AutoLine() {
	AddSequential(new DriveDistance(LR_AUTOLINE_DISTANCE));

}
