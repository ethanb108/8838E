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
  leftFrontMotor_.reset(new vex::motor(vex::PORT13, kDrivetrainGears, kRotateReverse));
  leftUpperMotor_.reset(new vex::motor(vex::PORT11, kDrivetrainGears, kRotateFoward));
  leftBackMotor_.reset(new vex::motor(vex::PORT18, kDrivetrainGears, kRotateReverse));
 
  rightFrontMotor_.reset(new vex::motor(vex::PORT14, kDrivetrainGears, kRotateFoward));
  rightUpperMotor_.reset(new vex::motor(vex::PORT12, kDrivetrainGears, kRotateReverse));
  rightBackMotor_.reset(new vex::motor(vex::PORT20, kDrivetrainGears, kRotateFoward));
  
  leftDriveGroup_.reset(new vex::motor_group(*leftFrontMotor_, *leftUpperMotor_, *leftBackMotor_));
  rightDriveGroup_.reset(new vex::motor_group(*rightFrontMotor_, *rightUpperMotor_, *rightBackMotor_));

  // Intake Motors
  firstStage5WattMotor_.reset(new vex::motor(vex::PORT8, kRotateReverse));
  secondStage11WattMotor_.reset(new vex::motor(vex::PORT2, kRotateFoward));
  secondStage5WattMotor_.reset(new vex::motor(vex::PORT3, kRotateReverse));
}