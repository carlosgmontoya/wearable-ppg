class LecturaPPG:
    def __init__(self, muestras, frecuencia_hz):
        self.muestras = muestras
        self.frecuencia_hz = frecuencia_hz

    def duracion_segundos(self):
        return len(self.muestras) / self.frecuencia_hz
    
    def promedio(self):
        return sum(self.muestras) / len(self.muestras)
    
lectura = LecturaPPG([1023, 987, 1005, 1010], 250)
print(lectura.duracion_segundos())
print(lectura.promedio())