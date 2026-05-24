#include "ledMorse.h"

LedMorse::LedMorse(int pin) : LedIndicador (pin) {
    
};

void LedMorse::punto() {
    encender();
    delay(200);
    apagar();
    delay(200);
};

void LedMorse::raya() {
    encender();
    delay(600);
    apagar();
    delay(200);
};

void LedMorse::SOS() {
    punto();
    punto();
    punto();
    raya();
    raya();
    raya();
    punto();
    punto();
    punto();
};