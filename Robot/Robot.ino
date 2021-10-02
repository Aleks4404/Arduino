// connect motor controller pins to Arduino digital pins
// right motor
#define in1 2
#define in2 4
// left motor
#define in4 7
#define in3 8


void moveStright();


void setup()
{
  // set all the motor control pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  moveStright();
  delay(7000);

}

void moveStright()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

