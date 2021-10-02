int redPin = 10;
int greenPin = 9;
int bluePin = 8;
int interval = 1000;

void setup() {
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);

}

void loop() {
  digitalWrite(redPin, HIGH);
  delay(interval);
  digitalWrite(redPin, LOW);
  delay(interval);

  digitalWrite(greenPin, HIGH);
  delay(interval);
  digitalWrite(greenPin, LOW);
  delay(interval);

  digitalWrite(bluePin, HIGH);
  delay(interval);
  digitalWrite(bluePin, LOW);
  delay(interval);

}
