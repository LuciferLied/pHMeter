#include <config.h>

void pump(unsigned long now) {
  if (mode == "Doser") {
    if (now - lastPumpTime >= pumpCD) {
      if (runPump == true) {
        startPump(now);
        runPump = false;
        handlingPump = true;
      } else if (handlingPump == true && now - lastPumpTime >= currentPumpTiming) {
        stopPump();
        handlingPump = false;
      }
    }
  } else if (mode == "Calibrator") {
    if (runPump == true) {
        startPump(now);
        runPump = false;
        handlingPump = true;
      } else if (handlingPump == true && now - lastPumpTime >= currentPumpTiming) {
        stopPump();
        handlingPump = false;
      }
  }
}
void startPump(unsigned long now) {
  lastPumpTime = now;
  digitalWrite(7, LOW); // Relay ON
}
void stopPump() {
  digitalWrite(7, HIGH); // Relay OFF
}