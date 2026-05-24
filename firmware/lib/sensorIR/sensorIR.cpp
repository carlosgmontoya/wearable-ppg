
#include "sensorIR.h"

SensorIR::SensorIR(int id) : Sensor(id) {

};

int SensorIR::leer() {
    return random(50000, 65000);
};