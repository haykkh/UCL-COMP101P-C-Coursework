#include <EngduinoLEDs.h>
#include <EngduinoButton.h>
#include <EngduinoThermistor.h>
#include <EngduinoLight.h>

void setup() {
  // put your setup code here, to run once:
  EngduinoLEDs.begin();
  EngduinoLight.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = EngduinoLight.lightLevel();

  Serial.println(v);
  if (v > 900) {
    EngduinoLEDs.setAll(RED);
  } else {
    if (v > 700) {
      EngduinoLEDs.setLED(0, 13, 0, 3);
      EngduinoLEDs.setLED(1, 13, 0, 3);
      EngduinoLEDs.setLED(2, 13, 0, 3);
      EngduinoLEDs.setLED(3, 13, 0, 3);
      EngduinoLEDs.setLED(4, 13, 0, 3);
      EngduinoLEDs.setLED(5, 13, 0, 3);
      EngduinoLEDs.setLED(6, 13, 0, 3);
      EngduinoLEDs.setLED(10, 13, 0, 3);
      EngduinoLEDs.setLED(11, 13, 0, 3);
      EngduinoLEDs.setLED(12, 13, 0, 3);
      EngduinoLEDs.setLED(13, 13, 0, 3);
      EngduinoLEDs.setLED(14, 13, 0, 3);
      EngduinoLEDs.setLED(15, 13, 0, 3);
    } else {
      if (v > 500) {
        EngduinoLEDs.setLED(0, 10, 0, 6);
        EngduinoLEDs.setLED(1, 10, 0, 6);
        EngduinoLEDs.setLED(2, 10, 0, 6);
        EngduinoLEDs.setLED(3, 10, 0, 6);
        EngduinoLEDs.setLED(11, 10, 0, 6);
        EngduinoLEDs.setLED(12, 10, 0, 6);
        EngduinoLEDs.setLED(13, 10, 0, 6);
        EngduinoLEDs.setLED(14, 10, 0, 6);
        EngduinoLEDs.setLED(15, 10, 0, 6);
      } else {
        if (v > 300) {
          EngduinoLEDs.setLED(0, 7, 0, 9);
          EngduinoLEDs.setLED(1, 7, 0, 9);
          EngduinoLEDs.setLED(2, 7, 0, 9);
          EngduinoLEDs.setLED(12, 7, 0, 9);
          EngduinoLEDs.setLED(13, 7, 0, 9);
          EngduinoLEDs.setLED(14, 7, 0, 9);
          EngduinoLEDs.setLED(15, 7, 0, 9);
        } else {
          if (v > 100 ) {
            EngduinoLEDs.setLED(0, 3, 0, 13);
            EngduinoLEDs.setLED(13, 3, 0, 13);
            EngduinoLEDs.setLED(14, 3, 0, 13);
            EngduinoLEDs.setLED(15, 3, 0, 13);
          } else {
            EngduinoLEDs.setAll(OFF);
          }
        }
      }
    }
  }
  delay(100);
}
