"""
f = open("datos.txt", "w")
f.write("Hola mundo")
f.close()

f = open("datos.txt")
contenido = f.read()
print(contenido)
f.close()
"""

with open("datos.txt", "w") as f:
    f.write("\nHola mundo con with")

with open("datos.txt") as f:
    contenido = f.read()
    print(contenido)