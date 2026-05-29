import asyncio
import random

class Dispositivo:
    def __init__(self, id):
        self._id = id
        
    def info(self):
        print(f"El id es {self._id}")

disp = Dispositivo(2345)
disp.info()

class DispositivoBLE(Dispositivo):
    def __init__(self, id, direccion):
        super().__init__(id)
        self._direccion = direccion

    async def conectar(self):
        print("Conectando... ")
        await asyncio.sleep(1)
        print(f"{self._direccion} conectado")

    async def escuchar(self):
        while True:
            data = random.randint(800, 1200)
            await asyncio.sleep(2)
            print(data)
            
dispble = DispositivoBLE(123, 999)

async def main():
    await asyncio.gather(dispble.conectar(), dispble.escuchar())
    

asyncio.run(main())

"""
import asyncio
import random

class SensorPPG:
    def __init__(self, frecuencia, nombre):
        self.__frecuencia = frecuencia
        self._nombre = nombre
        
    def get_frecuencia(self):
        return self.__frecuencia
    
    def info(self):
        print(f"El nombre es {self._nombre} y la frecuencia es {self.__frecuencia}")
        

sensor = SensorPPG(256, "Felipe")
print(sensor.get_frecuencia())
sensor.info()

class SensorBLE(SensorPPG):
    def __init__(self, frecuencia, nombre, direccion):
        super().__init__(frecuencia, nombre)
        self._direccion = direccion 
        
    async def conectar(self):
        print("Conectando... ")
        await asyncio.sleep(2)
        print(f"Conectado {self._nombre} a {self._direccion}")

    async def escuchar(self):
        while True:
            await asyncio.sleep(5)
            data = random.randint(0,10)
            print(data)
        
sens = SensorBLE(256, "Yaya", 2345)

async def main():
    await asyncio.gather(sens.conectar(), sens.escuchar())

asyncio.run(main())
"""

"""
class LecturaPPG:
    def __init__(self, muestras, frecuencia):
        self.muestras = muestras
        self.frecuencia = frecuencia
        
    def agregar(self, muestra):
        self.muestras.append(muestra)
        
        
    def promedio(self):
        return sum(self.muestras)/len(self.muestras)
        
        
lectura = LecturaPPG([10], 256)
lectura.agregar(15)
lectura.agregar(5)
print(lectura.promedio())
"""