import asyncio
import random

numero = 0
data = []

async def leer_sensor():
    print("Leyendo sensor...")
    while True:
        numero = random.randint(1, 10)
        data.append(numero)
        if len(data)==10:
            promedio = sum(data)/len(data)
            print(promedio)
            data.clear()    
        await asyncio.sleep(0.1)       
    print(data)

async def status():
    while True:
        print("sistema activo...")
        await asyncio.sleep(2)
    
async def main():
    await asyncio.gather(
        leer_sensor(),
        status()
    )
    
asyncio.run(main())