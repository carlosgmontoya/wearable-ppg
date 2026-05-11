import asyncio

async def recibir_datos():
    print("Esperando datos BLE...")
    await asyncio.sleep(2)  # Simula la espera de datos
    print("Datos recibidos!")
    return [1023, 987, 1005]

async def guardar_mongdb(datos):
    print(f"Guardando {len(datos)} muestras...")
    await asyncio.sleep(1)  # Simula el tiempo de guardado
    print("Guardado!")

async def monitorear():
    for i in range(5):
        print(f"monitoreando... {i}")
        await asyncio.sleep(0.5)

async def leer_dato(numero):
    print(f"Leyendo dato {numero}...")
    await asyncio.sleep(1)
    print(f"Dato {numero} leído!")
    return numero

async def procesar_datos():
    while True:
        print("Procesando datos...")
        await asyncio.sleep(1)
        print("Datos procesados!")

#async def main():
#    datos = await recibir_datos()
#    await guardar_mongdb(datos)

#async def main():
#    await asyncio.gather(
#        recibir_datos(),
#        guardar_mongdb([1023, 987, 1005]),
#        monitorear()
#    )

async def main():
    await asyncio.gather(
        leer_dato(1),
        leer_dato(2),
        leer_dato(3),
        procesar_datos()
    )


asyncio.run(main())