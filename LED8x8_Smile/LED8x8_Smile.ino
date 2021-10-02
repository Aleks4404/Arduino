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

// inPins
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

  digitalWrite(rowArray[1], HIGH);
  digitalWrite(rowArray[2], HIGH);
  digitalWrite(columnArray[0], HIGH);
  digitalWrite(columnArray[3], HIGH);
  digitalWrite(columnArray[4], HIGH);
  digitalWrite(columnArray[7], HIGH);
  delay(2);
  digitalWrite(rowArray[1], LOW);
  digitalWrite(rowArray[2], LOW);
  digitalWrite(columnArray[0], LOW);
  digitalWrite(columnArray[3], LOW);
  digitalWrite(columnArray[4], LOW);
  digitalWrite(columnArray[7], LOW);
  delay(2);
  digitalWrite(rowArray[4], HIGH);
  digitalWrite(columnArray[0], HIGH);
  digitalWrite(columnArray[1], HIGH);
  digitalWrite(columnArray[2], HIGH);
  digitalWrite(columnArray[5], HIGH);
  digitalWrite(columnArray[6], HIGH);
  digitalWrite(columnArray[7], HIGH);
  delay(2);
  digitalWrite(rowArray[4], LOW);
  digitalWrite(columnArray[0], LOW);
  digitalWrite(columnArray[1], LOW);
  digitalWrite(columnArray[2], LOW);
  digitalWrite(columnArray[5], LOW);
  digitalWrite(columnArray[6], LOW);
  digitalWrite(columnArray[7], LOW);
  delay(2);

  digitalWrite(rowArray[5], HIGH);
  digitalWrite(columnArray[0], HIGH);
  digitalWrite(columnArray[2], HIGH);
  digitalWrite(columnArray[3], HIGH);
  digitalWrite(columnArray[4], HIGH);
  digitalWrite(columnArray[5], HIGH);
  digitalWrite(columnArray[7], HIGH);
  delay(2); 
  digitalWrite(rowArray[5], LOW);
  digitalWrite(columnArray[0], LOW);
  digitalWrite(columnArray[2], LOW);
  digitalWrite(columnArray[3], LOW);
  digitalWrite(columnArray[4], LOW);
  digitalWrite(columnArray[5], LOW);
  digitalWrite(columnArray[7], LOW);
  delay(2);  

  digitalWrite(rowArray[6], HIGH);
  digitalWrite(columnArray[0], HIGH);
  digitalWrite(columnArray[1], HIGH);
  digitalWrite(columnArray[6], HIGH);
  digitalWrite(columnArray[7], HIGH);
  delay(2); 
  digitalWrite(rowArray[6], LOW);
  digitalWrite(columnArray[0], LOW);
  digitalWrite(columnArray[1], LOW);
  digitalWrite(columnArray[6], LOW);
  digitalWrite(columnArray[7], LOW);
  delay(2); 
}

