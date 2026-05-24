#include <Arduino.h>

class BufferPPG {
private:
    uint32_t muestras[50];
    int indice = 0;

public:
    BufferPPG();
    void agregar(uint32_t muestra);
    bool estaLleno();
    float promedio();
    void limpiar();

};