# 🫀 Wearable PPG — Roadmap 12 Semanas (Opción 2)

**Stack:** ESP32-S3 · MAX30101 · BLE · Python · MongoDB · Scikit-learn · PyTorch  
**Ritmo:** Full time (6-8 horas/día)

---

## ✅ Semana 1 — Python, POO, async, Git
- [x] POO a fondo (clases, herencia, encapsulamiento)
- [x] Python async/await (necesario para `bleak`)
- [x] Git: ramas, pull requests, flujo profesional
- [x] Estructura de proyecto Python profesional
- [x] Crear repo del wearable en GitHub

**Resultado:** Proyecto base en GitHub bien estructurado ✅

---

## ✅ Semana 2 — ESP32 + PlatformIO + MAX30101
- [x] PlatformIO en VS Code, configurar ESP32-S3
- [x] I2C, conectar MAX30101, leer datos
- [x] Acumular muestras en buffer, enviar bloques
- [x] Visualizar señal PPG en Teleplot (Red, IR, Green)
- [x] Subir firmware a GitHub

**Resultado:** Señal PPG cruda visible en Teleplot ✅

---

## ✅ Semana 3 — BLE
- [x] Teoría BLE (servicios, características, UUIDs)
- [x] Enviar bloques PPG por BLE desde ESP32
- [x] Recibir datos con `bleak` en Python
- [x] Manejar async/await en el receptor

**Resultado:** ESP32 → Python funcionando por BLE ✅

---

## Semana 4 — MongoDB + POO C++ + bleak a fondo
- [ ] MongoDB local, conceptos básicos
- [ ] `pymongo`, operaciones básicas
- [ ] Pipeline completo ESP32 → Python → MongoDB
- [ ] POO en C++ con desafíos (clases, herencia, punteros, `->`)
- [ ] Refactorizar código BLE del ESP32 con POO
- [ ] `bleak` a fondo (callbacks, async, reconexión automática)
- [ ] POO aplicado en Python: clases `ReceptorBLE` y `RepositorioPPG`
- [ ] Manejo de errores y reconexión BLE automática

**Resultado:** Sistema completo funcionando de punta a punta ✅

---

## Semana 5 — Matemáticas + primer contacto ML
- [ ] Álgebra lineal aplicada con Numpy
- [ ] Estadística aplicada a señal PPG
- [ ] Visualización con Matplotlib/Seaborn
- [ ] Análisis exploratorio de la señal PPG real
- [ ] Dataset público de PPG (PhysioNet)
- [ ] Primer modelo ML con datos públicos

**Resultado:** Notebook con análisis exploratorio + primer modelo ML ✅

---

## Semana 6 — Filtros + ML en paralelo
- [ ] Teorema de Nyquist, señal a 250 Hz
- [ ] FFT con Scipy, espectro de frecuencias
- [ ] Identificar ruido y componentes útiles
- [ ] Filtros digitales (Butterworth, pasa bajos, pasa altos)
- [ ] Diseñar filtro para la señal PPG real
- [ ] Aplicar modelo ML a señal filtrada
- [ ] Comparar resultados con y sin filtro

**Resultado:** Señal filtrada + modelo ML aplicado ✅

---

## Semana 7 — BPM, SpO2 + features para ML
- [ ] Extracción de BPM desde señal PPG filtrada
- [ ] Extracción de SpO2
- [ ] Features: HRV, amplitud, frecuencia dominante
- [ ] Dataset de features listo para ML

**Resultado:** Pipeline con señal filtrada y métricas extraídas ✅

---

## Semana 8 — Machine Learning clásico (parte 1)
- [ ] Conceptos: train/test split, overfitting, métricas
- [ ] Extracción de features (BPM, HRV, amplitud, frecuencia dominante)
- [ ] Random Forest y SVM con features reales

**Resultado:** Primer modelo entrenado con señal PPG real ✅

---

## Semana 9 — Machine Learning clásico (parte 2)
- [ ] Validación cruzada, ajuste de hiperparámetros
- [ ] Pipeline ML completo con Scikit-learn
- [ ] Comparar modelos, interpretar resultados

**Resultado:** Notebook ML documentado en GitHub ✅

---

## Semana 10 — Deep Learning (parte 1)
- [ ] Redes neuronales conceptualmente
- [ ] PyTorch básico (tensores, datasets, dataloaders)
- [ ] Primera red neuronal con señal PPG
- [ ] Curvas de entrenamiento y validación

**Resultado:** Primer modelo DL funcionando en GitHub ✅

---

## Semana 11 — Deep Learning (parte 2)
- [ ] LSTM para señales temporales
- [ ] Entrenar LSTM con señal PPG real
- [ ] Comparar LSTM vs ML clásico
- [ ] Integrar modelo entrenado en el pipeline completo
- [ ] Optimización y manejo de errores general
- [ ] README profesional y documentación

**Resultado:** Portafolio en GitHub terminado ✅

---

## Semana 12 — Buffer
- [ ] Profundizar en lo que más interesó
- [ ] Resolver deuda técnica acumulada
- [ ] Preparar presentación del proyecto

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
| Dataset PPG | [PhysioNet](https://physionet.org) (gratis) |
| Señales | [Scipy Signal](https://docs.scipy.org/doc/scipy/reference/signal.html) |
| ML | [Scikit-learn docs](https://scikit-learn.org/stable/) |
| Deep Learning | [PyTorch tutorials](https://pytorch.org/tutorials/) |
