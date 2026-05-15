#include "servidor_ble.h"

class CallbacksBLE : public BLEServerCallbacks {
    ServidorBLE *servidor;
public:
    CallbacksBLE(ServidorBLE *srv) { servidor = srv; }
    
    void onConnect(BLEServer* pServer) {
        servidor->setConectado(true);
    }
    void onDisconnect(BLEServer* pServer) {
        servidor->setConectado(false);
        pServer->startAdvertising();
    }
};

ServidorBLE::ServidorBLE() {
    conectado = false;
}

void ServidorBLE::begin(String nombre, String serviceUUID, String caracteristicaUUID) {
    BLEDevice::init(nombre.c_str());
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new CallbacksBLE(this));

    BLEService *pService = pServer->createService(serviceUUID.c_str());
    pCaracteristica = pService->createCharacteristic(
        caracteristicaUUID.c_str(),
        BLECharacteristic::PROPERTY_NOTIFY
    );
    pCaracteristica->addDescriptor(new BLE2902());
    pService->start();

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(serviceUUID.c_str());
    pAdvertising->start();
}

void ServidorBLE::enviar(uint8_t *datos, size_t longitud) {
    pCaracteristica->setValue(datos, longitud);
    pCaracteristica->notify();
}

bool ServidorBLE::estaConectado() {
    return conectado;
}

void ServidorBLE::setConectado(bool estado) {
    conectado = estado;
}
