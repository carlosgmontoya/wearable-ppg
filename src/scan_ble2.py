import asyncio
from bleak import BleakScanner


async def escanear():
    devices = await BleakScanner.discover(timeout=5.0)
    for device in devices:
        print(f"Nombre: {device.name}, Dirección: {device.address}")

asyncio.run(escanear())