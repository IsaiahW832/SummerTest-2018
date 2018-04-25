/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <Commands/TurnDegrees.h>
#include "Commands/DriveDistance.h"
#include "Commands/spitOutCube.h"

OI::OI() {
	_driveStick = new Joystick(DRIVE_JOYSTICK_PORT);
	_gameController = new Joystick(GAME_CONTROLLER_PORT);
#ifdef TEST
	// Connect the buttons to commands
	_buttonGrabOut = new JoystickButton(_driveStick, RUN_GRABBER_BUTTON);
	_buttonDrive = new JoystickButton(_driveStick, DRIVE_DISTANCE_BUTTON_NUMBER);
	_buttonTurn = new JoystickButton(_driveStick, TURN_DEGREES_BUTTON);
	_buttonDrive->WhenPressed(new DriveDistance(20));
	_buttonTurn->WhenPressed(new TurnDegrees(45));
	_buttonGrabOut->WhenPressed(new spitOutCube);
#endif
}

Joystick* OI::GetDriveStick(){
	return _driveStick;
}
Joystick* OI::GetGameController(){
	return _gameController;
}
