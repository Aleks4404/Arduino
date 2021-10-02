// bottom LED pins
int pin1 = 13; 
int pin2 = 12;
int pin3 = 11;
int pin4 = 10;   
int pin5 = 14; //    A0 => 14-th pin of arduino
int pin6 = 15; //    A1 => 15-th pin of arduino
int pin7 = 16; //    A2 => 16-th pin of arduino
int pin8 = 17; //    A3 => 17-th pin of arduino

//top LED pins
int pin9 = 9; 
int pin10 = 8;
int pin11 = 7;
int pin12 = 6;   
int pin13 = 5; 
int pin14 = 4;
int pin15 = 3;
int pin16 = 2; 


// pins arrays
int pinArray[] = {pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15, pin16};

// inPins. Resistors 220Om
int inPinArray[] = {pin1, pin2, pin5, pin7, pin8, pin11, pin13, pin16};
// outPins
int outPinArray[] = {pin3, pin4, pin6, pin9, pin10, pin12, pin14, pin15};
// rowPins
int rowArray[] = {pin16, pin11, pin8, pin13, pin1, pin7, pin2, pin5};
// columnPins
int columnArray[] = {pin12, pin3, pin4, pin15, pin6, pin14, pin10, pin9};

void setup() {
 
  // pinMode OUTPUT for all LED pins
  for (int i = 0; i < 16; i++) {
    pinMode(pinArray[i], OUTPUT);
  }

}

void loop() {
  smile();
  delay(500);
  heart();
  delay(500);
  
}

void ledON(int x, int y) {
  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 8; k++) {
      if (i == x && k == y) {
        digitalWrite(rowArray[i], HIGH);
        digitalWrite(columnArray[k], LOW);
        delay(1);
        digitalWrite(rowArray[i], LOW);
        digitalWrite(columnArray[k], LOW);
      }
      else {
        digitalWrite(rowArray[i], LOW);
        digitalWrite(columnArray[k], HIGH);
      }
    }
  }
}

void heart() {

  for (int i = 0; i < 50; i++){
    ledON(1,1);
    ledON(1,2);
    ledON(1,5);
    ledON(1,6);
    ledON(2,0);
    ledON(2,3);
    ledON(2,4);
    ledON(2,7);
    ledON(3,0);
    ledON(3,7);
    ledON(4,1);  
    ledON(4,6);
    ledON(5,2);  
    ledON(5,5);
    ledON(6,3);  
    ledON(6,4);
  } 
}

void smile() {

  for (int i = 0; i < 50; i++){
    ledON(2,1);
    ledON(2,2);
    ledON(2,5);
    ledON(2,6);
    ledON(3,1);
    ledON(3,2);
    ledON(3,5);
    ledON(3,6);
    ledON(5,1);  
    ledON(5,6);
    ledON(6,2);
    ledON(6,3);
    ledON(6,4);
    ledON(6,5);
  } 
}

