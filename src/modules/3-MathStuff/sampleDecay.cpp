#include <config.h>

void sampleDecay(unsigned long now) {
  if (mode == "Doser") {
    if (now - lastDecayTime >= decayCD) {
      lastDecayTime = now;
      if (now - lastCompTime >= decayCD) {
        for (int i = 0; i < diffPHVals; i++) {
          if (clusteredSamplesCompArray[i] * pow(decayFactor, compFactor) >= clusteredSamplesArray[i]) {
            clusteredSamplesArray[i] = 0;
          }
          clusteredSamplesCompArray[i] = clusteredSamplesArray[i];
          if (clusteredSamplesArray[i] != 0) {
            clusteredSamplesArray[i] = clusteredSamplesArray[i] * decayFactor;
          }
        }
      } else {
        for (int i = 0; i < diffPHVals; i++) {
          clusteredSamplesArray[i] = clusteredSamplesArray[i] * decayFactor;
        }
      }
    }
    return;
  } else if (mode == "Calibrator") {
    ///////////////////////

    // if(now - compTimer >= 30*1000){
    //     for (int i = 0; i < ADCSize; i++)
    //     {
    //         medMedOccCompVals[i] = medMedVals[i];
    //         medMedOccComp[i] = medMedOcc[i];
    //     }
        
    // }



    return;
  } else if (mode == "Tester") {
    ///////////////////////
    return;
  } else {
    for (int i = 0; i < 1000; i++) {
      Serial.println("ERROR --> MODE NOT FOUND <-- ERROR");
    }
  }
}