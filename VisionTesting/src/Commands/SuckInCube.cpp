#include "SuckInCube.h"

SuckInCube::SuckInCube(int secondsToGrab) {
	Requires(grabber);
	SetTimeout(secondsToGrab);
}

// Called just before this Command runs the first time
void SuckInCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SuckInCube::Execute() {
	grabber->RunGrabber(GRABBER_IN, .8);
}

// Make this return true when this Command no longer needs to run execute()
bool SuckInCube::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void SuckInCube::End() {
	grabber->RunGrabber(GRABBER_STOP, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SuckInCube::Interrupted() {
	End();
}
