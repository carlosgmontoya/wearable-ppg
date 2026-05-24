#pragma once
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

class ServidorBLE {
private:
    BLECharacteristic *pCaracteristica;
    bool conectado;

public:
    ServidorBLE();
    void begin(String nombre, String serviceUUID, String caracteristicaUUID);
    void enviar(uint8_t *datos, size_t longitud);
    bool estaConectado();
    void setConectado(bool estado);
};