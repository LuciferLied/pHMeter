#include <config.h>

void setup() {
  pinMode(DIGIPIN, OUTPUT);
  digitalWrite(DIGIPIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  phaseHandler(now);
  pump(now);
  reader(now);
  if (incCommand != "") {
    commander(now);
  }
  if (handlingPump == false) {
    if (now - lastLoopTime >= loopCD) {
      if (mode == "Doser") {
        doser(now);
      } else if (mode == "Calibrator") {
        calibrator(now);
      }
      sampleDecay(now);
    }
    printer(now, mode, lastPrinterTime, printerCD, printIteration);
  }
  incCommand = "";
}