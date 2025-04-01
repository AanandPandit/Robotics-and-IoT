#include <SoftwareSerial.h>

SoftwareSerial HC12(0, 1);

void setup() {


  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
  if (HC12.available()) {
    String receivedData = HC12.readString();
    Serial.print("BReceived: ");
    Serial.println(receivedData);
  }
}
