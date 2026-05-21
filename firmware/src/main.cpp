#include <Arduino.h>
#include "sensorRojo.h"

SensorRojo sensoriux(2349);

void setup() {
    Serial.begin(115200);
};

void loop() {
    Serial.println(sensoriux.leer());
    delay(2000);
};

/*
#include <Arduino.h>
#include "sensor.h"

Sensor sensor(2348);

void setup() {
    Serial.begin(115200);
};

void loop() {
    Serial.println(sensor.leer());
    sensor.imprimirId();
    delay(2000);
};
*/

/*
#include <Arduino.h>
#include "sensor_ppg2.h"

SensorPPG sensor(2347, 50, 128);

void setup() {
    Serial.begin(115200);
};

void loop() {
    sensor.info();
    Serial.println(sensor.leer());
    delay(2000);
};
*/

/*
#include <Arduino.h>
#include "dispositivo.h"

Dispositivo dispositivo1(2345, 30);
Dispositivo dispositivo2(2346, 20);

void setup(){
    Serial.begin(115200);
};

void loop(){
    dispositivo1.info();
    dispositivo2.info();
    delay(2000);
};
*/

/*#include <Arduino.h>
#include "sensor_ppg.h"
#include "buffer_ppg.h"
#include "servidor_ble.h"

#define SERVICE_UUID        "9c4743dd-5fdf-4203-9ecf-c45dab140996"
#define CHARACTERISTIC_UUID "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"

SensorPPG sensor(250);
BufferPPG buffer;
ServidorBLE servidor;

void setup() {
    Serial.begin(115200);
    
    if (!sensor.begin()) {
        Serial.println("Sensor no encontrado");
        while(1);
    }
    
    servidor.begin("Wearable-PPG", SERVICE_UUID, CHARACTERISTIC_UUID);
    Serial.println("Sistema iniciado");
}

void loop() {
    buffer.agregar(sensor.leerIR());
    
    if (buffer.estaLleno()) {
        if (servidor.estaConectado()) {
            servidor.enviar((uint8_t*)&buffer, sizeof(buffer));
            Serial.println("Bloque enviado");
        }
        buffer.limpiar();
    }
}

*/

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
/*
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
*/

// POO Ejemplo 3 de uso de clases en Arduino
/*
#include <Arduino.h>
#include "dispositivo_ble.h"

DispositivoBLE dispositivo("Wearable-PPG");

void setup() {
    Serial.begin(115200);
};

void loop() {

    dispositivo.conectar();
    delay(2000);
    Serial.println("¿Dispositivo conectado? " + String(dispositivo.estaConectado()));
    delay(2000);
    dispositivo.desconectar();
    delay(2000);
    Serial.println("¿Dispositivo conectado después de desconectar? " + String(dispositivo.estaConectado()));
    delay(2000);

};

*/