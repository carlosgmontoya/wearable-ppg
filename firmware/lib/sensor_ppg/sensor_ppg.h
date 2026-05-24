#pragma once
#include <Arduino.h>
#include <Wire.h>
#include "MAX30105.h"

class SensorPPG {
private:
    MAX30105 sensor;
    int frecuencia;

public:
    SensorPPG(int frecuencia);
    bool begin();
    uint32_t leerIR();
    uint32_t leerRojo();
    uint32_t leerVerde();
};