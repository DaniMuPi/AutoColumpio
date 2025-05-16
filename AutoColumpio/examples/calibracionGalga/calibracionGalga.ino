#include <Arduino.h>
#include "AutoColumpio.h"
#include "soc/rtc.h"
#include "esp_system.h"

AutoColumpio columpio(5, 4);  // DOUT, SCK

void setup() {
  Serial.begin(115200);
  rtc_cpu_freq_config_t config;
  setCpuFrequencyMhz(80);
  columpio.iniciar();
}

void loop() {
  columpio.calibrar();
  delay(1000);
}
