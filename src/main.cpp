/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ebringle                                                  */
/*    Created:      8/9/2024, 7:45:15 PM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "devices.h"
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// Global Robot Configuration
Devices robot;

// Write a line of text to the top of the screen(mostly for debugging).
void WriteText(const std::string &text) {
  robot.brain_->Screen.clearLine(1);
  robot.brain_->Screen.print("%s", text.c_str());
}

// Remap joystick sensitivity
// Note: Value returned will be -1 to 1.
// https://www.chiefdelphi.com/t/paper-joystick-sensitivity-gain-adjustment/107280/15
double RemapJoystick(const vex::controller::axis &joystick_axis, double a1) {
  // Scaling it to [-1, 1]
  double x = joystick_axis.value() / 127.0;

  // Remap with y = a(x^3) + (1-a)x
  return a1 * x * x * x + (1.0 - a1) * x;
}

// Arcade drive
void ArcadeDrive() {
  // Configuration parameters
  const double max_velocity = 100.0;
  const double throttle_tuning = 0.6;
  const double turn_tuning = 0.6;
  const double turn_scaling = 0.5;
  const double spin_scaling = 0.5;

  // Get the current controller joysitck state.
  double throttle = max_velocity * RemapJoystick(robot.main_controller_->Axis3, throttle_tuning);
  double turn = max_velocity * RemapJoystick(robot.main_controller_->Axis1, turn_tuning);

  // Scaling the value of turn to be proportinal to throttle so if throttle is
  // small turning will also be smaller.
  double scaled_turn = (turn * turn_scaling) * (throttle / max_velocity);

  // Calculate drive group velocities.
  double velocity_left = 0.0;
  double velocity_right = 0.0;

  if (turn == 0) {
    // Moving in a straight line.
    velocity_left = throttle;
    velocity_right = throttle;
  } else if (throttle == 0) {
    // Turning in place.
    velocity_left = turn * spin_scaling;
    velocity_right = -turn * spin_scaling;
  } else if (turn > 0) {
    // Turning right
    velocity_left = throttle;
    velocity_right = throttle - scaled_turn;
  } else {
    // Turning left
    velocity_left = throttle + scaled_turn;
    velocity_right = throttle;
  }

  // Set velocity of drivetrain.
  robot.leftDriveGroup_->setVelocity(velocity_left, vex::percentUnits::pct);
  robot.leftDriveGroup_->spin(vex::directionType::fwd);

  robot.rightDriveGroup_->setVelocity(velocity_right, vex::percentUnits::pct);
  robot.rightDriveGroup_->spin(vex::directionType::fwd);
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  WriteText("Pre-autonomous");
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  WriteText("Autonomous");
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

long count = 0;

void usercontrol(void) {
  WriteText("User-control");
  // Controller button event handlers
  robot.main_controller_->Axis3.changed(ArcadeDrive);
  robot.main_controller_->Axis1.changed(ArcadeDrive);

  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec);  // Sleep the task for a short amount of time to
                     // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  WriteText("Initializing");
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Call uservontrol directly until we find out how to start
  // it in that mode for testing.
  usercontrol();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
