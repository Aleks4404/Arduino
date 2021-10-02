int aPin = 9; 
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

int ledArray[] = {aPin, bPin, cPin, dPin, ePin, fPin, gPin, dpPin};
int yArray[] = {y1, y2, y3, y4};

int test = 9999;

int LEDPin = 1; 

void setup() {

  pinMode(LEDPin, OUTPUT);
  
  // pinMode OUTPUT for all LED pins
  for (int i = 0; i < 8; i++) {
    pinMode(ledArray[i], OUTPUT);
  }


  // pinMode OUTPUT for pins that control digits
  for (int i = 0; i < 4; i++) {
    pinMode(yArray[i], OUTPUT);
  }

  // Serial port configuration for troubleshooting
  Serial.begin(9600);

}

void loop() {
  
  int thousand = test/1000;
  int hundred = (test - thousand*1000)/100;
  int ten = (test - thousand*1000 - hundred*100)/10;
  int one = test - thousand*1000 - hundred*100 - ten*10;
  
  // OFF all digit pins at start
  for (int y = 0; y < 4; y++) {
    digitalWrite(yArray[y], HIGH);
  }
  
  // check that number to display is not zero
  if (test > 0) {
      
      // display first digit
      if (thousand != 0) {
        digitalWrite(yArray[0], LOW);
        LEDDisplay(thousand);
        dp();
        delay (5);
        digitalWrite(yArray[0], HIGH);
      } else {
        digitalWrite(yArray[0], LOW);
        LEDDisplay(0);
        delay (5);
        digitalWrite(yArray[0], HIGH);
      }

      // display second digit
      if (hundred != 0) {
        digitalWrite(yArray[1], LOW);
        LEDDisplay(hundred);
        delay (5);
        digitalWrite(yArray[1], HIGH);
      } else {
        digitalWrite(yArray[1], LOW);
        LEDDisplay(0);
        delay (5);
        digitalWrite(yArray[1], HIGH);    
      }

      // display third digit
      if (ten != 0) {
        digitalWrite(yArray[2], LOW);
        LEDDisplay(ten);
        delay (5);
        digitalWrite(yArray[2], HIGH);
      } else {
        digitalWrite(yArray[2], LOW);
        LEDDisplay(0);
        delay (5);
        digitalWrite(yArray[2], HIGH);    
      }

      // display last digit
      if (one != 0) {
        digitalWrite(yArray[3], LOW);
        LEDDisplay(one);
        delay (5);
        digitalWrite(yArray[3], HIGH);
      } else {
        digitalWrite(yArray[3], LOW);
        LEDDisplay(0);
        delay (5);
        digitalWrite(yArray[3], HIGH);    
      }

    // decriment number fo count down  
    test = test - 1;
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

void dp () {
//      digitalWrite(aPin, LOW);
//      digitalWrite(bPin, LOW);
//      digitalWrite(cPin, LOW);
//      digitalWrite(dPin, LOW);
//      digitalWrite(ePin, LOW);
//      digitalWrite(fPin, LOW);
//      digitalWrite(gPin, LOW);
      digitalWrite(dpPin, HIGH);
}

