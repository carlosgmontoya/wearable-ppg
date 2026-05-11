# 🫀 Wearable PPG — Roadmap 12 Semanas

**Stack:** ESP32-S3 · MAX30101 · BLE · Python · MongoDB · Scikit-learn · PyTorch  
**Ritmo:** Full time (6-8 horas/día)

---

## Semana 1 — Repaso Python + Git profesional

- [ ] POO a fondo (clases, herencia, encapsulamiento)
- [ ] Python async/await (necesario para `bleak`)
- [ ] Git: ramas, pull requests, flujo profesional
- [ ] Estructura de proyecto Python profesional
- [ ] Crear repo del wearable en GitHub

**Resultado:** Proyecto base en GitHub bien estructurado

---

## Semana 2 — ESP32 + PlatformIO + MAX30101

- [ ] PlatformIO en VS Code, configurar ESP32-S3
- [ ] I2C, conectar MAX30101, leer datos
- [ ] Acumular 250 muestras en buffer, enviar bloques
- [ ] Visualizar señal PPG cruda en Monitor Serial
- [ ] Subir firmware a GitHub

**Resultado:** Señal PPG cruda visible en Monitor Serial

---

## Semana 3 — BLE

- [ ] Teoría BLE (servicios, características, UUIDs)
- [ ] Enviar bloques PPG por BLE desde ESP32
- [ ] Recibir datos con `bleak` en Python
- [ ] Manejar async/await en el receptor

**Resultado:** ESP32 → Python funcionando por BLE

---

## Semana 4 — MongoDB + Pipeline completo

- [ ] MongoDB local, conceptos básicos
- [ ] `pymongo`, operaciones básicas
- [ ] POO aplicado: clases `ReceptorBLE` y `RepositorioPPG`
- [ ] Pipeline completo ESP32 → Python → MongoDB
- [ ] Manejo de errores y reconexión BLE automática

**Resultado:** Sistema completo funcionando de punta a punta ✅

---

## Semana 5 — Matemáticas para señales

- [ ] Álgebra lineal aplicada con Numpy
- [ ] Estadística aplicada a señal PPG
- [ ] Visualización con Matplotlib/Seaborn
- [ ] Análisis exploratorio de la señal PPG real

**Resultado:** Notebook Jupyter con análisis exploratorio de PPG

---

## Semana 6 — Procesamiento de señales (parte 1)

- [ ] Teorema de Nyquist, señal a 250 Hz
- [ ] FFT con Scipy, espectro de frecuencias
- [ ] Identificar ruido y componentes útiles

**Resultado:** Notebook con análisis espectral de la señal

---

## Semana 7 — Procesamiento de señales (parte 2)

- [ ] Filtros digitales (Butterworth, pasa bajos, pasa altos)
- [ ] Diseñar filtro para la señal PPG
- [ ] Extracción de BPM
- [ ] Extracción de SpO2

**Resultado:** Pipeline con señal filtrada y métricas extraídas ✅

---

## Semana 8 — Machine Learning clásico (parte 1)

- [ ] Conceptos: train/test split, overfitting, métricas
- [ ] Extracción de features (BPM, HRV, amplitud, frecuencia dominante)
- [ ] Random Forest y SVM con las features extraídas

**Resultado:** Primer modelo entrenado con señal PPG real

---

## Semana 9 — Machine Learning clásico (parte 2)

- [ ] Validación cruzada, ajuste de hiperparámetros
- [ ] Pipeline ML completo con Scikit-learn
- [ ] Comparar modelos, interpretar resultados

**Resultado:** Notebook ML documentado en GitHub

---

## Semana 10 — Deep Learning (parte 1)

- [ ] Redes neuronales conceptualmente
- [ ] PyTorch básico (tensores, datasets, dataloaders)
- [ ] Primera red neuronal con señal PPG
- [ ] Curvas de entrenamiento y validación

**Resultado:** Primer modelo DL funcionando en GitHub

---

## Semana 11 — Deep Learning (parte 2)

- [ ] LSTM para señales temporales
- [ ] Entrenar LSTM con señal PPG real
- [ ] Comparar LSTM vs ML clásico

**Resultado:** Notebook comparativo documentado

---

## Semana 12 — Integración y cierre

- [ ] Integrar modelo entrenado en el pipeline completo
- [ ] Optimización y manejo de errores general
- [ ] README profesional y documentación
- [ ] Revisión final del proyecto

**Resultado:** Portafolio en GitHub terminado ✅

---

## Stack de librerías

| Área | Librería |
|---|---|
| Hardware | PlatformIO, SparkFun MAX3010x |
| BLE Python | `bleak` |
| Base de datos | `pymongo` |
| Señales | `scipy`, `numpy` |
| Visualización | `matplotlib`, `seaborn` |
| ML | `scikit-learn` |
| Deep Learning | `pytorch` |
| Notebooks | `jupyter` |

---

## Recursos clave

| Tema | Recurso |
|---|---|
| Git/GitHub | [Pro Git](https://git-scm.com/book/es/v2) (gratis, en español) |
| Python + POO | [Real Python](https://realpython.com) |
| PlatformIO | [Docs oficiales](https://docs.platformio.org) |
| BLE Python | [Docs bleak](https://bleak.readthedocs.io) |
| MongoDB | [MongoDB University](https://university.mongodb.com) (gratis) |
| Señales | [Scipy Signal](https://docs.scipy.org/doc/scipy/reference/signal.html) |
| ML | [Scikit-learn docs](https://scikit-learn.org/stable/) |
| Deep Learning | [PyTorch tutorials](https://pytorch.org/tutorials/) |
