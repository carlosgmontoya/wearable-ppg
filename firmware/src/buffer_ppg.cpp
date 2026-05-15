#include "buffer_ppg.h"

BufferPPG::BufferPPG() {
    indice = 0;
};

void BufferPPG::agregar(uint32_t muestra) {
    muestras[indice] = muestra;
    indice = indice +1;
};

bool BufferPPG::estaLleno() {
    if(indice>=50){
        return true;
    } else {
        return false;
    }
    };

float BufferPPG::promedio() {
    uint32_t suma = 0;
    for (int i = 0; i < indice; i++) {
        suma += muestras[i];
    }
    return (float)suma / indice;
};

void BufferPPG::limpiar() {
    for (int i = 0; i < indice; i++) {
        muestras[i] = 0;
    }
    indice = 0;

};