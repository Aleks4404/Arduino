#define rightIR A0
#define leftIR A1

// motor one
#define enA 6
#define in1 7
#define in2 8
// motor two
#define enB 3
#define in3 2
#define in4 4

/*
// connect motor controller pins to Arduino digital pins
// motor one
int enA = 6;
int in1 = 7;
int in2 = 8;
// motor two
int enB = 3;
int in3 = 2;
int in4 = 4;
*/

void moveStright(int PWM, int time);

double valueIRright = 0;
double valueIRleft = 0;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(rightIR,INPUT); //declare pin A0 as input for right sensor
  pinMode(leftIR,INPUT); //declare pin A1 as input for left sensor
  
  // logging
  Serial.begin(9600); //set the baud rate of the serial monitor
  
}

 
void loop()
{
  valueIRright = analogRead(rightIR); 
  valueIRleft = analogRead(leftIR);
  double valueIRright_voltage = valueIRright*0.00488; //convert analog value to voltage
  double valueIRleft_voltage = valueIRleft*0.00488; //convert analog value to voltage

  Serial.print("Right Sensor Voltage: ");
  Serial.print(valueIRright_voltage); //display analog value in serial monitor
  Serial.print("\t");
  Serial.print("Left Sensor Voltage: ");
  Serial.println(valueIRleft_voltage); //display value of voltage in serial monitor
  delay(200);
  
//  moveStright(255, 5000);
//  moveStright(200, 5000);
//  moveStright(130, 5000);
}


void moveStright(int PWM, int time)
{
  analogWrite(enA, PWM);  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enB, PWM);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  delay(time);
}
