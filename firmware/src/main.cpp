/* POO Ejemplo 1 de uso de clases en Arduino
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
*/

// POO Ejemplo 2 de uso de clases en Arduino

#include <Arduino.h>
#include "buffer_ppg.h"

BufferPPG buffer;

void setup() {
    Serial.begin(115200);
};


void loop() {
    for (int i = 0; i < 50; i++) {
        buffer.agregar(i*10);
    }

    Serial.println("¿Buffer lleno? " + String(buffer.estaLleno()));
    Serial.println("Promedio: " + String(buffer.promedio()));

    buffer.limpiar();
    Serial.println("¿Buffer lleno después de limpiar? " + String(buffer.estaLleno()));
    delay(2000);

};