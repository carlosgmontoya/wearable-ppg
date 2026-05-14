import asyncio
import struct
from datetime import datetime
from bleak import BleakClient
from pymongo import MongoClient
from dotenv import load_dotenv
import os

load_dotenv()

CHARACTERISTIC_UUID = "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"
ESP32_ADDRESS =       "D8:3B:DA:44:E4:39"

client_mongo = MongoClient(os.getenv("MONGODB_URI"))
coleccion = client_mongo["wearable"]["ppg"]

def al_recibir(sender, data):
    if len(data) < 4:
        return
    muestras = list(struct.unpack(f'{len(data)//4}I', data))
    if len(muestras) > 0:
        documento = {
            "timestamp": datetime.now(),
            "muestras": muestras,
            "promedio": sum(muestras) // len(muestras),
            "hz": 250
        }
        coleccion.insert_one(documento)
        print(f"Guardado: {len(muestras)} muestras, promedio: {documento['promedio']}")

async def main():
    print(f"Conectando a {ESP32_ADDRESS}...")
    async with BleakClient(ESP32_ADDRESS) as client:
        print("Conectado!")
        await client.start_notify(CHARACTERISTIC_UUID, al_recibir)
        await asyncio.sleep(60)

asyncio.run(main())