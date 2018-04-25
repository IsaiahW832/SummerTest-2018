#ifndef ROBOTMAP_H
#define ROBOTMAP_H
//#define TEST
//#define SECONDARY_ROBOT
#define TEST_ACCER
//Only one or the other or both of the Second joystick has to be commented out
//#define SECONDJOYSTICK
//#define SECONDJOYSTICK_GAME_REPLACE

#include <WPILib.h>

// Speed of Auto Programs
constexpr float DRIVE_DISTANCE_SPEED = -.6;
constexpr float TURN_DEGREES_SPEED = .5; //If this is changed then you must go and change Timer.

//Lift motor controller ports
constexpr int SPARK_ACMESCREW_1 = 8;
constexpr int SPARK_ACMESCREW_2 = 9;
constexpr int SCREW_1_CHANNEL_A = 4;
constexpr int SCREW_1_CHANNEL_B = 5;
constexpr double SCREW_1_ENCODER_VERTICAL_DPP = 0.00048828125;
constexpr int SCREW_2_CHANNEL_A = 6;
constexpr int SCREW_2_CHANNEL_B = 7;
constexpr double SCREW_2_ENCODER_VERTICAL_DPP = 0.00048828125;
constexpr int LIFT_DIRECTION_UP = 1;
constexpr int LIFT_DIRECTION_DOWN = -1;
constexpr int LIFT_DIRECTION_FAST = -2;
constexpr int LIFT_DIRECTION_STOP = 0;
constexpr float ACME_SCREW_SPEED_UP = 1;
constexpr float ACME_SCREW_SPEED_DOWN = -0.8;
constexpr float ACME_SCREW_SPEED_FAST = -1;

// Drive Train Motor Controller Ports
#ifdef SECONDARY_ROBOT
constexpr int VICTOR_SP_DRIVE_LEFT1		=	0; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_DRIVE_LEFT2		=	1; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_DRIVE_RIGHT1	=	2; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_DRIVE_RIGHT2	=	3; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_GRABBER_LEFT	=	4; /* DeviceID matches the PWM Port */
constexpr int VICTOR_SP_GRABBER_RIGHT	=	5; /* DeviceID matches the PWM Port */
#endif
#ifndef SECONDARY_ROBOT
constexpr int VICTOR_SPX_DRIVE_LEFT1	=	40; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */
constexpr int VICTOR_SPX_DRIVE_LEFT2	=	41; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */
constexpr int VICTOR_SPX_DRIVE_RIGHT1	=	42; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */
constexpr int VICTOR_SPX_DRIVE_RIGHT2	=	43; /* DeviceID matches the web-based config for the CAN enabled Motor Contoller */

//Grabber Ports
constexpr int GRABBER_LEFT_SIDE_PORT = 45;
constexpr int GRABBER_RIGHT_SIDE_PORT = 46;

#endif

//Camera setting
constexpr int EXPOSURE = 50;
constexpr int BRIGHTNESS = 5;
constexpr int WIDTH_RESOL = 320;
constexpr int HEIGHT_RESOL = 240;
// Joystick Ports
constexpr int DRIVE_JOYSTICK_PORT	=	0;
constexpr int GAME_CONTROLLER_PORT  =	1;

// Joystick Items
constexpr int DRIVE_DISTANCE_BUTTON_NUMBER = 9;
constexpr int TURN_DEGREES_BUTTON = 10;
constexpr int RUN_GRABBER_BUTTON = 11;
constexpr int XY_DRIVE_GOVERNOR_NUMBER = 3;
constexpr int ROT_DRIVE_GOVERNOR_NUMBER = 4;
constexpr int LIFT_1_UP = 6; //Right Bumper Button
constexpr int LIFT_1_DOWN = 3; //Right Trigger Button
constexpr int LIFT_1_FAST = 8;//Start button
constexpr int LIFT_2_UP = 5; //Left Bumper Up
constexpr int LIFT_2_DOWN = 2; //Left Trigger Down
constexpr float TRIGGER_PERCENT_PRESS = .25;//trigger have a percent not a one
constexpr int GRABBER_IN_BUTTON = 1;//a button In
constexpr int GRABBER_OUT_BUTTON = 2;//b button Out
constexpr int GRABBER_STOP_BUTTON = 3;//x Button Stop
constexpr int GRABBER_SLOW_BUTTON = 4;//y Button Slow In
constexpr int GRABBER_LEFT_SIDE_AXIS = 1;
constexpr int GRABBER_RIGHT_SIDE_AXIS = 5;

