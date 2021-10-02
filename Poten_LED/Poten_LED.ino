const byte SENSOR = A0;
int value;

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  value = analogRead(SENSOR);
  Serial.println(value);
  delay(100);
}

