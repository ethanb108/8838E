#include "devices.h"

// Rotation direction of the motors
const bool kRotateFoward = false;
const bool kRotateReverse = true;

// Drivetrain setting
const vex::gearSetting kDrivetrainGears = vex::gearSetting::ratio6_1;

Devices::Devices() {
  // Brain
  brain_.reset(new vex::brain());

  // Controller
  main_controller_.reset(new vex::controller(vex::controllerType::primary));

  // Drivetrain Motors
  leftFrontMotor_.reset(new vex::motor(vex::PORT18, kDrivetrainGears, kRotateReverse));
  leftMiddleMotor_.reset(new vex::motor(vex::PORT19, kDrivetrainGears, kRotateReverse));
  leftBackMotor_.reset(new vex::motor(vex::PORT20, kDrivetrainGears, kRotateReverse));
 
  rightFrontMotor_.reset(new vex::motor(vex::PORT13, kDrivetrainGears, kRotateFoward));
  rightMiddleMotor_.reset(new vex::motor(vex::PORT12, kDrivetrainGears, kRotateFoward));
  rightBackMotor_.reset(new vex::motor(vex::PORT11, kDrivetrainGears, kRotateFoward));
  
  leftDriveGroup_.reset(new vex::motor_group(*leftFrontMotor_, *leftMiddleMotor_, *leftBackMotor_));
  rightDriveGroup_.reset(new vex::motor_group(*rightFrontMotor_, *rightMiddleMotor_, *rightBackMotor_));
}