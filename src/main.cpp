#include <config.h>

void setup() {
  pinMode(DIGIPIN, OUTPUT);
  digitalWrite(DIGIPIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  if(firstRun == true){
    executePreset(now);
    clearCommandArray();
    firstRun = false;
  }
  phaseHandler(now);
  pump(now);
  reader(now);
  if (incCommand != "") {
    commander(now);
    incCommand = "";
  }
  if (handlingPump == false && incCommand == "") {
    if (now - lastLoopTime >= loopCD) {
      if (mode == "Doser") {
        doser(now);
      } else if (mode == "Calibrator") {
        calibrator2(now);
      }
      sampleDecay(now);
    }
    printer(now, mode, lastPrinterTime, printerCD, printIteration);
  }
    reader(now);
  if (incCommand != "") {
    commander(now);
    incCommand = "";
  }
}