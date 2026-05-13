#include <Arduino.h>
#include <Wire.h>
#include "MAX30105.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

MAX30105 particleSensor;

#define SERVICE_UUID        "9c4743dd-5fdf-4203-9ecf-c45dab140996"
#define CHARACTERISTIC_UUID "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;

#define BUFFER_SIZE 250
uint32_t buffer[BUFFER_SIZE];
int bufferIndex = 0;

class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        deviceConnected = true;
        Serial.println("Cliente conectado");
    }
    void onDisconnect(BLEServer* pServer) {
        deviceConnected = false;
        Serial.println("Cliente desconectado");
        pServer->startAdvertising();
    }
};

void setup() {
    Serial.begin(115200);
    Wire.begin();

    if (particleSensor.begin(Wire, I2C_SPEED_FAST) == false) {
        Serial.println("MAX30105 no encontrado");
        while (1);
    }
    particleSensor.setup();

    BLEDevice::init("Wearable-PPG");
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    BLEService *pService = pServer->createService(SERVICE_UUID);
    pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_NOTIFY
    );
    pCharacteristic->addDescriptor(new BLE2902());
    pService->start();

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->start();
}

void loop() {
    buffer[bufferIndex++] = particleSensor.getIR();

    if (bufferIndex >= BUFFER_SIZE) {
        if (deviceConnected) {
            pCharacteristic->setValue((uint8_t*)buffer, sizeof(buffer));
            pCharacteristic->notify();
            Serial.println("Bloque enviado");
        } else {
            Serial.println("BLE activo, sin cliente...");
        }
        bufferIndex = 0;
    }
}