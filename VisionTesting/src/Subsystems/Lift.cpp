//Lift1 = Small(grabber stage)
//Lift2 = Big(lift stage)
#include "Lift.h"
#include "..\CommandBase.h"
#include "..\Commands\LiftWithJoystick.h"

Lift::Lift() : frc::Subsystem("Lift") {
	_acmeScrew1 = new Spark(SPARK_ACMESCREW_1);//Big
	_acmeScrew1->IsSafetyEnabled();
	_acmeScrew2 = new Spark(SPARK_ACMESCREW_2);//Small
	_acmeScrew2->IsSafetyEnabled();

	_screw1Encoder = new frc::Encoder(SCREW_1_CHANNEL_A, SCREW_1_CHANNEL_B);
	_screw1Encoder->SetDistancePerPulse(SCREW_1_ENCODER_VERTICAL_DPP);
	_screw2Encoder  = new frc::Encoder(SCREW_2_CHANNEL_A, SCREW_2_CHANNEL_B);
	_screw2Encoder->SetDistancePerPulse(SCREW_2_ENCODER_VERTICAL_DPP);
}

void Lift::InitDefaultCommand() {
	SetDefaultCommand(new LiftWithJoystick());
}

void Lift::Lift1Operate(int direction) {
	if(direction == LIFT_DIRECTION_UP) {
		_acmeScrew1->Set(-ACME_SCREW_SPEED_UP);//inverted motor
	}
	else if(direction == LIFT_DIRECTION_DOWN) {
		_acmeScrew1->Set(-ACME_SCREW_SPEED_DOWN);//inverted motor
	}
	else {
		_acmeScrew1->Set(0);
	}
}
void Lift::Lift2Operate(double direction) {
	if(direction == LIFT_DIRECTION_UP) {
		_acmeScrew2->Set(ACME_SCREW_SPEED_UP);
	}
	else if(direction == LIFT_DIRECTION_DOWN) {
		_acmeScrew2->Set(ACME_SCREW_SPEED_DOWN);
	}
	else if(direction == LIFT_DIRECTION_FAST){
		_acmeScrew2->Set(ACME_SCREW_SPEED_FAST);
		}
	else {
		_acmeScrew2->Set(0);
	}
}

void Lift::ResetEncoder2() {
	_screw2Encoder->Reset();
}

void Lift::ResetEncoder1() {
	_screw1Encoder->Reset();
}

double Lift::GetEncoder2() {
	return _screw2Encoder->GetDistance();
}

double Lift::GetEncoder1() {
	return _screw1Encoder->GetDistance();
}