// Pneumatics Items
constexpr int COMPRESSOR_PCM_ID = 0;
constexpr int PRESSURE_SENSOR_CHANNEL = 3;

//Grabber direction and speed
constexpr int GRABBER_IN = -1;
constexpr int GRABBER_OUT = 1;
constexpr int GRABBER_SLOW = -1;
constexpr int GRABBER_STOP = 0;
constexpr float GRABBER_SPEED = 1.0;

//Drive Sensor Channels
constexpr int LEFT_ENCODER_A_CHANNEL = 0;
constexpr int LEFT_ENCODER_B_CHANNEL = 1;
constexpr int RIGHT_ENCODER_A_CHANNEL = 2;
constexpr int RIGHT_ENCODER_B_CHANNEL = 3;

//Acceleration percent
constexpr double PERCENT_ACCEL = 0.01;

//Max Turning speed
constexpr double MAXTURNINGSPEED = .8;

//Gyro Channel
constexpr double GYRO_PORT = 0;
constexpr double KP_GYRO = -0.1;

//Distance for Encoder
constexpr double DRIVE_ENC_20_INCHES = 20;

//Grabber information
constexpr double SPIT_OUT_CUBE_TIME = 2;

//Auto distances
//Lift factor
constexpr float LIFTING_TO_SCALE_UPPER_1 = 50;
constexpr float LIFTING_TO_SCALE_LOWER_2 = 50;

//Lift Directions
constexpr int LIFT_UP_DIRECTION = 1;
constexpr int LIFT_DOWN_DIRECTION = -1;

//Angle values
constexpr int TURN_110_DEGREES = 110;
constexpr int TURN_70_DEGREES = 70;
constexpr int TURN_90_DEGREES = 90;
constexpr int L_TURN_RIGHT_DEGREES = -90;
constexpr int L_TURN_LEFT_DEGREES = 90;
constexpr int R_TURN_RIGHT_DEGREES = -90;
constexpr int R_TURN_LEFT_DEGREES = 90;
constexpr int M_TURN_RIGHT_DEGREES = -90;
constexpr int M_TURN_LEFT_DEGREES = 90;

constexpr double TURN_39_POINT_44_DEGREES = 39.44;

//LR_AutoLine
constexpr int LR_AUTOLINE_DISTANCE = 120;

//LR_AutoLinePush
constexpr int LR_AUTOLINE_PUSH_DISTANCE_1 = 244;
constexpr int LR_AUTOLINE_PUSH_DISTANCE_2 = 100;

//L_LeftSwitch and R_RightSwitch
//line up directly with switch fence
constexpr int LR_FIRST_DISTANCE_SWITCH_FENCE = 95;
//line Outside the switch fence
constexpr int LR_FIRST_DISTANCE_SWITCH_OFF_FENCE = 110;
//star 36 inches from wall
constexpr int LR_SECOND_DISTANCE_SWITCH_OFF_FENCE = 25;

//LR_SideSwitchPush
constexpr int LR_SIDE_SWITCH_PUSH_DISTANCE_1 = 31.5;
constexpr int LR_SIDE_SWITCH_PUSH_DISTANCE_2 = 150; //Adjust

//L_LeftScale and R_RightScale
constexpr int LR_SCALE_FIRST_DISTANCE = 222;
constexpr int LR_SCALE_SECOND_DISTANCE = 17;

//LR_SideScaleTwice
constexpr double LR_SCALE_TWICE_AWAY_FROM_SCALE = 19.35;
constexpr double LR_SCALE_TWICE_DRIVE_TO_CUBE = 134.2;

//L_RightScale and R_LeftScale
constexpr int LR_OPPOSITE_SCALE_FIRST_DISTANCE = 223.5;
constexpr int LR_OPPOSITE_SCALE_SECOND_DISTANCE = 242;
constexpr int LR_OPPOSITE_SCALE_THIRD_DISTANCE = 86.5;
constexpr int LR_OPPOSITE_SCALE_FOURTH_DISTANCE = 17;

