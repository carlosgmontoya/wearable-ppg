#pragma once
#include <Arduino.h>
#include "ledIndicador.h"

class LedMorse : public LedIndicador {
    public:
        LedMorse(int pin);
        void punto();
        void raya();
        void SOS();
};