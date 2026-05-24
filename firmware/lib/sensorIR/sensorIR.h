#pragma once
#include <Arduino.h>
#include "sensor.h"

class SensorIR : public Sensor {
    public:
        SensorIR(int id);
        int leer() override;
};