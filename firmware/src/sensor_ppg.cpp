#include "sensor_ppg.h"

SensorPPG::SensorPPG(int frecuencia) {
    this->frecuencia = frecuencia;
};

bool SensorPPG::begin() {
    if(!sensor.begin(Wire, I2C_SPEED_FAST)) {
        return false;
    }

    sensor.setup();
    return true;

};

uint32_t SensorPPG::leerIR() {
    return sensor.getIR();
};

uint32_t SensorPPG::leerRojo() {
    return sensor.getRed();
};

uint32_t SensorPPG::leerVerde() {
    return sensor.getGreen();
};
