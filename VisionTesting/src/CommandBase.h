#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Lift.h"
#include "Subsystems/Grabber.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveTrain *driveTrain;
	static Lift *lift;
	static Grabber *grabber;
	static OI *oi;
};

#endif // COMMAND_BASE_H
