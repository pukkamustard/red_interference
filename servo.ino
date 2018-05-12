#include <Servo.h>

Servo servo;  // create servo object to control a servo

int servoPosition = 0;    

int servoSetPosition(int pos) {

  servo.write(0);
  delay(500);
  servo.write(180);
  delay(500);
  servo.write(0);
  delay(500);

  for (int i = 0; i <= pos; i = i + 1){
    servoPosition = i;
    servo.write(i);
    delay(5);
  }
  servoPosition = pos;
}

void servoInit() {
  servo.attach(SERVO_PIN); 
  servoSetPosition(0);
}
