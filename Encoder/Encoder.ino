#define encoderPin 2

int encoderPos = 0;
int encoderPinLastStatus = LOW;
int encoderPinCurrentStatus = LOW;

void setup() {
  pinMode (encoderPin, INPUT);
  Serial.begin (9600);
}

void loop() {
  encoderPinCurrentStatus = digitalRead(encoderPin);
  if ((encoderPinLastStatus == LOW) && (encoderPinCurrentStatus == HIGH)) {
    encoderPos++;
    Serial.println (encoderPos);
  }
  encoderPinLastStatus = encoderPinCurrentStatus;
}


