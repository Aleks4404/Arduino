#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// connect motor controller pins to Arduino digital pins
// right motor
#define enA 8
#define in1 9
#define in2 10
// left motor
#define enB 7
#define in4 6
#define in3 5

// servo angles for Ultrasonic
#define right 0
#define center 75
#define left 160

// Ultrasonic pins
#define echoPin 13
#define trigPin 12

LiquidCrystal_I2C lcd(0x27, 16, 2);   /* Задаем адрес и размерность дисплея.
  При использовании LCD I2C модуля с дисплеем 20х04 ничего в коде изменять не требуется, cледует только задать правильную размерность */

Servo myservo;  // create servo object to control a servo

// variable for ultrasonic measurements
int distance;

void servoSlow(Servo num, int pos, int time, int start);
void findDistance();
void moveStright();
void moveBackward();
void turnRight();
void turnLeft();
void stopMotors();

void setup()
{
  // Print a message to the LCD.
  lcd.begin();
  lcd.setCursor(0, 0); // first digit is a column, second is a row
  lcd.print("Scanning...");

  //Initialize The Serial Port
  Serial.begin(9600);

  //Initialize The Servo Motor
  myservo.attach(2);  // attaches the servo on pin 2 to the servo object
  myservo.write(center);

  servoSlow(myservo, 180, 10, center); // Servo num, int pos, int time, int start
  servoSlow(myservo, center, 10, 180);
  servoSlow(myservo, 0, 10, center);
  servoSlow(myservo, center, 10, 0);

  //Ultrasonic Pin Mode Settings
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // PWM for motors
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void loop()
{
  findDistance();
  if (distance > 30 || distance == 0) {
    moveStright();
  } else {
    stopMotors();
    delay(50);
    findDistance();
    if (distance > 30 || distance == 0) {
      moveStright();
    } else {
      myservo.write(center - 50);
      delay(500);
      findDistance();
      if (distance > 30 || distance == 0) {
        myservo.write(center);
        delay(500);
        turnRight();
        delay(900);
      } else {
        myservo.write(center + 50);
        delay(1000);
        findDistance();
        if (distance > 30 || distance == 0) {
          myservo.write(center);
          delay(800);
          turnLeft();
          delay(900);
        } else {
          myservo.write(center);
          delay(800);
          turnLeft();
          delay(1800);
        }
      }

    }
  }
}

void moveStright()
{
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveBackward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() // delay(900) on speed 255
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() // delay(900) on speed 255
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopMotors()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// manage servo motion speed
void servoSlow( Servo num, int pos, int time, int start)
{
  num.write(start);
  if (start < pos) {

    for ( int i = start; i < pos; i++)
    { num.write(i);
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

// Measure distance with Ultrasonic sensor
void findDistance() {
  int duration = 0;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * (1 / 29.1);
  delay(60);
}



