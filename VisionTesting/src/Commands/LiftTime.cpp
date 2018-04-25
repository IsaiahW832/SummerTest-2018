/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LiftTime.h"

LiftTime::LiftTime() {
	Requires(lift);
	SetTimeout(1);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LiftTime::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftTime::Execute() {
	lift->Lift2Operate(LIFT_DIRECTION_UP);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftTime::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void LiftTime::End() {
	lift->Lift2Operate(LIFT_DIRECTION_STOP);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftTime::Interrupted() {
	End();
}
