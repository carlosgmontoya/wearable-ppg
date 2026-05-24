#include "sensor.h"

Sensor::Sensor(int id) {
    this->id = id;
};

int Sensor::leer() {
    return 0;
};

void Sensor::imprimirId() {
    Serial.println("El id es " +String(id));
};