//L_RightSwitch and R_LeftSwitch
constexpr int LR_OPPOSITE_SWITCH_FIRST_DISTANCE = 55;
constexpr int LR_OPPOSITE_SWITCH_SECOND_DISTANCE = 161;
constexpr int LR_OPPOSITE_SWITCH_THIRD_DISTANCE = 87;

//M_RightAutoLine
constexpr int M_SECOND_AUTO_LINE_DISTANCE = 100;
constexpr int M_FIRST_AUTO_LINE_DISTANCE = 22;
constexpr int M_AUTO_LINE_ANGLE_R = 35;
constexpr int M_AUTO_LINE_ANGLE_L = -35;

//M_Switch//
constexpr int M_DRIVE_OFF_WALL = 22;
constexpr int M_SWITCH_DISTANCE_1 = 65;
constexpr int M_SWITCH_DISTANCE_2 = 26;

//M_SwitchTwice
constexpr int M_SWITCH_TWICE_1 = -30;
constexpr double M_SWITCH_TWICE_ANGLE = 63.4;
constexpr int M_SWITCH_TWICE_2 = 50;


//Pathfinder CommandGroups

//Pathfinder L_RightScale and R_LeftScale
 //designate points and exit angles for pathfinder
constexpr float P_L_RIGHT_SCALE_X1 = 0;
constexpr float P_L_RIGHT_SCALE_Y1 = 223.5;
constexpr float P_L_RIGHT_SCALE_EA1 = 90;
constexpr float P_L_RIGHT_SCALE_X2 = 242;
constexpr float P_L_RIGHT_SCALE_Y2 = 223.5;
constexpr float P_L_RIGHT_SCALE_EA2 = 0;
constexpr float P_L_RIGHT_SCALE_X3 = 242;
constexpr float P_L_RIGHT_SCALE_Y3 = 310;
constexpr float P_L_RIGHT_SCALE_EA3 = 270;

constexpr float P_R_LEFT_SCALE_X1 = 0;
constexpr float P_R_LEFT_SCALE_Y1 = 223.5;
constexpr float P_R_LEFT_SCALE_EA1 = 270;
constexpr float P_R_LEFT_SCALE_X2 = -242;
constexpr float P_R_LEFT_SCALE_Y2 = 223.5;
constexpr float P_R_LEFT_SCALE_EA2 = 0;
constexpr float P_R_LEFT_SCALE_X3 = -242;
constexpr float P_R_LEFT_SCALE_Y3 = 310;
constexpr float P_R_LEFT_SCALE_EA3 = 90;

constexpr int P_LR_OPPOSITE_SCALE_FINAL_DRIVE = 17;

//Pathfinder L_RightSwitch and R_LeftSwitch
 //designate points and exit angles for pathfinder
constexpr float P_L_RIGHT_SWITCH_X1 = 0;
constexpr float P_L_RIGHT_SWITCH_Y1 = 223.5;
constexpr float P_L_RIGHT_SWITCH_EA1 = 45;
constexpr float P_L_RIGHT_SWITCH_X2 = 80.5;
constexpr float P_L_RIGHT_SWITCH_Y2 = 242.5;
constexpr float P_L_RIGHT_SWITCH_EA2 = 90;
constexpr float P_L_RIGHT_SWITCH_X3 = 161;
constexpr float P_L_RIGHT_SWITCH_Y3 = 223.5;
constexpr float P_L_RIGHT_SWITCH_EA3 = 180;

constexpr float P_R_LEFT_SWITCH_X1 = 0;
constexpr float P_R_LEFT_SWITCH_Y1 = 223.5;
constexpr float P_R_LEFT_SWITCH_EA1 = 315;
constexpr float P_R_LEFT_SWITCH_X2 = -80.5;
constexpr float P_R_LEFT_SWITCH_Y2 = 242.5;
constexpr float P_R_LEFT_SWITCH_EA2 = 270;
constexpr float P_R_LEFT_SWITCH_X3 = -161;
constexpr float P_R_LEFT_SWITCH_Y3 = 223.5;
constexpr float P_R_LEFT_SWITCH_EA3 = 180;

