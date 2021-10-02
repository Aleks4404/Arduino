#include <Stepper.h>

// change this to fit the number of steps per revolution // for your motor
//22 little from scanner
// em-286, 98steps per revolution, 460rpm
const int stepsPerRevolution = 196;

int MotorSpeed = 100;

// initialize the stepper library on pins 8 through 11:

Stepper myStepper(stepsPerRevolution, 8,9,10,11);

void setup() { 
// set the speed at 10 rpm: 
myStepper.setSpeed(MotorSpeed); 
delay(5000); 
}

void loop() {
  // step one revolution in one direction: 
  myStepper.step(stepsPerRevolution*10); 
  delay(2000); 

  // step one revolution in the other direction: 
  myStepper.step(-stepsPerRevolution*10); 
  delay(2000); 
}
