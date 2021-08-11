#ifndef STEPPER_H
#define STEPPER_H

//Libraries
#include <Arduino.h>
#include "DRV8825.h"

//Defining DRV8825 pins for Stepper 1 (lead screw)
#define Stepper_1_M0 17
#define Stepper_1_step 19
#define Stepper_1_dir 18

//Defining DRV7725 pinsfor Stepper 2 (roller)
#define Stepper_2_M0 2
#define Stepper_2_step 23
#define Stepper_2_dir 22

// Acceleration and deceleration values are always in FULL steps / s^2
#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000
#define MOTOR_STEPS 200   //6400 steps for microstepping
#define RPM 120           //Revolutions per minute
#define MICROSTEPS 1      //Set to 16 for microstep

//Create DRV8825 stepper objects
DRV8825 stepper_1(MOTOR_STEPS, Stepper_1_dir, Stepper_1_step, 
        Stepper_1_M0, Stepper_1_M0, Stepper_1_M0);
DRV8825 stepper_2(MOTOR_STEPS, Stepper_2_dir, Stepper_2_step, 
        Stepper_2_M0, Stepper_2_M0, Stepper_2_M0);

void stepperSetup() {
  stepper_1.begin(RPM, MICROSTEPS);
  stepper_2.begin(RPM, MICROSTEPS);

  //Energizes coil to hold motor shaft (disable to release hold)
  stepper_1.enable();
  stepper_2.enable();
  
  stepper_1.setSpeedProfile(stepper_1.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
  stepper_2.setSpeedProfile(stepper_2.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
} //Use stepper.move(-MOTOR_STEPS*MICROSTEPS) to take motor step
#endif