constexpr int P_LR_OPPOSITE_SWITCH_FINAL_DRIVE = 47;

//Pathfinder M_RightAutoLine and M_LeftAutoLine !!Check this One!!-Where is starting location
 //designate points and exit angles for pathfinder
constexpr float P_M_RIGHT_AUTO_LINE_X1 = 0;
constexpr float P_M_RIGHT_AUTO_LINE_Y1 = 70;
constexpr float P_M_RIGHT_AUTO_LINE_EA1 = 45;
constexpr float P_M_RIGHT_AUTO_LINE_X2 = 121;
constexpr float P_M_RIGHT_AUTO_LINE_Y2 = 105;
constexpr float P_M_RIGHT_AUTO_LINE_EA2 = 0;
constexpr float P_M_RIGHT_AUTO_LINE_X3 = 121;
constexpr float P_M_RIGHT_AUTO_LINE_Y3 = 223.5;
constexpr float P_M_RIGHT_AUTO_LINE_EA3 = 0;

constexpr float P_M_LEFT_AUTO_LINE_X1 = 0;
constexpr float P_M_LEFT_AUTO_LINE_Y1 = 70;
constexpr float P_M_LEFT_AUTO_LINE_EA1 = 315;
constexpr float P_M_LEFT_AUTO_LINE_X2 = -121;
constexpr float P_M_LEFT_AUTO_LINE_Y2 = 105;
constexpr float P_M_LEFT_AUTO_LINE_EA2 = 0;
constexpr float P_M_LEFT_AUTO_LINE_X3 = -121;
constexpr float P_M_LEFT_AUTO_LINE_Y3 = 223.5;
constexpr float P_M_LEFT_AUTO_LINE_EA3 = 0;

//Pathfinder M_LeftSwitch and M_RightSwitch
 //designate points and exit angles for pathfinder
constexpr float P_M_RIGHT_SWITCH_X1 = 0;
constexpr float P_M_RIGHT_SWITCH_Y1 = 22;
constexpr float P_M_RIGHT_SWITCH_EA1 = 45;
constexpr float P_M_RIGHT_SWITCH_X2 = 104;
constexpr float P_M_RIGHT_SWITCH_Y2 = 70;
constexpr float P_M_RIGHT_SWITCH_EA2 = 10;
constexpr float P_M_RIGHT_SWITCH_X3 = 104;
constexpr float P_M_RIGHT_SWITCH_Y3 = 110;
constexpr float P_M_RIGHT_SWITCH_EA3 = 0;

constexpr float P_M_LEFT_SWITCH_X1 = 0;
constexpr float P_M_LEFT_SWITCH_Y1 = 22;
constexpr float P_M_LEFT_SWITCH_EA1 = 315;
constexpr float P_M_LEFT_SWITCH_X2 = -104;
constexpr float P_M_LEFT_SWITCH_Y2 = 70;
constexpr float P_M_LEFT_SWITCH_EA2 = 350;
constexpr float P_M_LEFT_SWITCH_X3 = -104;
constexpr float P_M_LEFT_SWITCH_Y3 = 110;
constexpr float P_M_LEFT_SWITCH_EA3 = 0;

constexpr int M_LR_SWITCH_FINAL_DRIVE = 36;


//pathfinder constants
constexpr double WHEEL_BASE_WIDTH = 0.6; //distance between left and right wheels in meters

constexpr int INITIAL_POSITION = 0;
constexpr int TICKS_PER_REVOLUTION = 360;
constexpr double WHEEL_CIRCUMFRENCE = 0.4787787204060999; //meters
constexpr int MAX_VELOCITY = 15; //meters/sec
constexpr double KP = 1.0; //0.8-1.2 is common
constexpr double KI = 0.0; //unused
constexpr double KD = 0.0; //adjust if unhappy with tracking
constexpr double KV = 1/MAX_VELOCITY; // motor controller accepted max velocity
constexpr double KA = 0.0; //adjust to change acceleration rate

#endif // ROBOTMAP_H
