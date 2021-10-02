#include <Servo.h>

// motor one
#define enA 11
#define in1 12
#define in2 13
// motor two
#define enB 9
#define in3 7
#define in4 8
// servo motors
#define pan 5
#define tilt 6

Servo panServo, tiltServo;  // create servo object to control a servo

void moveStright(int PWM, int time);

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Initialize The Servo Motor
  panServo.attach(pan);
  panServo.write(90);  
  tiltServo.attach(tilt);
  tiltServo.write(60); 
  
  // logging
  Serial.begin(9600); //set the baud rate of the serial monitor
  
}

 
void loop()
{
  //moveStright(150, 5000);
}


void moveStright(int PWM, int time)
{
  analogWrite(enA, PWM);  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enB, PWM);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
    
  delay(time);
}

