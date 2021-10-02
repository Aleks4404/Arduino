// pins for sensors
#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5

// pins for motor power
#define leftEngine 10
#define rightEngine 11

long duration, distance, RightSensor, LeftSensor;

void setup()
{
Serial.begin (9600);

pinMode(leftEngine, OUTPUT);
pinMode(rightEngine, OUTPUT);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

}

void loop() {
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;


Serial.print(LeftSensor);
Serial.print(" - ");
Serial.println(RightSensor);



if (RightSensor < 50) {
  analogWrite(leftEngine, 60);
  analogWrite(rightEngine, 150);
}

else if (LeftSensor < 50) {
  analogWrite(leftEngine, 150);
  analogWrite(rightEngine, 60);
}

else if (LeftSensor < 15 && RightSensor < 15) {
  analogWrite(leftEngine, 0);
  analogWrite(rightEngine, 0);
}

else {
  analogWrite(leftEngine, 150);
  analogWrite(rightEngine, 150);
}

}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;

}
