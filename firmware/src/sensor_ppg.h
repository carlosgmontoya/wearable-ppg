#pragma once
#include <Arduino.h>

class SensorPPG {
private:
    String nombre;
    int frecuencia;

public:
    SensorPPG(String nombre, int frecuencia);
    void imprimir();
};