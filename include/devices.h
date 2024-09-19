#ifndef DEVICES_H
#define DEVICES_H

#include <memory>
#include "vex.h"

// Class to hold all of the devices and device groups on the robot.
class Devices {
 public:
  Devices();
  ~Devices() = default;

 //private:
  // VexV5 Brain
  std::unique_ptr<vex::brain> brain_;

  // VexV5 Controller
  std::unique_ptr<vex::controller> main_controller_;

  // VexV5 Drivetrain Motors
  std::unique_ptr<vex::motor> leftFrontMotor_;
  std::unique_ptr<vex::motor> leftUpperMotor_;
  std::unique_ptr<vex::motor> leftBackMotor_;

  std::unique_ptr<vex::motor> rightFrontMotor_;
  std::unique_ptr<vex::motor> rightUpperMotor_;
  std::unique_ptr<vex::motor> rightBackMotor_;

  // VexV5 Drivetrain Motor Groups
  std::unique_ptr<vex::motor_group> leftDriveGroup_;
  std::unique_ptr<vex::motor_group> rightDriveGroup_;

  // VexV5 Intake Motors
  std::unique_ptr<vex::motor> firstStage5WattMotor_;
  std::unique_ptr<vex::motor> secondStage11WattMotor_;
  std::unique_ptr<vex::motor> secondStage5WattMotor_;
};

#endif  // #ifndef DEVICES_H
