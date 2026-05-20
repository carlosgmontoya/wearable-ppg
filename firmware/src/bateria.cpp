#include "bateria.h"

Bateria::Bateria(String nombre) {
    this->nombre = nombre;
};

void Bateria::descargar(int cantidad) {
    nivel = nivel - cantidad;
};

int Bateria::getNivel() {
    return nivel;
};

bool Bateria::estaLow() {
    if(nivel < 20) {
        return true;
    }
    return false;
};

void Bateria::imprimir() {
    Serial.println("Nombre: " + nombre + ", Nivel: "+String(nivel));
};
