#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(driveTrain);
}

void DriveWithJoystick::Initialize() {
	driveTrain->ResetEncoders();
	driveTrain->ResetGyro();
//	driveTrain->CalibrateGyro();
}

void DriveWithJoystick::Execute()
{
#ifndef SECONDJOYSTICK
	driveTrain->ArcadeDrive(oi->GetDriveStick()->GetX(), oi->GetDriveStick()->GetY(), oi->GetDriveStick()->GetZ(), oi->GetDriveStick()->GetRawAxis(XY_DRIVE_GOVERNOR_NUMBER), true);
#endif
#ifdef SECONDJOYSTICK
	driveTrain->ArcadeDrive(oi->GetDriveStick()->GetRawAxis(0), oi->GetDriveStick()->GetRawAxis(1), 0, oi->GetDriveStick()->GetRawAxis(2), true);
#endif
	frc::SmartDashboard::PutBoolean("Kyle says drive good", true);
	if (oi->GetDriveStick()->GetRawButton(11) == 1){
		driveTrain->ResetGyro();
	}
	//Shows the Gyro value
	driveTrain->GetGyroAngle();
}

bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	driveTrain->ArcadeDrive(0, 0, 0, 0, true);
}

void DriveWithJoystick::Interrupted() {
	End();
}
