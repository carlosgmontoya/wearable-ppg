#include "sensor_ppg.h"

SensorPPG::SensorPPG(String nombre, int frecuencia) {
    this->nombre = nombre;
    this->frecuencia = frecuencia;
}

void SensorPPG::imprimir() {
    Serial.print("Sensor: ");
    Serial.print(nombre);
    Serial.print(", Frecuencia: ");
    Serial.print(frecuencia);
    Serial.println(" Hz");
}
