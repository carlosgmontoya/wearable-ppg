#include <Arduino.h>

class Bateria {
    private:
        int nivel = 100;
        String nombre;

    public:
        Bateria(String nombre);
        void descargar(int cantidad);
        int getNivel();
        bool estaLow();
        void imprimir();

};