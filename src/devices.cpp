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
 
  rightFrontMotor_.reset(new vex::motor(vex::PORT6, kDrivetrainGears, kRotateFoward));
  rightUpperMotor_.reset(new vex::motor(vex::PORT7, kDrivetrainGears, kRotateReverse));
  rightBackMotor_.reset(new vex::motor(vex::PORT1, kDrivetrainGears, kRotateFoward));
  
  leftDriveGroup_.reset(new vex::motor_group(*leftFrontMotor_, *leftUpperMotor_, *leftBackMotor_));
  rightDriveGroup_.reset(new vex::motor_group(*rightFrontMotor_, *rightUpperMotor_, *rightBackMotor_));

  // Intake Motors
  firstStage5WattMotor_.reset(new vex::motor(vex::PORT12, kRotateReverse));
  secondStage11WattMotor_.reset(new vex::motor(vex::PORT5, kRotateFoward));
  secondStage5WattMotor_.reset(new vex::motor(vex::PORT3, kRotateReverse));

  // Intake motor groups
  intakeMotorGroup_.reset(new vex::motor_group(*firstStage5WattMotor_, *secondStage11WattMotor_, *secondStage5WattMotor_));
}