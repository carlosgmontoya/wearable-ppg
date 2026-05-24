#include <Arduino.h>

class Dispositivo {
    private:
        int id;

    protected:
        int bateria;

    public:
        Dispositivo(int id, int bateria);
        void info();
};