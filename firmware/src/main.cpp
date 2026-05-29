#include <Arduino.h>
#include <Wire.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "MAX30105.h"

#define SERVICE_UUID        "9c4743dd-5fdf-4203-9ecf-c45dab140996"
#define CHARACTERISTIC_UUID "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"
#define BUFFER_SIZE 1

MAX30105 particleSensor;
BLECharacteristic *pCaracteristica;
uint32_t buffer[BUFFER_SIZE];
int bufferIndex = 0;

class MisCallbacks : public BLEServerCallbacks {
    void onDisconnect(BLEServer* pServer) {
        BLEDevice::getAdvertising()->start();
    }
};

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("Iniciando...");
    Wire.begin();
    
    if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
        Serial.println("Sensor no encontrado");
        while(1);
    }
    Serial.println("Sensor encontrado!");

    particleSensor.setup();
    byte ledBrightness = 60;
    byte sampleAverage = 4;
    byte ledMode = 3;  // 1=Red, 2=Red+IR, 3=Red+IR+Green
    int sampleRate = 400;
    int pulseWidth = 411;
    int adcRange = 16384;
    particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange);

    BLEDevice::init("Wearable-PPG");
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MisCallbacks());
    BLEService *pService = pServer->createService(SERVICE_UUID);
    pCaracteristica = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_NOTIFY
    );
    pCaracteristica->addDescriptor(new BLE2902());
    pService->start();
    BLEDevice::getAdvertising()->start();
    Serial.println("Sistema listo");
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    uint32_t valor = random(800, 1200);
    pCaracteristica->setValue((uint8_t*)&valor, sizeof(valor));
    pCaracteristica->notify();
    delay(4);  // 250 Hz
}

/*
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID        "9c4743dd-5fdf-4203-9ecf-c45dab140996"
#define CHARACTERISTIC_UUID "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"

BLECharacteristic *pCaracteristica;

void setup() {
    Serial.begin(115200);
    BLEDevice::init("ESP32-BLE");

    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);
    pCaracteristica = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_NOTIFY
    );
    pCaracteristica->addDescriptor(new BLE2902());
    pService->start();

//    BLEDevice::getAdvertising()->start();
    Serial.println("BLE listo");
    pinMode(LED_BUILTIN, OUTPUT);
};

void loop() {
    // Aquí podrías agregar código para manejar conexiones BLE, enviar datos, etc.
    BLEDevice::getAdvertising()->start();
    if (pCaracteristica != nullptr) {
        int valor = random(800, 1200);
        pCaracteristica->setValue(valor);
        pCaracteristica->notify();
    }

    BLEAddress address = BLEDevice::getAddress();
    Serial.println(address.toString().c_str());

    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    Serial.println("LED toggled");
};
*/

/*
#include <Arduino.h>
#include "ledIndicador.h"

LedIndicador led(LED_BUILTIN);

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
};

void loop() {
    led.encender();
    delay(2000);
    Serial.println(led.estaEncendido());
    led.apagar();
    Serial.println(led.estaEncendido());
    delay(2000);
};
*/

/*
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
*/

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