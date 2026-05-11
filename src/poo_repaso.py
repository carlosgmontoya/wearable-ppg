class LecturaPPG:
    def __init__(self, muestras, frecuencia_hz):
        self.muestras = muestras
        self.frecuencia_hz = frecuencia_hz

    def duracion_segundos(self):
        return len(self.muestras) / self.frecuencia_hz
    
    def promedio(self):
        return sum(self.muestras) / len(self.muestras)


class LecturaPPGFiltrada(LecturaPPG):
    def __init__(self, muestras, frecuencia_hz, filtro):
        super().__init__(muestras, frecuencia_hz)
        self.filtro = filtro

    def description(self):
        return f"Filtro: {self.filtro}, Promedio: {self.promedio()}"


class SensorPPG:
    def __init__(self, frecuencia_hz):
        self.__frecuencia_hz = frecuencia_hz
        self.__muestras = []

    def agregar_muestra(self, muestra):
        self.__muestras.append(muestra)

    def get_frecuencia(self):
        return self.__frecuencia_hz

    def get_muestras(self):
        return self.__muestras

#lectura = LecturaPPG([1023, 987, 1005, 1010], 250)
#print(lectura.duracion_segundos())
#print(lectura.promedio())
#print(lectura.muestras)
#print(lectura.frecuencia_hz)

#lectura_filtrada = LecturaPPGFiltrada([1023, 987, 1005, 1010], 250, "Butterworth")
#print(lectura_filtrada.description())
#print(lectura_filtrada.duracion_segundos())
#print(lectura_filtrada.muestras)
#print(lectura_filtrada.frecuencia_hz)
#print(lectura_filtrada.filtro)

sensor = SensorPPG(250)
sensor.agregar_muestra(1023)
sensor.agregar_muestra(987)
sensor.agregar_muestra(1005)
sensor.agregar_muestra(1010)
print(sensor.get_frecuencia())
print(sensor.get_muestras())

