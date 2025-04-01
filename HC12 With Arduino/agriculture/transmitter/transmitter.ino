#include <SoftwareSerial.h>

SoftwareSerial HC12(0, 1);  // TX, RX
const int moisturePin = 7;
bool lastMoistureState = LOW;

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  pinMode(moisturePin, INPUT);  // Set moisture sensor pin as input
  Serial.println("Transmitter Ready...");
}

void loop() {
  // if (Serial.available()){
  //   char command = Serial.read();
  // HC12.print(command);
  // Serial.println(command);}

  // **Automatic Water Pump Control Based on Moisture Sensor**
  bool moistureState = digitalRead(moisturePin);  // Read moisture sensor state

  if (moistureState == HIGH ) {  
    HC12.print('O');  // Send command to turn ON pump
    // Serial.println("💦 Soil is DRY → Sent 'O' to turn ON Water Pump");
  } 
  else if (moistureState == LOW ) {  
    HC12.print('F');  // Send command to turn OFF pump
    // Serial.println("✅ Soil is MOIST → Sent 'F' to turn OFF Water Pump");
  }

  lastMoistureState = moistureState;  // Update last state

  delay(2000);  // Check moisture every 2 seconds

  }

