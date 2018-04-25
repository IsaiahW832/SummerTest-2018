#include "grabbingWithButtons.h"

grabbingWithButtons::grabbingWithButtons() {
	Requires(grabber);

	currentSpeed = 0;
	currentDirection = GRABBER_STOP;
	isRunning = false;
}

// Called just before this Command runs the first time
void grabbingWithButtons::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void grabbingWithButtons::Execute() {
#ifdef SECONDJOYSTICK_GAME_REPLACE
	if (oi->GetGameController()->GetRawButton(4) == 1){
		currentDirection = GRABBER_IN;
		currentSpeed = .8;
	}
	else if (oi->GetGameController()->GetRawButton(5) == 1){
		currentDirection = GRABBER_OUT;
		currentSpeed = .8;
	}
	else if(oi->GetGameController()->GetRawButton(3) == 1){
		currentDirection = GRABBER_STOP;
		currentSpeed = 0;
	}
	else if(oi->GetGameController()->GetRawButton(2) == 1){
		currentDirection = GRABBER_IN;
		currentSpeed = .3;
	}
	if (currentDirection == GRABBER_STOP){
		if (oi->GetGameController()->GetRawButton(6) == 1){
			grabber->RunLeftGrabber(GRABBER_OUT, .8);
		}
		else if (oi->GetGameController()->GetRawButton(7) == 1){
			grabber->RunLeftGrabber(GRABBER_IN, .8);
		}
		else{
			grabber->RunLeftGrabber(GRABBER_STOP, .0);
		}

		if (oi->GetGameController()->GetRawButton(11) == 1){
			grabber->RunRightGrabber(GRABBER_OUT, .8);
		}
		else if (oi->GetGameController()->GetRawButton(10) == 1){
			grabber->RunRightGrabber(GRABBER_IN, .8);
		}
		else{
			grabber->RunRightGrabber(GRABBER_STOP, .0);
		}
	}
	else{
		grabber->RunGrabber(currentDirection, currentSpeed);
	}
#endif
#ifndef SECONDJOYSTICK_GAME_REPLACE
	if (oi->GetGameController()->GetRawButton(GRABBER_IN_BUTTON) == 1){
		currentDirection = GRABBER_IN;
		currentSpeed = .8;
	}
	else if (oi->GetGameController()->GetRawButton(GRABBER_OUT_BUTTON) == 1){
		currentDirection = GRABBER_OUT;
		currentSpeed = .8;
	}
	else if (oi->GetGameController()->GetRawButton(GRABBER_SLOW_BUTTON) == 1){
		currentDirection = GRABBER_OUT;
		currentSpeed = .5;
	}
	else if(oi->GetGameController()->GetRawButton(GRABBER_STOP_BUTTON) == 1){
		currentDirection = GRABBER_STOP;
		currentSpeed = .8;
	}
	if (currentDirection == GRABBER_STOP){
		if (oi->GetGameController()->GetRawAxis(GRABBER_LEFT_SIDE_AXIS) >= .25){
			grabber->RunLeftGrabber(GRABBER_IN, .8);
			isRunning = true;
		}
		else if (oi->GetGameController()->GetRawAxis(GRABBER_LEFT_SIDE_AXIS) <= -.25){
			grabber->RunLeftGrabber(GRABBER_OUT, .8);
			isRunning = true;
		}
		else {
			grabber->RunLeftGrabber(GRABBER_STOP, 0);
			isRunning = false;
		}

		if (oi->GetGameController()->GetRawAxis(GRABBER_RIGHT_SIDE_AXIS) >= .25){
			grabber->RunRightGrabber(GRABBER_IN, .8);
			isRunning = true;
		}
		else if (oi->GetGameController()->GetRawAxis(GRABBER_RIGHT_SIDE_AXIS) <= -.25){
			grabber->RunRightGrabber(GRABBER_OUT, .8);
			isRunning = true;
		}
		else{
			grabber->RunRightGrabber(GRABBER_STOP, 0);
			isRunning = false;
		}

		//vision grabber
		if(!isRunning && Vision::GetSeeYellow() == true){
			grabber->RunGrabber(GRABBER_IN, .8);
		}
	}
	else {
		grabber->RunGrabber(currentDirection, currentSpeed);
	}
#endif
}

// Make this return true when this Command no longer needs to run execute()
bool grabbingWithButtons::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void grabbingWithButtons::End() {
	grabber->RunGrabber(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void grabbingWithButtons::Interrupted() {
	End();
}
