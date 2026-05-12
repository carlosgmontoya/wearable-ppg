class Sensor:
    def __init__(self, nombre, activo):
        self.__nombre = nombre
        self.__activo = activo
        
    def activar(self):
        self.__activo = True
        print(f"Sensor {self.__nombre} activado!")
        
    def desactivar(self):
        self.__activo = False
        print(f"Sensor {self.__nombre} desactivado!")
        
    def consultar(self):
        if self.__activo == True:
            print(f"Sensor {self.__nombre} activo")
        else:
            print(f"Sensor {self.__nombre} inactivado")
        
sensor1 = Sensor("infrarrojo", False)
sensor1.activar()
sensor1.consultar()
sensor1.desactivar()
sensor1.consultar()