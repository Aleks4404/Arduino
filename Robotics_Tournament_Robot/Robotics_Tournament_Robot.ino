//color sensor
#define S0 9
#define S1 10
#define S2 11
#define S3 12
#define sensorOut 13

//IR sensors
#define rightIR A0
#define leftIR A1
//bumper
#define rightBumper A2
#define leftBumper A3

// motor one
#define enA 6
#define in1 7
#define in2 8
// motor two
#define enB 3
#define in3 2
#define in4 4

double pidController(double left, double right);
void moveForwardRight(double input);
void moveForwardRight(double input);
void moveBack(int time);
void stopMotor(int time);
void moveStright();
void turnLeft(int time);
void turnRight(int time);
int getColor();

int frequency = 0;
int red = 0; //color sensor
int green = 0;
int blue = 0;
int lastColor = 0;


double valueIRright_voltage = 0;
double valueIRleft_voltage = 0;
double setPoint = 0;
double e_prev = 0;
double e_int = 0;
double Kp = 44; //44
double Kd = 22; //22
double Ki = 0.0005; //0.0005
int max_speed = 255; //220

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(rightIR, INPUT); //declare pin A0 as input for right sensor
  pinMode(leftIR, INPUT); //declare pin A1 as input for left sensor

  //color sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // logging
  Serial.begin(9600); //set the baud rate of the serial monitor

}


void loop()
{
  //  int color = getColor();
  //  Serial.println(color);
  //    if (color == 1)   {
  //      Serial.println("Red");
  //    }
  //    else if (color == 2)   {
  //      Serial.println("Green");
  //    }
  //    else if (color == 3)   {
  //      Serial.println("Blue");
  //    }
  //      else if (color == 4)   {
  //      Serial.println("Yellow");
  //    }
  //      else if (color == 0)   {
  //      Serial.println("Black&White");
  //    }

  valueIRleft_voltage = analogRead(leftIR) * 0.00488; //convert analog value to voltage
  valueIRright_voltage = analogRead(rightIR) * 0.00488; //convert analog value to voltage

    double blaBla = pidController(valueIRleft_voltage, valueIRright_voltage);
    if (blaBla < 0) {
      moveForwardRight(blaBla);
    }
    else {
    moveForwardLeft(blaBla);
  
    }

//  int rightBumperStatus = analogRead(rightBumper); //800 ON
//  Serial.println(rightBumperStatus);
//
//  int leftBumperStatus = analogRead(leftBumper);
//  Serial.println(leftBumperStatus);
//
//  moveStright();
//  if (rightBumperStatus > 900) {
//    //    stopMotor(100);
//    //    moveBack(100);
//    turnLeft(500);
//  }
//
//  else if (leftBumperStatus > 900) {
//    //    stopMotor(100);
//    //    moveBack(100);
//    turnRight(500);
//  }


  //delay(10);



}

double pidController(double left, double right) {
  double r = (-1) * left + right;
  double error = setPoint - r;
  e_int = e_int + error;
  double e_diff = (error - e_prev);
  double pid = Kp * error + Ki * e_int + Kd * e_diff;
  e_prev = error;
  return pid;
}

void moveForwardRight(double input) {
  //input will be minus.
  int PWM_right = int(max_speed + input * 20); //20
  if (PWM_right < 80) {
    PWM_right = 0;
  }
  analogWrite(enA, PWM_right);  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  int PWM_left = int(max_speed + input * 4);
  if (PWM_left > 255) {
    PWM_left = 255;
  }

  analogWrite(enB, PWM_left);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);

  //  Serial.print("PWM_right: ");
  //  Serial.print(PWM_right); //display analog value in serial monitor
  //  Serial.print("\t");
  //  Serial.print("PWM_left: ");
  //  Serial.println(PWM_left); //display value of voltage in serial monitor
}


void moveForwardLeft(double input) {
  // input will be plus
  int PWM_right = int(max_speed - input * 4); //3
  if (PWM_right > 255) {
    PWM_right = 255;
  }
  analogWrite(enA, PWM_right);  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  int PWM_left = int(max_speed  - input * 20);
  if (PWM_left < 80) {
    PWM_left = 0;
  }
  analogWrite(enB, PWM_left);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);

  //  Serial.print("PWM_right: ");
  //  Serial.print(PWM_right); //display analog value in serial monitor
  //  Serial.print("\t");
  //  Serial.print("PWM_left: ");
  //  Serial.println(PWM_left); //display value of voltage in serial monitor

}

int getColor() {
  int colorArray[3]; // red, green, blue
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  colorArray[0] = frequency;
  // Printing the value on the serial monitor
  //delay(10);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  colorArray[1] = frequency;
  //delay(10);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  colorArray[2] = frequency;
  //delay(10);

  if ((colorArray[0] >= 24 & colorArray[0] <= 34) & (colorArray[1] >= 25 & colorArray[1] <= 29) & (colorArray[2] >= 33 & colorArray[2] <= 37)) {
    return 2;
  }
  else if ((colorArray[0] >= 20 & colorArray[0] <= 25) & (colorArray[1] >= 45 & colorArray[1] <= 52) & (colorArray[2] >= 40 & colorArray[2] <= 45)) {
    return 1;
  }
  else if ((colorArray[0] >= 40 & colorArray[0] <= 47) & (colorArray[1] >= 40 & colorArray[1] <= 47) & (colorArray[2] >= 25 & colorArray[2] <= 33)) {
    return 3;
  }
  else if ((colorArray[0] >= 10 & colorArray[0] <= 18) & (colorArray[1] >= 15 & colorArray[1] <= 23) & (colorArray[2] >= 25 & colorArray[2] <= 32)) {
    return 4;
  }
  else {
    return 0;
  }
}


void turnRight(int time) {
  analogWrite(enA, 150);  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enB, 150);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  delay(time);

}
void moveStright() {
  analogWrite(enA, 180);  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enB, 180);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);


}
void turnLeft(int time) {
  analogWrite(enA, 150);  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enB, 150);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  delay(time);

}
void stopMotor(int time) {
  analogWrite(enA, 0);  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  analogWrite(enB, 0);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
  delay(time);
}
void moveBack(int time) {
  analogWrite(enA, 180);  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enB, 180);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  delay(time);

}

