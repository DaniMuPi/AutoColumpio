# AutoColumpio

Librería para ESP32 que facilita el uso de una celda de carga con el módulo HX711 para sistemas automatizados como columpios inteligentes.

## Características

- Inicialización fácil de la balanza
- Calibración automática
- Lectura de peso en gramos
- Escalado a rangos personalizados
- Detección automática de niño según peso

## Ejemplos

- `calibracionGalga`: permite calibrar fácilmente el sensor de carga.
- `funcionamientoCompleto`: muestra el funcionamiento junto con una pantalla Nextion.

## Uso

```cpp
#include "AutoColumpio.h"

AutoColumpio columpio(5, 4); // Pines DOUT y SCK
columpio.iniciar();
float peso = columpio.obtenerPesoGramos();
```

## Dependencias

- HX711
- Nextion
