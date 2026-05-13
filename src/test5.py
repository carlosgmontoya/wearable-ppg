import random
import asyncio

buffer = []

async def sensor():
    while True:
        numero = random.randint(800, 1200)
        print(numero)
        buffer.append(numero)
        await asyncio.sleep(0.1)
    
async def procesar():
    while True:
        await asyncio.sleep(3)
        if len(buffer)>0:
            promedio = sum(buffer)/len(buffer)
            print(promedio)
            buffer.clear()


async def main():
    await asyncio.gather(sensor(), procesar())
    
asyncio.run(main())