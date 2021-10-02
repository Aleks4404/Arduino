int aPin = 1; 
int bPin = 2;
int cPin = 3;
int dPin = 4;
int ePin = 5;
int fPin = 6;
int gPin = 7;
int dpPin = 8;

int y1 = 10;
int y2 = 11;
int y3 = 12;
int y4 = 13;

int yArray[] = {y1, y2, y3, y4};

void setup() {

  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dpPin, OUTPUT);

  
  for (int i = 0; i < 4; i++) {
    pinMode(yArray[i], OUTPUT);
  }

}

void loop() {

  for (int y = 0; y < 4; y++) {
    digitalWrite(yArray[y], HIGH);
  }
  
  
  for (int y = 0; y < 4; y++) {
    digitalWrite(yArray[y], LOW);
    
    for (int x = 0; x < 10; x++) {
     LEDDisplay(x);
      delay(1000);
    }
    digitalWrite(yArray[y], HIGH);
    delay(1000);
  }

}

void LEDDisplay(int x) {

  switch(x) {
    case 0:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, LOW);
      digitalWrite(dpPin, LOW);
      break;
    case 1:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      digitalWrite(dpPin, LOW);
      break;
    case 2:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    case 3:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    case 4:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    case 5:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    case 6:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    case 7:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      digitalWrite(dpPin, LOW);
      break;
    case 8:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, HIGH);
      digitalWrite(ePin, HIGH);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    case 9:
      digitalWrite(aPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(cPin, HIGH);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(dpPin, LOW);
      break;
    default:
      digitalWrite(aPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(cPin, LOW);
      digitalWrite(dPin, LOW);
      digitalWrite(ePin, LOW);
      digitalWrite(fPin, LOW);
      digitalWrite(gPin, LOW);
      digitalWrite(dpPin, LOW);
  }
}
