import asyncio
from bleak import BleakClient
import struct
import socket
import time
from pymongo import MongoClient
from dotenv import load_dotenv
from datetime import datetime
import os
import threading

load_dotenv()
client_mongo = MongoClient(os.getenv("MONGODB_URI"))
coleccion = client_mongo["wearable"]["ppg"]

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

direccion = "D8:3B:DA:44:E4:39"
CHARACTERISTIC_UUID = "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"

#async def conectar(direccion):
#    cliente = BleakClient(dirección)
#    try:
#        await cliente.connect()
#        print(f"Conectado a {dirección}")
#    except Exception as e:
#        print(f"Error al conectar: {e}")
#    finally:
#        await cliente.disconnect()
#        print("Desconectado")

#async def conectar(direccion):
#    async with BleakClient(direccion) as cliente:
#        print(f"Conectado a {direccion}")
#        for servicio in cliente.services:
#            print(f"Servicio: {servicio.uuid}")
#            for caracteristica in servicio.characteristics:
#                print(f"  Característica: {caracteristica.uuid}, Propiedades: {caracteristica.properties}")


contador_teleplot = 0
contador = 0
inicio = time.time()
ultimo_ts = None

def guardar_mongo(documento):
    coleccion.insert_one(documento)

def al_recibir(sender, data):
    global contador, inicio, ultimo_ts
    ts = struct.unpack('I', data[:4])[0]
    muestras = struct.unpack(f'{(len(data)-4)//4}I', data[4:])
    promedio = sum(muestras) // len(muestras)
    
    hz_real = 0
    if ultimo_ts is not None and ts > ultimo_ts:
        intervalo_ms = ts - ultimo_ts
        hz_real = round(len(muestras) * 1000 / intervalo_ms)
    ultimo_ts = ts
    
    contador += len(muestras)
    if time.time() - inicio >= 1:
        print(f"Hz reales: {contador}")
        contador = 0
        inicio = time.time()
    
    mensaje = f"green:{promedio}\n"
    udp.sendto(mensaje.encode(), ("127.0.0.1", 47269))

    documento = {
        "timestamp": datetime.now(),
        "timestamp_esp": ts,
        "muestras": list(muestras),
        "hz_real": hz_real,
        "num_muestras": len(muestras)
    }
    threading.Thread(target=guardar_mongo, args=(documento,)).start()

async def conectar(direccion):
    while True:
        try:
            async with BleakClient(direccion) as cliente:
                print(f"Conectado a {direccion}")
                await cliente.start_notify(CHARACTERISTIC_UUID, al_recibir)
                print("Suscrito, esperando datos...")
                while True:
                    await asyncio.sleep(1)
        except Exception as e:
            print(f"Desconectado, reconectando... {e}")
            await asyncio.sleep(2)



asyncio.run(conectar(direccion))
