// This example uses an Adafruit Huzzah ESP8266
// to connect to shiftr.io.
//
// You can check on your device after a successful
// connection here: https://shiftr.io/try.
//
// by Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <ESP8266WiFi.h>
#include <MQTTClient.h>

// WiFi Settings
const char ssid[] = "blup";
const char pass[] = "blupblup";

WiFiClientSecure net;
MQTTClient client;

void netInit() {
  WiFi.begin(ssid, pass);
  client.begin("broker.shiftr.io", 8883, net);   
  client.onMessage(messageReceived);
}

void netConnect() {
  Serial.print("wifi...");
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.disconnect(true);
    delay(500);
    WiFi.begin(ssid, pass);
  }
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(DEBUG_PIN, HIGH);
    delay(100);
    digitalWrite(DEBUG_PIN, LOW);
    delay(100);
  }
  Serial.print("ok\n");

  Serial.print("mqtt ");
  digitalWrite(DEBUG_PIN, HIGH);
  bool connected = false;
  int i = 0;
  while (!connected && i <= 5) {
    connected = client.connect("red_button", "workshoppers", "mudapowa");
    i = i + 1;
    Serial.print("+");
    digitalWrite(DEBUG_PIN, LOW);
    delay(500);
  }

  if (connected){
    Serial.print(" ok\n");
  } else {
    Serial.print(" not connected!\n");
  }

  client.subscribe("/red_button");
}

bool publish(String msg){
  client.publish("/red_button", msg);
}

void netLoop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    netConnect();
  }
}

void messageReceived(String &topic, String &payload) {
  if (payload == "redbutton"){
    triggered = true;
  }
}
