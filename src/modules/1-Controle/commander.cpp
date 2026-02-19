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
  if (incCommand == "key") {
    int currentKeyEntry = 0;
    showPHKey = false;
    keySamplerIte = 0;
    samplingComplete = false;
    showKeyDetails = false;
    idle = false;
    sampleKey = true;
    cleanKey();
  }
  if (incCommand == "lockkey") {
    sampleKey = false;
    idle = false;
    showKeyDetails = true;
    samplingComplete = false;
    lockCurrentCalibration();
    resetSampleKey();
  }
  if (incCommand == "tittime") {
    resetter();
    runPump = true;
    lastTitTime = now;
    pumpTotalONTime = pumpTotalONTime + currentPumpTiming;
    pump(now);
  }
  if (incCommand == "reset") {
    resetSampleKey();
  }
  if (incCommand.startsWith("win")) {
    int firstSpace = incCommand.indexOf(' ');
    if (firstSpace != -1) {
      String param = incCommand.substring(firstSpace + 1);
      param.trim();
      if (param == "reset")
        currentWindow = 0;
      else if (param == "large")
        currentWindow = 1;
      else if (param == "medi")
        currentWindow = 2;
      else if (param == "small")
        currentWindow = 3;
      else if (param == "key")
        currentWindow = 4;
    }
    windowSetting();
  }
  // if (incCommand.startsWith("sampletime ")) {
  //   // Extract after "sampletime ", convert to float, then to ms
  //   maxSampleTime = (unsigned long)(incCommand.substring(11).toFloat() * 1000.0f);
  // }
  if (incCommand.startsWith("tit+")) {
    int firstSpace = incCommand.indexOf(' ');
    if (firstSpace != -1) {
      String param = incCommand.substring(firstSpace + 1);
      param.trim();
      currentPumpTiming = param.toInt();
    }
  }
  if (incCommand.startsWith("minocc")) {
    int firstSpace = incCommand.indexOf(' ');
    if (firstSpace != -1) {
      String param = incCommand.substring(firstSpace + 1);
      param.trim();
      minSmpls = param.toInt();
    }
  }
  if (incCommand == "showkey") {
    if (showPHKey == true)
      showPHKey = false;
    else if (showPHKey == false)
      showPHKey = true;
  }
  if (incCommand == "emptypump") {
    runPump = true;
    currentPumpTiming = 10 * 1000;
    pump(now);
  }
  if (incCommand == "prev") {
    restoreFromProtector();
    if (pHValuesIndex == 0) {
      pHValuesIndex = diffPHVals - 1;
    } else {
      pHValuesIndex--;
    }
    showPHKey = true;
    newKeyInSampler = true;
    idle = true;
    sampleKey = false;
    showKeyDetails = false;
    samplingComplete = false;
  }
  if (incCommand == "next") {
    restoreFromProtector();
    if (pHValuesIndex == diffPHVals - 1) {
      pHValuesIndex = 0;
    } else {
      pHValuesIndex++;
    }
    showPHKey = true;
    newKeyInSampler = true;
    idle = true;
    sampleKey = false;
    showKeyDetails = false;
    samplingComplete = false;
  }
  if (incCommand.startsWith("ph ")) {
    float targetPH = incCommand.substring(3).toFloat();

    for (int i = 0; i < diffPHVals; i++) {
      // Standard 0.01 tolerance for exact 0.10 increment matching
      if (abs(phValues[i] - targetPH) < 0.01f) {
        restoreFromProtector();
        showPHKey = true;
        newKeyInSampler = true;
        idle = true;
        sampleKey = false;
        showKeyDetails = false;
        samplingComplete = false;
        pHValuesIndex = i;
        break;
      }
    }
  }
  if (incCommand == "led") {
    matrixPicker();
  }
  if (incCommand == "result") {
    printResults();
  }
  if (incCommand == "endcalibration") {
  }
  if (incCommand == "print") {
    if (print == false)
      print = true;
    else
      print = false;
  }
  incCommand = "";
}