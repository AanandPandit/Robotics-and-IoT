#include <SoftwareSerial.h>

SoftwareSerial HC12(0, 1); 

void setup() {


  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
  HC12.println("Hello from Arduino 1");
  Serial.println("Sent: Hello from Arduino 1");
  delay(2000);
}
