#include <Servo.h>

Servo servo;  // create servo object to control a servo

int servoPosition = 0;    

int servoSetPosition(int pos) {
  servo.write(servoPosition);
  servoPosition = pos;
}

void servoInit() {
  servo.attach(SERVO_PIN); 
  servoSetPosition(0);
}
