
#include <Servo.h>
Servo base;
Servo leftArm;
Servo rightArm;
Servo claw;
int clawPos = 90, basePos = 90, lArmPos = 135, rArmPos = 0;
int rxPos, ryPos, lxPos, lyPos, rkPos, lkPos;
int trackClaw, trackBase, tracklArm, trackrArm;
const int rk = 11;
const int lk = 8;
const int rx = A2;
const int ry = A5;
const int lx = A3;
const int ly = A1;

void setup() {
  //initialization
  pinMode(rk, INPUT_PULLUP);
  pinMode(lk, INPUT_PULLUP);
  
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
  //get values of joystick coordinates every loop
  
  rxPos = analogRead(rx);
  ryPos = analogRead(ry);
  lxPos = analogRead(lx);
  lyPos = analogRead(ly);
  rkPos = digitalRead(rk);
  lkPos = digitalRead(lk);

  //right stick - claw and right arm
  servoMove(claw, clawPos, rxPos, rkPos);
  servoMove(rightArm, rArmPos, ryPos, rkPos);
  
  //left stick - base and left arm
  servoMove(base, basePos, lyPos, lkPos);
  servoMove(leftArm, lArmPos, lxPos, lkPos);

  
}

//universal movement function
void servoMove(Servo myservo, int servoPos, int stickPos, int keyPos) {
  //only move if stick is being held down
  if(keyPos == 0) {
    servoPos = map(stickPos, 0, 1023, 0, 180); //map joystick position to servo position
    myservo.write(servoPos);
  }
}
