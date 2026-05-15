#include <dispositivo_ble.h>

DispositivoBLE::DispositivoBLE(String nombre){
    this->nombre = nombre;
}
    
void DispositivoBLE::conectar(){
    conectado = true;
    Serial.println("Conectado a " + nombre);
};

void DispositivoBLE::desconectar(){
    conectado = false;
    Serial.println("Desconectado de " + nombre);
};

bool DispositivoBLE::estaConectado(){
    return conectado;
};