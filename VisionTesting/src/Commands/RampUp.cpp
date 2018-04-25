#include "RampUp.h"

RampUp::RampUp() {
	Requires(driveTrain);
	SetTimeout(10);
	// eg. Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void RampUp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RampUp::Execute() {
	driveTrain->DriveRampUp(.6);
}

// Make this return true when this Command no longer needs to run execute()
bool RampUp::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void RampUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RampUp::Interrupted() {

}
