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
    const char* detectarNino(float pesoEscaladoKg);
    void tare();
    void setScale(float factor);

private:
    HX711 scale;
    int _doutPin;
    int _sckPin;
    float _factorEscala;
};

#endif
