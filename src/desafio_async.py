import asyncio

async def leer_sensor():
    print("Leyendo sensor...")
    await asyncio.sleep(0.1)  # Simula el tiempo de lectura
    print("Sensor leído!")
    return []