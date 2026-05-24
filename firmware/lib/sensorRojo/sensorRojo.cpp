#include "sensorRojo.h"

SensorRojo::SensorRojo(int id) : Sensor(id) {

};

int SensorRojo::leer() {
    return random(40000, 55000);
};