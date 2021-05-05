#include <WebUSB.h>

WebUSB WebUSBSerial(1 /* https:// */, "localhost:3000/webUSB/console/");

#undef Serial
#define Serial WebUSBSerial

const int motorLPin = 10;
const int motorRPin = 9;
      int pulseTime =  300;

      int intensity =  127;

void setup() {
  while (!Serial) {
    ;
  }
  Serial.begin(9600);
  Serial.write("Sketch begins.\r\n> ");
  Serial.flush();
  pinMode(motorLPin, OUTPUT);
  pinMode(motorRPin, OUTPUT);
}

void loop() {
  if (Serial && Serial.available()) {
    int byte = Serial.read();
    Serial.write(byte);
    if (byte == 'E') {
      buzz();
      
    }
    Serial.write("\r\n> ");
    Serial.flush();
  }
}

void buzz() {
  Serial.println("Buzz!");
  Serial.write("\r\nTurning motor on.");
  digitalWrite(motorLPin, intensity);
  delay(pulseTime);
  Serial.write("\r\nTurning motor off.");
  digitalWrite(motorLPin, LOW);
}
