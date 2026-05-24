#include "dispositivo.h"

Dispositivo::Dispositivo(int id, int bateria){
    this-> id = id;
    this-> bateria = bateria;
};

void Dispositivo::info(){
    Serial.println("La bateria " + String(id) + " tiene " + String(bateria) + " % de carga");
};
