#include "spitOutCube.h"

spitOutCube::spitOutCube() {
	Requires(grabber);
	SetTimeout(SPIT_OUT_CUBE_TIME);
}

// Called just before this Command runs the first time
void spitOutCube::Initialize() {
	frc::SmartDashboard::PutString("Command Message", "Spit Out Cube Start");
}

// Called repeatedly when this Command is scheduled to run
void spitOutCube::Execute() {
	grabber->RunGrabber(GRABBER_OUT, .8);
}

// Make this return true when this Command no longer needs to run execute()
bool spitOutCube::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void spitOutCube::End() {
	grabber->RunGrabber(GRABBER_STOP, .0);
	frc::SmartDashboard::PutString("Command Message", "Spit Out Cube Stop");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void spitOutCube::Interrupted() {
	End();
}
