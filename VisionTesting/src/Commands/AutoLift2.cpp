#include "AutoLift2.h"

AutoLift2::AutoLift2(float heightToRaiseLift2, int screwDirection2) {
	Requires(lift);
	_heightToRaiseLift2 = heightToRaiseLift2;
	SetTimeout(4.5);
	_direction = screwDirection2;
}

// Called just before this Command runs the first time
void AutoLift2::Initialize() {
	lift->ResetEncoder2();
}

// Called repeatedly when this Command is scheduled to run
void AutoLift2::Execute() {
	lift->Lift2Operate(_direction);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLift2::IsFinished() {
	return lift->GetEncoder2() >= _heightToRaiseLift2 || IsTimedOut();
}

// Called once after isFinished returns true
void AutoLift2::End() {
	lift->Lift2Operate(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLift2::Interrupted() {
	End();
}
