#include <Servo.h>

Servo myservo;  // create servo object to control a servo 

int rightSensor = A0;  // right sensor
int leftSensor = A1;  // left sensor
int motor = 3; // pwm for DC motors
int valueOfTheRightSensor;    // variable to read the value from the analog pin0 
int valueOfTheLeftSensor;    // variable to read the value from the analog pin0 

int rightSensorStartValue = 0;
int leftSensorStartValue = 0;

int startWheelPosition = 90;
int newWheelPosition = 90;

                                                                                                                                                                           

void setup() 
{ 

  pinMode(motor, OUTPUT);
  myservo.attach(2);  // attaches the servo on pin 2 to the servo object 
  Serial.begin(9600);

  Serial.println("Initializing start values of light sensors... ");
  delay(5000);
  leftSensorStartValue = analogRead(leftSensor);
  rightSensorStartValue = analogRead(rightSensor);
  Serial.println("Start values of light sensors initialized. ");
  Serial.println();
  Serial.print("Start value of the left sensor: ");
  Serial.print(leftSensorStartValue); 
  Serial.print(", ");
  Serial.print("Start value of the right sensor: ");
  Serial.print(rightSensorStartValue);  
  Serial.println();
  delay(5000);
} 

void loop() 
{ 
  digitalWrite(motor, HIGH);
  delay(300);
  digitalWrite(motor, LOW);
  delay(300);

  
  valueOfTheRightSensor = analogRead(rightSensor);            // reads the value of the rightSensor (value between 0 and 1023) 
  valueOfTheLeftSensor = analogRead(leftSensor);            // reads the value of the leftSensor (value between 0 and 1023) 
  
  Serial.print("valueOfTheLeftSensor: ");
  Serial.print(valueOfTheLeftSensor); 
  Serial.print(", ");
  Serial.print("valueOfTheRightSensor: ");
  Serial.print(valueOfTheRightSensor);  
  Serial.println();


  if (valueOfTheRightSensor < rightSensorStartValue*0.80) {
    newWheelPosition = newWheelPosition + 1;
    myservo.write(120);   
    delay(20);
    
 
  }
  
  else if (valueOfTheLeftSensor < leftSensorStartValue*0.80) {
    newWheelPosition = newWheelPosition - 1;
    myservo.write(60);  
    delay(20); 
  }  

  else {
    myservo.write(startWheelPosition);
    delay(20); 

  }
  
 

} 
