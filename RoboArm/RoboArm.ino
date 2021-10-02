#include <Servo.h>

#define baseMotor 6
#define shoulderMotor 9
#define elbowMotor 10
#define endEffectorMotor 11

#define timeBetweenSteps 20

short currentBaseServoAngle = 90, currentShoulderServoAngle = 0, currentElbowServoAngle = 180, currentEndEffectorServoAngle = 0;
//for serial input
short baseServoAngle, shoulderServoAngle, elbowServoAngle, endEffectorServoAngle;
// create servo object to control a servo
Servo baseServo, shoulderServo, elbowServo, endEffectorServo;

String inString = "";    // string to hold input

void setup() {
  //Initialize The Serial Port
  Serial.begin(9600);
  Serial.println("Enter parameters: base_angle,shoulder_angle,elbow_angle,end_effector_angle");
  Serial.println();
    
  //Initialize The Servo Motors
  initializeServos();
  delay(5000);
}

void loop() {
  // Read serial input:
  readValuesFromSerial();
  
/* 
  servoAngles(90,10,100,30);
  delay(300);
  servoAngles(90,90,100,30);
  delay(300);
  servoAngles(90,90,100,0);
  delay(300);
  servoAngles(90,20,30,0);
  delay(300);
  servoAngles(0,20,30,0);
  delay(300);
  servoAngles(0,50,30,0);
  delay(300);
  servoAngles(0,50,30,30);
  delay(300);
  */
}

/*
Function to move servo motor
Servo num -- name of the servo
int pos -- desired position in degrees
int time -- delay between steps
int start -- start position of the servo
*/
void servoSlow(Servo num, int pos, int time, int start){
  num.write(start);
  if (start < pos) {

    for ( int i = start; i < pos; i++){ 
      num.write(i);
      delay(time);
    }
  }
  else {
    for ( int i = start; i > pos; i--)
    { num.write(i);
      delay(time);
    }
  }
}


void initializeServos() {
  /*
  end effector -- close 0, 
  elbow -- down 180 (free to move conterclockwise to 0)
  shoulder -- up 0 (free to move clockwise to 180)
  base -- middle 90 (0 - right, 180 - left)
  */
  
  //Initialize The Servo Motor
  baseServo.attach(baseMotor);
  baseServo.write(90);
  
  shoulderServo.attach(shoulderMotor);
  shoulderServo.write(0);  

  elbowServo.attach(elbowMotor);
  elbowServo.write(180);
  
  endEffectorServo.attach(endEffectorMotor);
  endEffectorServo.write(0);  
}

void readValuesFromSerial(){
  // Read serial input:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    // if you get a newline, print the string,
    // then the string's value:    
    if (inChar == '\n') {
      /*
      strtok() is destructive in its parsing (ie it writes to the string you're parsing while you're parsing it), so it takes a char* as a parameter, not a const char*.
      c_str() returns a const char* since it does not expect you to write to the content of the buffer it returns.
      A way to do the parsing is to strdup() (ie copy) the buffer you want to work and parse that
      */  
      char* buf = strdup(inString.c_str());
      String tok;

      tok = strtok(buf, ",");
      baseServoAngle = tok.toInt();
      Serial.print("baseServoAngle: ");
      Serial.println(baseServoAngle);
      servoSlow(baseServo, baseServoAngle, timeBetweenSteps, currentBaseServoAngle);
      currentBaseServoAngle = baseServoAngle;
  
      tok = strtok(NULL, ",");
      shoulderServoAngle = tok.toInt();
      Serial.print("shoulderServoAngle: ");
      Serial.println(shoulderServoAngle);
      servoSlow(shoulderServo, shoulderServoAngle, timeBetweenSteps, currentShoulderServoAngle);
      currentShoulderServoAngle = shoulderServoAngle;
      
      tok = strtok(NULL, ",");
      elbowServoAngle = abs(tok.toInt() - 180);
      Serial.print("elbowServoAngle: ");
      Serial.println(elbowServoAngle);
      servoSlow(elbowServo, elbowServoAngle, timeBetweenSteps, currentElbowServoAngle);
      currentElbowServoAngle = elbowServoAngle;
      
      tok = strtok(NULL, ",");
      if (tok.toInt() > 50) {
        endEffectorServoAngle = 50;
      } else {
        endEffectorServoAngle = tok.toInt();
      }
      Serial.print("endEffectorServoAngle: ");
      Serial.println(endEffectorServoAngle);
      servoSlow(endEffectorServo, endEffectorServoAngle, timeBetweenSteps, currentEndEffectorServoAngle);
      currentEndEffectorServoAngle = endEffectorServoAngle;
      
      //clear inString for next loop
      inString = ""; 
    
    } else {
      inString += inChar;
    }
  }
}

//define servos position - like this: 90,90,90,90 (base, shoulder, elbow, tip)
void servoAngles(short baseServoAngle, short shoulderServoAngle,short elbowServoAngle,short endEffectorServoAngle) {
  servoSlow(baseServo, baseServoAngle, timeBetweenSteps, currentBaseServoAngle);
  currentBaseServoAngle = baseServoAngle;
  
  servoSlow(shoulderServo, shoulderServoAngle, timeBetweenSteps, currentShoulderServoAngle);
  currentShoulderServoAngle = shoulderServoAngle;
      
  elbowServoAngle = abs(elbowServoAngle - 180);
  servoSlow(elbowServo, elbowServoAngle, timeBetweenSteps, currentElbowServoAngle);
  currentElbowServoAngle = elbowServoAngle;

  if (endEffectorServoAngle > 50) {
    endEffectorServoAngle = 50;
  } 
  servoSlow(endEffectorServo, endEffectorServoAngle, timeBetweenSteps, currentEndEffectorServoAngle);
  currentEndEffectorServoAngle = endEffectorServoAngle;
}
