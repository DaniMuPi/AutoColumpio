#include "AutoColumpio.h"

AutoColumpio::AutoColumpio(int doutPin, int sckPin)
  : _doutPin(doutPin), _sckPin(sckPin) {}

void AutoColumpio::iniciar() {
    scale.begin(_doutPin, _sckPin);
}

void AutoColumpio::calibrar() {
    if (scale.is_ready()) {
        scale.set_scale();
        Serial.println("Tara... quite cualquier peso de la balanza.");
        delay(5000);
        scale.tare();
        Serial.println("Tara completada...");
        Serial.print("Coloque un peso conocido en la balanza...");
        delay(5000);
        long reading = scale.get_units(50);
        Serial.print("Resultado: ");
        Serial.println(reading);
    } else {
        Serial.println("HX711 no encontrado.");
    }
}

float AutoColumpio::obtenerPesoGramos(uint8_t muestras) {
    return scale.get_units(muestras);
}

const char* AutoColumpio::detectarNino(float pesoEscaladoKg) {
    if (pesoEscaladoKg < 10) {
        return "No";
    } else if (pesoEscaladoKg <= 60) {
        return "Si";
    } else {
        return "Peso excedido";
    }
}

void AutoColumpio::tare() {
  scale.tare();
}

void AutoColumpio::setScale(float factor) {
  _factorEscala = factor;
  scale.set_scale(_factorEscala);
  _escalaEstablecida = true;
}
