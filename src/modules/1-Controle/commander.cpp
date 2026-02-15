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
  if (incCommand == "key"){
    for(int i = keyStart; i < keyEnd+1; i++ ){
      for(int k = 0; k < maxKeys; k++){
        if(calibKeyBook[pHValuesIndex][k] == 0){
          calibKeyBook[pHValuesIndex][k] = calibValueArr[i];
          break;
        }
      }
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
    currentPumpTiming = 10*1000;
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
  if (incCommand == "endcalibration") {
  }
  incCommand = "";
}