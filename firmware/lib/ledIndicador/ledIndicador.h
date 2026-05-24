#pragma once
#include <Arduino.h>

class LedIndicador {
    private:
        int pin;
        bool encendido;

    public:
        LedIndicador(int pin);
        void encender();
        void apagar();
        bool estaEncendido();

};