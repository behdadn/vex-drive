/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       behdad                                                    */
/*    Created:      Thu Nov 11 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    9, 10           
// Controller1          controller                    
// Vision19             vision        19              
// Vision20             vision        20              
// BumperA              bumper        A               
// BumperB              bumper        B               
// Motor1               motor         1               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "auto.h"
#include "test.h"
#include "vex.h"

using namespace vex;

// divide all angles by 1.5!!!

bool intake = false;

void intake_toggle() {
  if (intake) {
    Motor1.stop();
    intake = false;
  } else {
    Motor1.setVelocity(60, percent);
    Motor1.spin(forward);
    intake = true;
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Drivetrain.setDriveVelocity(10, percent);

  // Controller1.ButtonA.pressed(intake_toggle);

  Brain.Screen.print("Brain Activated"); // don't remove this line!!

  encoder_test();
  // drive();
}
