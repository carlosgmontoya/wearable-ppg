import random

min = 0
max = 10
lectura = 0

class Dispositivo:
    def __init__(self, id, bateria):
        self._id = id
        self._bateria = bateria
    
    def leer(self):
        lectura = random.randint(min, max)        
        print(f"El sensor {self._id} con carga de {self._bateria} marca {lectura} ")

class SensorPPG(Dispositivo):
    def __init__(self, id, bateria):
        super().__init__(id, bateria)
    
    def leer(self):
        lectura = [random.randint(500, 800) for i in range(5)]
        print(f"El sensor {self._id} con carga de {self._bateria} marca {lectura} ")

class SensorTemperatura(Dispositivo):
    def __init__(self, id, bateria):
        super().__init__(id, bateria)
        
    def leer(self):
        lectura = random.randint(35, 40)
        print(f"El sensor {self._id} con carga {self._bateria} marca {lectura}")


sensor1 = SensorPPG(2345, "30%")
sensor1.leer()

sensor2 = SensorTemperatura(25, "40%")
sensor2.leer()