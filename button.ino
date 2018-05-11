#define DEBUG_PIN 0
#define BUTTON_PIN 5
#define SERVO_PIN 4

bool volatile triggered = false;

void setup() {
  Serial.begin(115200);
  Serial.print("\n\nRESET\n");
  pinMode(DEBUG_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onPress, RISING);

  // initialize networking
  netInit();

  // init servo
  servoInit();
}

void onPress() {
  triggered = triggered || true; 
}

void loop() {
  // network loop
  netLoop();


  int buttonValue = digitalRead(BUTTON_PIN);
  /*Serial.print(String(buttonValue));*/

  if (triggered) {
    Serial.print("Boom!\n");
    publish("Boom!");

    servoSetPosition(180);
    digitalWrite(DEBUG_PIN, HIGH);
    delay(1500);
    servoSetPosition(0);
    digitalWrite(DEBUG_PIN, LOW);
    triggered = false;
  }
  delay(20);
}
