#include "DriveTrain.h"
#include "..\CommandBase.h"
#include "../Commands/DriveWithJoystick.h"
#include <algorithm>
DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
	// Drive Train Motor Controllers
#ifdef SECONDARY_ROBOT
	_victorL1 = new frc::VictorSP(VICTOR_SP_DRIVE_LEFT1);
	_victorL2 = new frc::VictorSP(VICTOR_SP_DRIVE_LEFT2);
	_victorR1 = new frc::VictorSP(VICTOR_SP_DRIVE_RIGHT1);
	_victorR2 = new frc::VictorSP(VICTOR_SP_DRIVE_RIGHT2);
#endif
#ifndef SECONDARY_ROBOT
	_victorL1 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_LEFT1);
	_victorL2 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_LEFT2);
	_victorR1 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_RIGHT1);
	_victorR2 = new WPI_VictorSPX(VICTOR_SPX_DRIVE_RIGHT2);
#endif
#ifdef SECONDJOYSTICK
	_secondJoystick = true;
#endif
#ifndef SECONDJOYSTICK
	_secondJoystick = false;
#endif
	// Speed Controller Groups
	_leftSide = new SpeedControllerGroup(*_victorL1, *_victorL2);
	_rightSide = new SpeedControllerGroup(*_victorR1, *_victorR2);

	// Differential Drive Class
	_driveTrain = new DifferentialDrive(*_leftSide, *_rightSide);

	// Sensors
	_leftEncoder = new Encoder{LEFT_ENCODER_A_CHANNEL, LEFT_ENCODER_B_CHANNEL};
	_leftEncoder->SetDistancePerPulse(0.05235987755);
	_rightEncoder = new Encoder{RIGHT_ENCODER_A_CHANNEL, RIGHT_ENCODER_B_CHANNEL};
	_rightEncoder->SetDistancePerPulse(0.05235987755);
	_rangeFinder = new AnalogInput(0.0138996939);
	_gyro = new ADXRS450_Gyro();
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

bool DriveTrain::signbit(double xSignbit){
	if (xSignbit <= 0){
		return true;
	}
	else{
		return false;
	}
}

void DriveTrain::ResetGyro(){
	_gyro->Reset();
}

double DriveTrain::GetGyroAngle(){
	frc::SmartDashboard::PutNumber("Gyro angle", _gyro->GetAngle());
	return _gyro->GetAngle();
}

void DriveTrain::ResetEncoders(){
	_leftEncoder->Reset();
	_rightEncoder->Reset();
}

double DriveTrain::GetEncoderValue() {
	double encoderValue;

	//Average value from both encoders
	//encoderValue = (GetREncoderValue() + GetLEncoderValue()) / 2.0;

	// Until both encoders work, just return the value from the working one
	encoderValue = GetLEncoderValue();
	frc::SmartDashboard::PutNumber("Average Encoder Value", encoderValue);
	return encoderValue;
}

double DriveTrain::GetREncoderValue() {
	frc::SmartDashboard::PutNumber("Right Encoder Value", _rightEncoder->Get());
	return _rightEncoder->GetDistance();
}

double DriveTrain::GetLEncoderValue() {
	frc::SmartDashboard::PutNumber("Left Encoder Value", _leftEncoder->GetDistance());
	return _leftEncoder->GetDistance();
}

