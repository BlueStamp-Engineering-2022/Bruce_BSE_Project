#include <Servo.h>
#include <String.h>
Servo base;
Servo leftArm;
Servo rightArm;
Servo claw;
int clawPos = 90, basePos = 90, lArmPos = 135, rArmPos = 0;
int incomingByte = 0;         
String inputString = "";     
boolean newLineReceived = false;
boolean startBit  = false;  
int num_receive = 0;

void setup() {
  // put your setup code here, to run once:
  claw.write(clawPos);
  claw.attach(9);
  
  base.write(basePos);
  base.attach(3);

  leftArm.write(lArmPos);
  leftArm.attach(5);

  rightArm.write(rArmPos);
  rightArm.attach(6);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available())
  {
    incomingByte = Serial.read();              //One byte by byte, the next sentence is read into a string array to form a completed packet
    if (incomingByte == '%') {
      num_receive = 0;
      startBit = true;
    }
    if (startBit == true) {
      num_receive++;
      inputString += (char) incomingByte;     
    }
    if (startBit == true && incomingByte == '#') {
      newLineReceived = true;
      startBit = false;
    }
    if(num_receive >= 40) {
      num_receive = 0;
      startBit = false;
      newLineReceived = false;
      inputString = "";
    }  
  }

  if(newLineReceived) {
    switch(inputString[1]) {
      case '6':
        for(int i = 2; i <= inputString.length(); i++) {
          clawPos = servoMove(clawPos, false); 
          claw.write(clawPos); 
        } break; //open
      case '5': 
        for(int i = 2; i <= inputString.length(); i++) {
          clawPos = servoMove(clawPos, true); 
          claw.write(clawPos);
        } break; //close
      
      case '4': 
        for(int i = 2; i <= inputString.length(); i++) {
          rArmPos = servoMove(rArmPos, true); 
          rightArm.write(rArmPos);
        } break; //arm up
      case '7': 
        for(int i = 2; i <= inputString.length(); i++) {
          rArmPos = servoMove(rArmPos, false); 
          rightArm.write(rArmPos);
        } break; //arm down
      
      case 'C': 
        for(int i = 2; i <= inputString.length(); i++) {
          basePos = servoMove(basePos, true); 
          base.write(basePos);
        } break; //base right
      case 'B': 
        for(int i = 2; i <= inputString.length(); i++) {
          basePos = servoMove(basePos, false); 
          base.write(basePos);
        } break; //base left
      
      case 'A': 
        for(int i = 2; i <= inputString.length(); i++) {
          lArmPos = servoMove(lArmPos, true); 
          leftArm.write(lArmPos);
        } break; //arm forward
      case 'D': 
        for(int i = 2; i <= inputString.length(); i++) {
          lArmPos = servoMove(lArmPos, false); 
          leftArm.write(lArmPos);
        } break; //arm back
      
      default: break;
    }
    Serial.println(inputString);
    inputString = "";   // clear the string
    newLineReceived = false;
  }
  
}

int servoMove(int servoPos, boolean tag) {
  if(tag) {
    servoPos = servoPos - 3;
    if(servoPos <= 0) {
      servoPos = 0;
    }
    Serial.println(servoPos);
  }
  else {
    servoPos = servoPos + 3;
    if(servoPos >= 180) {
      servoPos = 180;
    }
    Serial.println(servoPos);
  }
  Serial.println(basePos);
  return servoPos;
}
