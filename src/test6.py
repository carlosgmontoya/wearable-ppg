import random
import asyncio

class SensorAsync:
    def __init__(self, nombre, bateria):
        self._nombre = nombre
        self._bateria = bateria
        

    async def leer(self):
        while True:
            numero = random.randint(800, 1200)
            print(f"{self._nombre} lectura: {numero}")
            await asyncio.sleep(0.1)
        
    async def monitorear_bateria(self):
        while True:
            self._bateria = self._bateria - 5
            print(f"nivel {self._bateria}")
            if self._bateria < 20:
                print("bateria baja!")
            await asyncio.sleep(1)
        
async def main():
    sensorasync = SensorAsync("litio", 50) 
    await asyncio.gather(sensorasync.leer(), sensorasync.monitorear_bateria())
    
asyncio.run(main())
    