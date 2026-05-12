import random

class BufferPPG:
    def __init__(self):
        self._buffer = []
                
    def agregar(self, muestra):
        self._muestra = muestra
        self._buffer.append(self._muestra)
        print(self._buffer)
        if self.esta_lleno():
            self.promedio()
            self._buffer.clear()
        
    def esta_lleno(self):
        return len(self._buffer)==10
            
    def promedio(self):
        if len(self._buffer)>0:
            promedio = sum(self._buffer)/len(self._buffer)
            print(promedio)

buffer1 = BufferPPG()
for i in range(15):
    buffer1.agregar(random.randint(1,10))
buffer1.promedio()