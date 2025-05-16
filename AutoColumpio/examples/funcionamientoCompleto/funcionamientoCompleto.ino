#include <Arduino.h>
#include "AutoColumpio.h"
#include "soc/rtc.h"
#include "esp_system.h"
#include <HardwareSerial.h>
#include "Nextion.h"

HardwareSerial myNextionSerial(2);  // UART2
#define nexSerial myNextionSerial

NexPage p0 = NexPage(0, 0, "page0");
NexText p0_t0 = NexText(0, 1, "t0");

AutoColumpio columpio(5, 4);  // DOUT, SCK

void setup() {
  Serial.begin(115200);
  rtc_cpu_freq_config_t config;
  setCpuFrequencyMhz(80);

  myNextionSerial.begin(9600, SERIAL_8N1, 16, 17);
  nexInit();

  Serial.println("Inicializando AutoColumpio");

  columpio.iniciar();

  columpio.setScale(-703.003); // aqui se debe añadir el resultado de calibración: (lectura)/(peso en gramos medido)
  columpio.tare(); // para poner la balanza a 0
}

void loop() {
  char mensaje[120];

  float pesoDetectado = columpio.obtenerPesoGramos(10);
  float pesoEscaladoGramos = (pesoDetectado/1000.0) * 100000.0; //Escalamos en este caso el rango de 0-1 kg a 0-100 kgs
  int pesoEscaladoKg = pesoEscaladoGramos / 1000.0;

  const char* deteccionNiño = columpio.detectarNino(pesoEscaladoKg);

  snprintf(mensaje, sizeof(mensaje),
    "Peso detectado = %.2f g\r\nPeso escalado = %d kg\r\n Detectado? %s",
    pesoDetectado, pesoEscaladoKg, deteccionNiño);

  p0_t0.setText(mensaje);

  delay(2000);
}
