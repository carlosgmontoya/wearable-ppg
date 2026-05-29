import asyncio
from bleak import BleakClient
import struct
import socket
import time

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

contador = 0
inicio = time.time()
contador_teleplot = 0

contador = 0
inicio = time.time()

def al_recibir(sender, data):
    global contador, contador_teleplot, inicio
    ts = struct.unpack('I', data[:4])[0]
    muestras = struct.unpack(f'{(len(data)-4)//4}I', data[4:])
    promedio = sum(muestras) // len(muestras)
    
    contador += len(muestras)
    contador_teleplot += 1
    
    if time.time() - inicio >= 1:
        print(f"Hz reales: {contador}")
        contador = 0
        inicio = time.time()
    
    mensaje = f"green:{promedio}\n"
    udp.sendto(mensaje.encode(), ("127.0.0.1", 47269))

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
