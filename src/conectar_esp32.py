import asyncio
from bleak import BleakClient
import struct

direccion = "D8:3B:DA:44:E4:39"
CHARACTERISTIC_UUID = "4f2f616b-7983-49b5-a516-e0f7a5e6fec9"

#async def conectar(direccion):
#    cliente = BleakClient(dirección)
#    try:
#        await cliente.connect()
#        print(f"Conectado a {dirección}")
        # Aquí puedes agregar código para interactuar con el dispositivo
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

def al_recibir(sender, data):
    valor = struct.unpack('I', data)[0]
    print(f"Datos recibidos: {valor}")

async def conectar(direccion):
    async with BleakClient(direccion) as cliente:
        print(f"Conectado a {direccion}")
        await cliente.start_notify(CHARACTERISTIC_UUID, al_recibir)
        await asyncio.sleep(10)



asyncio.run(conectar(direccion))
