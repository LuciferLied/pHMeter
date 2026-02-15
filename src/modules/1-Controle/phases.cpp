#include <config.h>

void phaseHandler(unsigned long now) {
  if (now - lastPhaseCheckTime >= phaseCheckCD) {
    if (mode == "Doser") {
      if (currentPH >= MAX_DESIRED_PH) {
        phase = "Lowering";
      } else if (currentPH <= MIN_DESIRED_PH) {
        phase = "Watching";
        // pumpDesRuntime = 0;
      }
    } else if(mode == "Calibrator"){
        phase = "Titting";
    }
  }
}