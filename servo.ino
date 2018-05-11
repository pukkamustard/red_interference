#include <Servo.h>

Servo servo;  // create servo object to control a servo

int servoPosition = 0;    

void servoInit() {
  servo.attach(SERVO_PIN); 
  servo.write(servoPosition);
}

int servoGetPosition() {
  return servoPosition;
}

int servoSetPosition(int pos) {
  servo.write(servoPosition);
  servoPosition = pos;
}

/*void loop() {*/
  /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees*/
    /*// in steps of 1 degree*/
    /*myservo.write(pos);              // tell servo to go to position in variable 'pos'*/
    /*delay(15);                       // waits 15ms for the servo to reach the position*/
  /*}*/
  /*for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees*/
    /*myservo.write(pos);              // tell servo to go to position in variable 'pos'*/
    /*delay(15);                       // waits 15ms for the servo to reach the position*/
  /*}*/
/*}*/
