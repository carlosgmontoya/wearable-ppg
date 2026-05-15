#include <Arduino.h>
#include "sensor_ppg.h"

SensorPPG sensor("MAX30105", 250);

void setup() {
    Serial.begin(115200);
}

void loop() {
    sensor.imprimir();
    delay(2000);
}