#include "CommandBase.h"

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}
DriveTrain* CommandBase::driveTrain = NULL;
Lift* CommandBase::lift = NULL;
Grabber* CommandBase::grabber = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init(){
	driveTrain = new DriveTrain();
	lift = new Lift();
	grabber = new Grabber();
	oi = new OI();
}
