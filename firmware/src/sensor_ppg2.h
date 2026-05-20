#pragma once
#include "dispositivo.h"

class SensorPPG:public Dispositivo {
    private:
        int frecuencia;

    public:
        SensorPPG(int id, int bateria, int frecuencia);
        int leer();
};