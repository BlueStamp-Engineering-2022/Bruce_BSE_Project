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
  //intialization, booting to the initial position and attaching the servos
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
  //reads the information sent over
  while (Serial.available())
  {
    incomingByte = Serial.read();              
    if (incomingByte == '%') { //the commands all start with '%', thus the program knows to start reading when it starts with this
      num_receive = 0;
      startBit = true; //start reading through the byte
    }
    if (startBit == true) {
      num_receive++;
      inputString += (char) incomingByte; //turning the incomining byte into a string by adding the characters one by one     
    }
    if (startBit == true && incomingByte == '#') { //the end of each byte is a '#', thus the program knows to terminiate appending if that is the received character
      newLineReceived = true; //a new command has been received
      startBit = false; //stop reading
    }
    if(num_receive >= 40) { //resets the string if the recieved byte is too long
      num_receive = 0;
      startBit = false;
      newLineReceived = false;
      inputString = "";
    }  
  }

  if(newLineReceived) { //if a full command has been sent
    switch(inputString[1]) { //the second character of each command signifies what to do
    //loops are to accomodate for long presses
    //essentially, normal commands are in the form "%A#" (example), but by adding more letters, such as "%AAA#," commands can be chained together by a for loop
      case '6':
        for(int i = 2; i <= inputString.length(); i++) {
          clawPos = servoMove(clawPos, false); 
          claw.write(clawPos); 
        } break; //open claw
      case '5': 
        for(int i = 2; i <= inputString.length(); i++) {
          clawPos = servoMove(clawPos, true); 
          claw.write(clawPos);
        } break; //close claw
      
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
    inputString = "";  // clear the string
    newLineReceived = false; //the command has been used
  }
  
}

//universal movement function
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
