String inString = "";    // string to hold input

int baseServoAngle, shoulderServoAngle, elbowServoAngle, endEffectorServoAngle;

void setup() {
  //Initialize The Serial Port
  Serial.begin(9600);
  Serial.println("Enter parameters: baseServoAngle,shoulderServoAngle,elbowServoAngle,endEffectorServoAngle");
  Serial.println();    
}

void loop() {
  readValuesFromSerial();
}


void readValuesFromSerial(){
  // Read serial input:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    // if you get a newline, print the string,
    // then the string's value:    
    if (inChar == '\n') {
      /*
      strtok() is destructive in its parsing (ie it writes to the string you're parsing while you're parsing it), so it takes a char* as a parameter, not a const char*.
      c_str() returns a const char* since it does not expect you to write to the content of the buffer it returns.
      A way to do the parsing is to strdup() (ie copy) the buffer you want to work and parse that
      */  
      char* buf = strdup(inString.c_str());
      String tok;

      tok = strtok(buf, ",");
      baseServoAngle = tok.toInt();
      Serial.print("baseServoAngle: ");
      Serial.println(baseServoAngle);
  
      tok = strtok(NULL, ",");
      shoulderServoAngle = tok.toInt();
      Serial.print("shoulderServoAngle: ");
      Serial.println(shoulderServoAngle);
      
      tok = strtok(NULL, ",");
      elbowServoAngle = tok.toInt();
      Serial.print("elbowServoAngle: ");
      Serial.println(elbowServoAngle);
      
      tok = strtok(NULL, ",");
      endEffectorServoAngle = tok.toInt();
      Serial.print("endEffectorServoAngle: ");
      Serial.println(endEffectorServoAngle);
      
      /*
      char* tok;
      char* buf = strdup(inString.c_str());
      tok = strtok(buf, " ");
      while (tok != NULL) {
        Serial.println(tok);
        tok = strtok(NULL, " ");
      }  
      */    
      //clear inString for next loop
      inString = ""; 
    
    } else {
      inString += inChar;
    }
  }
}

