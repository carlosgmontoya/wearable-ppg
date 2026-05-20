import random

class Dispositivo:
    def __init__(self, id, bateria):
        self.__id = id
        self._bateria = bateria
        
    def info(self):
        print(f"La batería {self.__id} tiene esta carga: {self._bateria}")
        

class SensorPPG(Dispositivo):
    def __init__(self, id, bateria, frecuencia):
        super().__init__(id, bateria)
        self._frecuencia = frecuencia
        
    def leer(self):
        ale = random.randint(800, 1200)
        return ale    

dispositivo1 = Dispositivo(2345, "30%")
dispositivo2 = SensorPPG(2346, "25%", 256)

dispositivo1.info()
aleator = dispositivo2.leer()    
print(aleator)