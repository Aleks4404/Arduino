int analogValue;  
int analogPin = A0;
int ledPin = 7;

void setup()  
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()  
{
    analogValue = analogRead(analogPin);
    Serial.print("Value on analog output: ");
    Serial.println(analogValue);

   if (analogValue > 531 || analogValue < 520) {
    digitalWrite(ledPin, HIGH);
   }

   else {
    digitalWrite(ledPin, LOW);
   }

}
