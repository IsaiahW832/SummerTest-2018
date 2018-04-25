/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "TurnDegrees.h"

TurnDegrees::TurnDegrees(float turnDegrees) {
	Requires(driveTrain);
	_turnDegrees = (turnDegrees);
	//Will stop the robot even if the gyro isn't working
	//SetTimeout(fabs(_turnDegrees/79));
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize() {
	driveTrain->ResetGyro();
	frc::SmartDashboard::PutString("Command Message", "Turn Degrees Start");
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
	//If power is changed then you must recalute the time.
	if (driveTrain->signbit(_turnDegrees)){
		driveTrain->ArcadeDrive(-TURN_DEGREES_SPEED, 0, -TURN_DEGREES_SPEED, 0, true);
	}
	else {
		driveTrain->ArcadeDrive(TURN_DEGREES_SPEED, 0, TURN_DEGREES_SPEED, 0, true);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished() {
	return (fabs(driveTrain->GetGyroAngle()) >= fabs(_turnDegrees)); //|| IsTimedOut());
}

// Called once after isFinished returns true
void TurnDegrees::End() {
	driveTrain->ArcadeDrive(0, 0, 0, 0, true);
	frc::SmartDashboard::PutString("Command Message", "Turn Degrees Stop");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDegrees::Interrupted() {
	End();
}
