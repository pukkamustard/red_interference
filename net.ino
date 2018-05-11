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
const char ssid[] = "MuDA";
const char pass[] = "MPRERWKK7WRME";

WiFiClientSecure net;
MQTTClient client;

void netInit() {
  WiFi.begin(ssid, pass);
  client.begin("broker.shiftr.io", 8883, net);   
  client.onMessage(messageReceived);
}

void netConnect() {
  Serial.print("wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("ok\n");

  Serial.print("mqtt...");
  while (!client.connect("red_button", "workshoppers", "mudapowa")) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("ok\n");

  /*client.subscribe("/temple");*/
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
  Serial.println("incoming: " + topic + " - " + payload);
}
