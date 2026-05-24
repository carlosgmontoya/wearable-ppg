#include "ledIndicador.h"

LedIndicador::LedIndicador(int pin) {
    this-> pin = pin;
};

void LedIndicador::encender() {
    encendido = true;
    digitalWrite(pin, HIGH);
};

void LedIndicador::apagar() {
    encendido = false;
    digitalWrite(pin, LOW);
};

bool LedIndicador::estaEncendido() {
    return encendido;
};