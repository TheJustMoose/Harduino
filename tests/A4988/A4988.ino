// Test code for A4988 shield
// See description of StepperDriver library here:
// https://www.arduino.cc/reference/en/libraries/stepperdriver/
//
#include "A4988.h"

const short step_pin = 5;
const short dir_pin = 6;
const short rpm = 60;  // rotational speed
const short steps_to_revolution = 200;

A4988 stepper(steps_to_revolution, dir_pin, step_pin);

void setup() {
  // Set target motor RPM to 1RPM and microstepping to 1 (full step mode)
  stepper.begin(rpm, 1);
}

void loop() {
  // Tell motor to rotate 360 degrees.
  stepper.rotate(360);
}
