#pragma once
#include <Arduino.h>
#include "sensor.h"

class SensorRojo : public Sensor {
    public:
        SensorRojo(int id);
        int leer() override;
};