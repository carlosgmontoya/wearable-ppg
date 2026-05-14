from pymongo import MongoClient
from dotenv import load_dotenv
import os

load_dotenv()

client = MongoClient(os.getenv("MONGODB_URI"))
db = client["wearable"]
coleccion = db["ppg"]

# Insertar un documento de prueba
coleccion.insert_one({"prueba": "conexión exitosa"})
print("Documento insertado!")

# Leer el documento
doc = coleccion.find_one({"prueba": "conexión exitosa"})
print(f"Documento encontrado: {doc}")