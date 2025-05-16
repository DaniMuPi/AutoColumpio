#ifndef AUTOCOLUMPIO_H
#define AUTOCOLUMPIO_H

#include <Arduino.h>
#include "HX711.h"

class AutoColumpio {
public:
    AutoColumpio(int doutPin, int sckPin);
    void iniciar();
    void calibrar();
    float obtenerPesoGramos(uint8_t muestras = 10);
    float escalarPeso(float pesoOriginal, float factor = 100.0);
    const char* detectarNino(float pesoEscaladoKg);

private:
    HX711 scale;
    int _doutPin;
    int _sckPin;
};

#endif
