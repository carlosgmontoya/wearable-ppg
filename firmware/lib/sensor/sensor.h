#pragma once
#include <Arduino.h>

class Sensor {
    protected:
        int id;

    public:
        Sensor(int id);
        virtual int leer();
        void imprimirId();
};