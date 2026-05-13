import asyncio

async def sensor1():
    while True:
        print("Lectura sensor1")
        await asyncio.sleep(1)
        
async def sensor2():
    while True:
        print("Lectura sensor2")
        await asyncio.sleep(0.5)
        
        
async def main():
    await asyncio.gather(sensor1(), sensor2())
    
asyncio.run(main())