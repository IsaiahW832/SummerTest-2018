#include "M_LeftAutoLine.h"

M_LeftAutoLine::M_LeftAutoLine() {
	AddSequential(new DriveDistance(M_FIRST_AUTO_LINE_DISTANCE));
	AddSequential(new TurnDegrees(M_AUTO_LINE_ANGLE_L));
	AddSequential(new DriveDistance(M_SECOND_AUTO_LINE_DISTANCE));
}
