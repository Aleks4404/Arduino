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
    Serial.println(analogValue);
    delay(1000);

    if (analogValue > 0) {
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }
}
