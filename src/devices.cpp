#include "devices.h"

// Rotation direction of the motors
const bool kRotateFoward = false;
const bool kRotateReverse = true;

// Drivetrain setting
const vex::gearSetting kDrivetrainGears = vex::gearSetting::ratio6_1;

Devices::Devices(RobotConfig config) {
  // Brain
  brain_.reset(new vex::brain());

  // Controller
  main_controller_.reset(new vex::controller(vex::controllerType::primary));

  // Drivetrain Motors
  if (config == RobotConfig::SCHOOL_BOT){
    leftFrontMotor_.reset(new vex::motor(vex::PORT13, kDrivetrainGears, kRotateReverse));
    leftUpperMotor_.reset(new vex::motor(vex::PORT11, kDrivetrainGears, kRotateFoward));
    leftBackMotor_.reset(new vex::motor(vex::PORT18, kDrivetrainGears, kRotateReverse));
 
    rightFrontMotor_.reset(new vex::motor(vex::PORT6, kDrivetrainGears, kRotateFoward));
    rightUpperMotor_.reset(new vex::motor(vex::PORT7, kDrivetrainGears, kRotateReverse));
    rightBackMotor_.reset(new vex::motor(vex::PORT1, kDrivetrainGears, kRotateFoward));
  } else if (config == RobotConfig::ETHAN_HOME_BOT){
    leftFrontMotor_.reset(new vex::motor(vex::PORT18, kDrivetrainGears, kRotateReverse));
    leftUpperMotor_.reset(new vex::motor(vex::PORT19, kDrivetrainGears, kRotateReverse));
    leftBackMotor_.reset(new vex::motor(vex::PORT20, kDrivetrainGears, kRotateReverse));
 
    rightFrontMotor_.reset(new vex::motor(vex::PORT13, kDrivetrainGears, kRotateFoward));
    rightUpperMotor_.reset(new vex::motor(vex::PORT12, kDrivetrainGears, kRotateFoward));
    rightBackMotor_.reset(new vex::motor(vex::PORT11, kDrivetrainGears, kRotateFoward));
  }

  leftDriveGroup_.reset(new vex::motor_group(*leftFrontMotor_, *leftUpperMotor_, *leftBackMotor_));
  rightDriveGroup_.reset(new vex::motor_group(*rightFrontMotor_, *rightUpperMotor_, *rightBackMotor_));

  // Intake Motors
  if (config == RobotConfig::SCHOOL_BOT) {
    firstStage5WattMotor_.reset(new vex::motor(vex::PORT12, kRotateReverse));
    secondStage11WattMotor_.reset(new vex::motor(vex::PORT5, kRotateFoward));
    secondStage5WattMotor_.reset(new vex::motor(vex::PORT3, kRotateReverse));
  
    intakeMotorGroup_.reset(new vex::motor_group(*firstStage5WattMotor_, *secondStage11WattMotor_, *secondStage5WattMotor_));
  } else if (config == RobotConfig::ETHAN_HOME_BOT) {
    firstStage5WattMotor_.reset(new vex::motor(vex::PORT7, kRotateReverse));

    intakeMotorGroup_.reset(new vex::motor_group(*firstStage5WattMotor_));
  }
};