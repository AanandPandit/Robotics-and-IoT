#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial HC12(0, 1);  // TX, RX
Servo myServo;

const int relayPin = 13;
const int servoPin = 5;

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  
  pinMode(relayPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(90); // Initial servo position at 90 degrees

  // Serial.println("Receiver Ready...");
}

void loop() {
  if (HC12.available()) {
    char receivedCommand = HC12.read();
    // Serial.print("Received: ");
    // Serial.println(receivedCommand);

    switch (receivedCommand) {
      case 'L': 
        myServo.attach(servoPin); myServo.write(0); delay(200); myServo.detach();// Rotate servo left
        // Serial.println("✅ Servo moved to LEFT (25°)");
        break;

      case 'R': 
        myServo.attach(servoPin); myServo.write(180); delay(200); myServo.detach(); // Rotate servo right
        // Serial.println("✅ Servo moved to RIGHT (165°)");
        break;

      case 'C': 
        myServo.attach(servoPin); myServo.write(90); delay(200); myServo.detach(); // Rotate servo right
        // Serial.println("✅ Servo moved to CENTER (90°)");
        break;

      case 'O': 
        digitalWrite(relayPin, HIGH); // WATER PUMP ON
        // Serial.println("✅ WATER PUMP turned ON");
        break;

      case 'F': 
        digitalWrite(relayPin, LOW); // WATER PUMP OFF
        // Serial.println("✅ WATER PUMP turned OFF");
        break;

    }
  }
}
