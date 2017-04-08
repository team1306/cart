#include <Adafruit_TiCoServo.h>

Adafruit_TiCoServo victor;

void setup() {
  pinMode(9, OUTPUT);
  victor.attach(9, 1500, 2000);

  Serial.begin(9600);
  Serial.println("Cart Starting!");
}

void loop() {
    victor.write(0);
    Serial.println("Set 0");
    delay(1000);
    victor.write(180);
    Serial.println("Set 180");
    delay(1000);
  if (Serial.available()) {
    char ch = Serial.read();

    if (!isnan(ch)) {
      if (ch == 1) {
        victor.write(0);
      }
      else if (ch == 2) {
        victor.write(90);
      }
      else if (ch == "3") {
        Serial.print("Setting 180 ");
        victor.write(180);
      }
      //victor.write(ch);
      Serial.println(ch);
    }
  }
}
