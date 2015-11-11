#include <EngduinoLEDs.h>
#include <EngduinoLight.h>

void setup() {
  // put your setup code here, to run once:
  EngduinoLEDs.begin();
  EngduinoLight.begin();
}

void loop() {
  int v = EngduinoLight.lightLevel();
  Serial.println(v);
  delay(100);
}

