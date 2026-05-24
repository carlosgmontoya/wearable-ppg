#include <Arduino.h>

class DispositivoBLE {
    private:
        String nombre;
        bool conectado = false;
    
    public:
        DispositivoBLE(String nombre);
        void conectar();
        void desconectar();
        bool estaConectado();
};