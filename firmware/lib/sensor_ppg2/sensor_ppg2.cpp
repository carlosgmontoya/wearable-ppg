#include "sensor_ppg2.h"

SensorPPG::SensorPPG(int id, int bateria, int frecuencia) : Dispositivo(id, bateria) {
    this-> frecuencia = frecuencia;
};

int SensorPPG::leer() {
    int ale = random(800, 1200);
    return ale;
};