void DriveTrain::ArcadeDrive(float xDir, float yDir, float zRotation, float governor, bool squaredInputs){
	//Speed To Use in The arcade drive

	double SpeedOfX = 0;
	double SpeedOfY = 0;
	double SpeedOfZ = 0;

	//Dead zone
	xDir = fabs(xDir) > 0.10 ? xDir : 0.0;
	yDir = fabs(yDir) > 0.10 ? yDir : 0.0;
	zRotation = fabs(zRotation) > 0.15 ? zRotation : 0.0;

	//Use governor to limit speed, governor paddle on joystick - down is 0%, up is 100%
	xDir *= (1 - governor);
	yDir *= (1 - governor);
	zRotation *= (1 - governor);
	//Limiting the turning speed to 50%
	if (zRotation > MAXTURNINGSPEED){
		zRotation = MAXTURNINGSPEED;
	}
	else if (zRotation < -MAXTURNINGSPEED){
		zRotation = -MAXTURNINGSPEED;
	}

	if (xDir > MAXTURNINGSPEED){
		xDir = MAXTURNINGSPEED;
	}
	else if (xDir < -MAXTURNINGSPEED){
		xDir = -MAXTURNINGSPEED;
	}

	//Acceleration section of the code

	//Acceleration of z
	//Checking if the Sign of last Speed of z is a different sign of request speed or zRotation
	if (DriveTrain::signbit(zRotation) != DriveTrain::signbit(lastSpeedOfZ)){
		lastSpeedOfZ = 0;
	}
	//Do the Acceleration of turning
	if (zRotation == 0){
		SpeedOfZ = 0;
	}
	else if (fabs(zRotation) <= fabs(lastSpeedOfZ)){
		SpeedOfZ = zRotation;
	}
	else if (fabs(zRotation) > fabs(lastSpeedOfZ)){
		SpeedOfZ = lastSpeedOfZ + (zRotation * PERCENT_ACCEL);
	}

	//Acceleration of Y
	//Checking if the Sign of last Speed of Y is a different sign of request speed or ydir
	if (DriveTrain::signbit(yDir) != DriveTrain::signbit(lastSpeedOfY)){
		lastSpeedOfY = 0;
	}
	//Do the Acceleration of turning
	if (yDir == 0){
		SpeedOfY = 0;
	}
	else if (fabs(yDir) <= fabs(lastSpeedOfY)){
		SpeedOfY = yDir;
	}
	else if (fabs(yDir) > fabs(lastSpeedOfY)){
		SpeedOfY =  lastSpeedOfY + (yDir * PERCENT_ACCEL);
		if (!signbit(SpeedOfY) && SpeedOfY < 0.3){
			SpeedOfY = 0.3;
		}

		else if (signbit(SpeedOfY) && SpeedOfY > -0.3){
			SpeedOfY = -0.3;
		}
	}

	//Acceleration of X
	//We aren't Use this right now. Z is the turning
	//kyle says drive good
	//kyle says straight drive
	//kyle says lift the milkcrates
	//kyle says turn right
	//kyle says turn left
	//kyle says eat eric
	//kyle says keep warm

	//Checking if the Sign of last Speed of X is a different sign of request speed or xdir
	if (DriveTrain::signbit(xDir) != DriveTrain::signbit(lastSpeedOfX)){
		lastSpeedOfX = 0;
	}
	//Do the Acceleration of turning
	if (xDir == 0){
		SpeedOfX = 0;
	}
	else if (fabs(xDir) <= fabs(lastSpeedOfX)){
		SpeedOfX = xDir;
	}
	else if (fabs(xDir) > fabs(lastSpeedOfX)){
		SpeedOfX = lastSpeedOfX + (xDir * PERCENT_ACCEL);
	}


	frc::SmartDashboard::PutNumber("Speed Y", SpeedOfY);
	frc::SmartDashboard::PutNumber("Speed Z", SpeedOfZ);
	frc::SmartDashboard::PutNumber("Speed X", SpeedOfX);
	frc::SmartDashboard::PutNumber("yDir", yDir);
	frc::SmartDashboard::PutNumber("zRotation", zRotation);

	// Drive Robot - only uncomment one of the following
	if (_secondJoystick){
		// Speed without acceleration limiting
#ifdef TEST_ACCER
		_driveTrain->ArcadeDrive(-SpeedOfY, xDir, squaredInputs);
#endif
#ifndef TEST_ACCER
		_driveTrain->ArcadeDrive(-yDir, xDir, squaredInputs);
#endif
		// Speed with acceleration limiting
		//_driveTrain->ArcadeDrive(-SpeedOfY, SpeedOfZ, squaredInputs);
	}
	else{
		// Speed without acceleration limiting
#ifdef TEST_ACCER
		_driveTrain->ArcadeDrive(-SpeedOfY, zRotation, squaredInputs);
#endif
#ifndef TEST_ACCER
		_driveTrain->ArcadeDrive(-yDir, zRotation, squaredInputs);
#endif
		// Speed with acceleration limiting
		//_driveTrain->ArcadeDrive(-SpeedOfY, SpeedOfZ, squaredInputs);
	}
	//Setting the lastSpeed
	lastSpeedOfZ = SpeedOfZ;
	lastSpeedOfY = SpeedOfY;
	lastSpeedOfX = SpeedOfX;

	//This is displaying the encoder value on smartdashboard

	//Joe - do NOT delete again.
	DriveTrain::GetEncoderValue();
}

void DriveTrain::SimpleArcadeDrive(float xSpeed, float zRotation){
	float slowSpeed = xSpeed/1.3;
	_driveTrain->ArcadeDrive(-slowSpeed, zRotation, true);
}

void DriveTrain::TankDrive(double lPower, double rPower) {
	_leftSide->Set(lPower);
	_rightSide->Set(-rPower);
}
//This is for testing Do not call besides to test/
void DriveTrain::DriveRampUp(float yDir){
	double SpeedOfY = 0;

	yDir = fabs(yDir) > 0.10 ? yDir : 0.0;

	//Acceleration of Y
	//Checking if the Sign of last Speed of Y is a different sign of request speed or ydir
	if (DriveTrain::signbit(yDir) != DriveTrain::signbit(lastSpeedOfY)){
		lastSpeedOfY = 0;
	}
	//Do the Acceleration of turning
	if (yDir == 0){
		SpeedOfY = 0;
	}
	else if (fabs(yDir) <= fabs(lastSpeedOfY)){
		SpeedOfY = yDir;
	}
	else if (fabs(yDir) > fabs(lastSpeedOfY)){
		SpeedOfY =  lastSpeedOfY + (yDir * PERCENT_ACCEL);
		if (!signbit(SpeedOfY) && SpeedOfY < 0.3){
			SpeedOfY = 0.3;
		}

		else if (signbit(SpeedOfY) && SpeedOfY > -0.3){
			SpeedOfY = -0.3;
		}
	}
	if (SpeedOfY < .6){
		_driveTrain->ArcadeDrive(-SpeedOfY, 0, true);
	}
	else{
		_driveTrain->ArcadeDrive(0, 0, true);
	}
	frc::SmartDashboard::PutNumber("Speed Y", SpeedOfY);

	lastSpeedOfY = SpeedOfY;
}

void DriveTrain::CalibrateGyro() {
	_gyro->Calibrate();
}
