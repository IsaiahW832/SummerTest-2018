/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLift1.h"

AutoLift1::AutoLift1(float heightToRaiseLift1, int screwDirection1) {
	Requires(lift);
	_heightToRaiseLift1 = heightToRaiseLift1;
	_direction = screwDirection1;
	SetTimeout(4.5);
}

// Called just before this Command runs the first time
void AutoLift1::Initialize() {
	lift->ResetEncoder1();
}

// Called repeatedly when this Command is scheduled to run
void AutoLift1::Execute() {
	lift->Lift1Operate(_direction);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLift1::IsFinished() {
	return (lift->GetEncoder1() >= _heightToRaiseLift1 || IsTimedOut());
}

// Called once after isFinished returns true
void AutoLift1::End() {
	lift->Lift1Operate(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLift1::Interrupted() {
	End();
}
