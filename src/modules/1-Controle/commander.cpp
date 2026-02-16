#include <config.h>
// Commands are not cAsEsEnSiTiVe

void commander(unsigned long now) {
  incCommand.toLowerCase();
  if (incCommand == "") {
    return;
  }
  if (incCommand == "Doser") {
    mode = "doser";
    // reset
  }
  if (incCommand == "calibrate") {
    mode = "Calibrator";
    // resetc
  }

  if (incCommand == "rawanal") {
  }
  if (incCommand == "log") {
    clusterCenters[pHValuesIndex] = mediOfTrim;
    stdDevArr[pHValuesIndex] = stdDevOfTrim;
    pumpTotalONTime = 0;
    pHValuesIndex++;
  }
  if (incCommand == "key") {
    int currentKeyEntry = 0;
    for(int i = 0; i < MaxKeySize; i++){
      calibKeyBook[pHValuesIndex][i] = 0;
    }
    for (int i = keyStart; i < keyEnd; i++) {
      if (currentKeyEntry == MaxKeySize) {
        break;
      }
      calibKeyBook[pHValuesIndex][currentKeyEntry] = calibValueArr[i];
      currentKeyEntry++;
    }
    sortRow(pHValuesIndex, calibKeyBook);
  }
  if (incCommand == "tittime") {
    resetter();
    runPump = true;
    lastTitTime = now;
    pumpTotalONTime = pumpTotalONTime + titTimeSetting;
    pump(now);
  }
  if (incCommand == "reset") {
    resetter();
  }
  if (incCommand == "tit+") {
    titTimeSetting = titTimeSetting + 10;
  }
  if (incCommand == "tit++") {
    titTimeSetting = titTimeSetting + 25;
  }
  if (incCommand == "tit+++") {
    titTimeSetting = titTimeSetting + 100;
  }
  if (incCommand == "tit++++") {
    titTimeSetting = titTimeSetting + 200;
  }
  if (incCommand == "tit-") {
    titTimeSetting = titTimeSetting - 10;
  }
  if (incCommand == "tit--") {
    titTimeSetting = titTimeSetting - 25;
  }
  if (incCommand == "tit---") {
    titTimeSetting = titTimeSetting - 100;
  }
  if (incCommand == "tit----") {
    titTimeSetting = titTimeSetting - 200;
  }
  if (incCommand == "emptypump") {
    runPump = true;
    currentPumpTiming = 10 * 1000;
    pump(now);
  }
  if (incCommand == "prev") {
    if (pHValuesIndex == 0) {
      pHValuesIndex = diffPHVals - 1;
    } else {
      pHValuesIndex--;
    }
  }
  if (incCommand == "next") {
    if (pHValuesIndex == diffPHVals - 1) {
      pHValuesIndex = 0;
    } else {
      pHValuesIndex++;
    }
  }
  if (incCommand == "led") {
    matrixPicker();
  }
  if (incCommand == "result") {
    Serial.println("Insertable values");
    Serial.println("int clusterCenters[diffPHVals] = {");
    int j = 0;
    for (int i = 0; i < 7; i++) {
      for (int k = 0; k < 5; k++) {
        Serial.print(clusterCenters[j]);
        Serial.print(",");
        j++;
        if (j == diffPHVals) {
          k = 5, i = 7;
        }
      }
      Serial.println("");
    }
    Serial.println("};");

    Serial.println("Insertable values");
    Serial.println("int stdDev[diffPHVals] = {");
    j = 0;
    for (int i = 0; i < 7; i++) {
      for (int k = 0; k < 5; k++) {
        Serial.print(stdDevArr[j]);
        Serial.print(",");
        j++;
        if (j == diffPHVals) {
          k = 5, i = 7;
        }
      }
      Serial.println("");
    }
    Serial.println("};");
  }
  if(incCommand == "phase0"){
    minSmpls = 200;
    largeWindowMult = 0.10;
    mediumWindowMult = 0.36;
    smallWindowMult = 0.60;
    largeWindow = 0;
    mediumWindow = 0;
    smallWindow = 0;
  }
  if(incCommand == "phase1"){
    minSmpls = 600;
    largeWindowMult = mediumWindowMult;
  }
  if(incCommand == "phase2"){
    minSmpls = highestOcc * (smallWindowMult-0.10);
    largeWindowMult = smallWindowMult;
    mediumWindowMult = smallWindowMult;
    DistToLock = 1;
  }
  if (incCommand == "endcalibration") {
  }
  if (incCommand == "print") {
    if(print == false)
      print = true;
    else
      print = false;
  }
  incCommand = "";
}