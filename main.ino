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

  digitalWrite(DEBUG_PIN, LOW);
}

void onPress() {
  triggered = true; 
}

void loop() {
  // network loop
  netLoop();

  if (triggered) {
    digitalWrite(DEBUG_PIN, HIGH);

    Project project = randomProject();

    // Send the interference
    publish(project.name);

    // point towards project
    servoSetPosition(project.angle);

    delay(500);
    digitalWrite(DEBUG_PIN, LOW);
    triggered = false;
  }
  delay(50);
}
