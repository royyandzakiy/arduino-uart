#include <SoftwareSerial.h>

SoftwareSerial EspSerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  EspSerial.begin(115200);
  Serial.println("Setup done.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    String str = Serial.readStringUntil('\n');
    Serial.println(str);
    EspSerial.println(str);
    delay(10);
  }
  if(EspSerial.available()) {
    String str = EspSerial.readStringUntil('\n');
    Serial.println(str);
    delay(10);
  }
}
