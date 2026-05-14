import asyncio
import struct
from bleak import BleakClient

SERVICE_UUID =        "9c4743dd-5fdf-4203-9ecf-c45dab140996"
CHARACTERISTIC_UUID = "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"
ESP32_ADDRESS =       "D8:3B:DA:44:E4:39"

def al_recibir(sender, data):
    if len(data) < 4:
        return
    muestras = list(struct.unpack(f'{len(data)//4}I', data))
    if len(muestras) > 0:
        print(f"Bloque recibido: {len(muestras)} muestras, promedio: {sum(muestras)//len(muestras)}")

async def main():
    print(f"Conectando a {ESP32_ADDRESS}...")
    async with BleakClient(ESP32_ADDRESS) as client:
        print("Conectado. Suscribiéndose a notificaciones...")
        await client.start_notify(CHARACTERISTIC_UUID, al_recibir)
        await asyncio.sleep(30)

asyncio.run(main())