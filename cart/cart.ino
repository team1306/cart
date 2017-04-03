#include <Adafruit_TiCoServo.h>

void setup() {
  Adafruit_TiCoServo dart;
  dart.attach(9);

  Serial.begin(9600);
  Serial.println("Cart Starting!");
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();

    if (!isNan(ch)) {
      dart.write(ch);
    }
  }
}
