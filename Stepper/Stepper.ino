// connect motor controller pins to Arduino digital pins
// motor one
int A_plus = 8;
int A_minus = 9;

int B_plus = 10;
int B_minus = 11;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(A_plus, OUTPUT);
  pinMode(A_minus, OUTPUT);
  pinMode(B_plus, OUTPUT);
  pinMode(B_minus, OUTPUT);

  digitalWrite(A_plus, HIGH);
  digitalWrite(A_minus, LOW);
  digitalWrite(B_plus, HIGH); 
  digitalWrite(B_minus, LOW); 

}

void loop()
{
/*
  //WAVE DRIVE (FULL STEP)
  // step 0
  digitalWrite(A_plus, HIGH);
  digitalWrite(A_minus, LOW);
  digitalWrite(B_plus, LOW); 
  digitalWrite(B_minus, LOW);
  delay(10);

  // step 1
  digitalWrite(A_plus, LOW);
  digitalWrite(A_minus, LOW);
  digitalWrite(B_plus, HIGH); 
  digitalWrite(B_minus, LOW); 
  delay(10);

  // step 2
  digitalWrite(A_plus, LOW);
  digitalWrite(A_minus, HIGH);
  digitalWrite(B_plus, LOW); 
  digitalWrite(B_minus, LOW); 
  delay(10);

  // step 3
  digitalWrite(A_plus, LOW);
  digitalWrite(A_minus, LOW);
  digitalWrite(B_plus, LOW); 
  digitalWrite(B_minus, HIGH); 
  delay(10);
*/

/*
  //2-PHASE (FULL STEP) OPERATION
  // step 0
  digitalWrite(A_plus, HIGH);
  digitalWrite(A_minus, LOW);
  digitalWrite(B_plus, HIGH); 
  digitalWrite(B_minus, LOW);
  delay(10);

  // step 1
  digitalWrite(A_plus, LOW);
  digitalWrite(A_minus, HIGH);
  digitalWrite(B_plus, HIGH); 
  digitalWrite(B_minus, LOW); 
  delay(10);

  // step 2
  digitalWrite(A_plus, LOW);
  digitalWrite(A_minus, HIGH);
  digitalWrite(B_plus, LOW); 
  digitalWrite(B_minus, HIGH); 
  delay(10);

  // step 3
  digitalWrite(A_plus, HIGH);
  digitalWrite(A_minus, LOW);
  digitalWrite(B_plus, LOW); 
  digitalWrite(B_minus, HIGH); 
  delay(10);
  */


}
