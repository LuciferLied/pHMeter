#include <config.h>

void syncShiftArrays(int values[], int occurrences[], int size) {
  highestOcc = 0;
  int tempMax = 0;

  for (int i = 0; i < size - 1; i++) {
    values[i] = values[i + 1];
    occurrences[i] = occurrences[i + 1];

    if (occurrences[i] > tempMax) {
      tempMax = occurrences[i];
    }
  }
  values[size - 1] = 0;
  occurrences[size - 1] = 0;

  highestOcc = tempMax;
}

void setWindows() {
  largeWindow = highestOcc * largeWindowMult;
  mediumWindow = highestOcc * mediumWindowMult;
  smallWindow = highestOcc * smallWindowMult;
  keyWindow = highestOcc * keyWindowMult;
}

void countSamples() {
  for (int i = 0; i < calibValArrSize; i++) {
    if (calibValueArr[i] != 0 && calibOccurArr[i] != 0) {
      ammSamplesCollected += calibOccurArr[i];
    }
  }
}

void findKey() {
  keyStart = 0;
  keyEnd = 0;
  int i = 0;
  for (i; i < calibValArrSize; i++) {
    if (calibOccurArr[i] >= keyWindow) {
      if (keyStart == 0) {
        keyStart = i;
      }
      if (keyStart != 0) {
        keyEnd = i + 1;
      }
    }
  }
}

void largestKey() {
  currLargestKey = 0;
  for (int i = 0; i < diffPHVals; i++) {
    int counter = 0;
    for (int k = 0; k < MaxKeySize; k++) {
      if (calibKeyBundle[i][k] != 0) {
        counter++;
      } else
        break;
    }
    if (counter > currLargestKey)
      currLargestKey = counter;
  }
}

int getWrappedIndex(int current, int offset, int size) {
  // Adding 'size' before modulo handles negative offsets perfectly
  return (current + offset + size) % size;
}

void cleanKey() {
  // Bounds check to prevent memory corruption
  if (pHValuesIndex < 0 || pHValuesIndex >= diffPHVals) return;

  for (int k = 0; k < MaxKeySize; k++) {
    // 1. Wipe the PIN identity
    calibKeyBundle[pHValuesIndex][k] = 0;

    // 2. Wipe the paired HI/LO percentages
    calibKeyBundlePerc[pHValuesIndex][k][0] = 0.0f;
    calibKeyBundlePerc[pHValuesIndex][k][1] = 0.0f;
  }
}

// void keyFromSamples(unsigned long now) { //possible spillover from ADCS in key into HIS array
//   if (sampleKey == true) {
//     // 1. Iterate through raw sample array
//     for (int i = keyStart; i < keyEnd; i++) {
//       bool exists = false;
//       int firstEmptyIndex = -1;

//       // Pre-calculate the current percentage as a float
//       float currentPerc = (calibOccurArr[i] * 100.0f) / 36000.0f;

//       // 2. Search the Staging Buffer
//       for (int k = 0; k < 63; k++) {
//         // Track first empty slot in Layer 0 (PIN/ADC)
//         if (calibSampleKeyHolder[0][k] == 0 && firstEmptyIndex == -1) {
//           firstEmptyIndex = k;
//         }

//         // Value exists: Update Occurrences and Hi/Lo percentages
//         if (calibSampleKeyHolder[0][k] == calibValueArr[i]) {
//           exists = true;
//           calibSampleKeyHolder[1][k]++; // Increment OCC (Layer 1)

//           // Update HI% in float array layer 0
//           if (currentPerc > calibSampleKeyPercHolder[0][k]) {
//             calibSampleKeyPercHolder[0][k] = currentPerc;
//           }
//           // Update LO% in float array layer 1
//           else if (currentPerc < calibSampleKeyPercHolder[1][k]) {
//             calibSampleKeyPercHolder[1][k] = currentPerc;
//           }
//           break;
//         }
//       }

//       // 3. New unique value: Initialize slots
//       if (!exists && firstEmptyIndex != -1) {
//         calibSampleKeyHolder[0][firstEmptyIndex] = calibValueArr[i]; // PIN
//         calibSampleKeyHolder[1][firstEmptyIndex] = 1;                // OCC
//         calibSampleKeyHolder[2][firstEmptyIndex] = 1;                // HIS (Init at 1 or OCC)

//         // Initialize HI/LO float percentages
//         calibSampleKeyPercHolder[0][firstEmptyIndex] = currentPerc;
//         calibSampleKeyPercHolder[1][firstEmptyIndex] = currentPerc;
//       }
//     }

//     sortKeyHolder();
//   }
// }

void keyFromSamples(unsigned long now) {
  if (!sampleKey)
    return; // Straight to the point

  for (int i = keyStart; i < keyEnd; i++) {
    int val = calibValueArr[i];
    if (val == 0)
      continue; // Ignore null samples

    bool exists = false;
    int firstEmptyIndex = -1;
    float currentPerc = (calibOccurArr[i] * 100.0f) / 36000.0f;

    for (int k = 0; k < 63; k++) {
      // 1. Correctly identify empty slot using PIN layer ONLY
      if (calibSampleKeyHolder[0][k] == 0) {
        if (firstEmptyIndex == -1)
          firstEmptyIndex = k;
        continue;
      }

      // 2. Check for match in PIN layer
      if (calibSampleKeyHolder[0][k] == val) {
        exists = true;
        calibSampleKeyHolder[1][k]++; // Update OCC

        // Update HI/LO Percentages in separate float array
        if (currentPerc > calibSampleKeyPercHolder[0][k])
          calibSampleKeyPercHolder[0][k] = currentPerc;
        if (currentPerc < calibSampleKeyPercHolder[1][k])
          calibSampleKeyPercHolder[1][k] = currentPerc;
        break;
      }
    }

    // 3. Insertion Logic - Explicitly set all 3 layers to prevent bleed
    if (!exists && firstEmptyIndex != -1) {
      calibSampleKeyHolder[0][firstEmptyIndex] = val; // PIN
      calibSampleKeyHolder[1][firstEmptyIndex] = 1;   // OCC
      calibSampleKeyHolder[2][firstEmptyIndex] = 1;   // HIS (Reset to 1, not 0)

      calibSampleKeyPercHolder[0][firstEmptyIndex] = currentPerc; // HI%
      calibSampleKeyPercHolder[1][firstEmptyIndex] = currentPerc; // LO%
    }
  }
  sortKeyHolder();
}

void updateHistory(unsigned long now) {
  for (int k = 0; k < 63; k++) {
    // Snapshot current OCC into Layer 2 (CMP)
    calibSampleKeyHolder[2][k] = calibSampleKeyHolder[1][k];
  }
}

// void decayWithHistory(unsigned long now) {
//   if (sampleKey == true && (now - lastPrinterTime >= printerCD) != true) {
//     // GATE 1: Decay (36s)
//     if (now - LastcalibKeyDecayTime >= (unsigned long)calibKeyDecayCD) {
//       LastcalibKeyDecayTime = now;

//       // Update history snapshot right before we modify the live counts
//       updateHistory(now);

//       bool changed = false;
//       for (int k = 0; k < 63; k++) {
//         if (calibSampleKeyHolder[1][k] > 0) {

//           // Apply Decay
//           calibSampleKeyHolder[1][k] *= calibKeyDecayFactor;

//           // GATE 2: Reset Check (60s)
//           if (now - lastCalibKeyResetTime >= CalibKeyResetCD) {
//             // If live count is lower than the snapshot we just took, wipe it
//             if (calibSampleKeyHolder[1][k] < calibSampleKeyHolder[2][k] - 36) {
//               for (int dim = 0; dim < 3; dim++) {
//                 calibSampleKeyHolder[dim][k] = 0;
//               }
//             }
//           }
//           changed = true;
//         }
//       }
//       if (now - lastCalibKeyResetTime >= CalibKeyResetCD) {
//         lastCalibKeyResetTime = now;
//       }
//       if (changed) {
//         sortKeyHolder();
//       }
//     }
//   }
// }

// void setLock() { /////put into next key if too many ADCVals
//   int currentKeyEntry = 0;
//   for (int i = 0; i < MaxKeySize; i++) {
//     calibKeyBundle[pHValuesIndex][i] = 0;
//   }
//   for (int i = keyStart; i < keyEnd; i++) {
//     if (currentKeyEntry >= MaxKeySize)
//       break;
//     int val = calibValueArr[i];
//     bool exists = false;
//     for (int j = 0; j < currentKeyEntry; j++) {
//       if (calibKeyBundle[pHValuesIndex][j] == val) {
//         exists = true;
//         break;
//       }
//     }
//     if (!exists) {
//       calibKeyBundle[pHValuesIndex][currentKeyEntry] = val;
//       currentKeyEntry++;
//     }
//   }
//   sortRow(pHValuesIndex, calibKeyBundle);
// }

void setLock() {
  if (sampleKey == true || idle == true) {
    int currentKeyEntry = 0;

    // 1. Clear current row - Safeguarded bound
    for (int i = 0; i < MaxKeySize; i++) {
      calibKeyBundle[pHValuesIndex][i] = 0;
    }

    // 2. Populate from calibValueArr
    for (int i = keyStart; i < keyEnd; i++) {
      // HARD LIMIT: Stop if we've filled the allowed slots
      if (currentKeyEntry >= MaxKeySize)
        break;

      int val = calibValueArr[i];
      bool exists = false;

      // Only check up to the current filled count
      for (int j = 0; j < currentKeyEntry; j++) {
        if (calibKeyBundle[pHValuesIndex][j] == val) {
          exists = true;
          break;
        }
      }

      if (!exists) {
        // Final check before write
        if (currentKeyEntry < MaxKeySize) {
          calibKeyBundle[pHValuesIndex][currentKeyEntry] = val;
          currentKeyEntry++;
        }
      }
    }

    // 3. Sort the resulting row
    sortRow(pHValuesIndex, calibKeyBundle);
  }
}

void historyAndDecay(unsigned long now) {
  if (!sampleKey) return; 
  const int minOccurrenceThreshold = 10;
  static unsigned long lastSlowDecayTime = 0; 

  // --- GATE 1: 12s INTERVAL (RESET, HIGH DECAY, MID LINEAR) ---
  if (now - LastcalibKeyDecayTime >= CMPUpdateCD) { 
    LastcalibKeyDecayTime = now;
    bool changed = false;

    for (int k = 0; k < 63; k++) {
      // 1. RESET LOGIC
      if (possibleReset[k][0] != 1) {
          possibleReset[k][1] = 0; 
      }
      else if (possibleReset[k][1] >= 3) {
          for(int d=0; d<3; d++) calibSampleKeyHolder[d][k] = 0;
          for(int d=0; d<2; d++) calibSampleKeyPercHolder[d][k] = 0.0f;
          possibleReset[k][1] = 0; 
          changed = true;
          continue; 
      }

      // 2. DECAY LOGIC
      int val = calibSampleKeyHolder[1][k];
      if (val >= 20) {
        // ZONE 1: Percentage decay
        int nextVal = (int)((float)val * calibKeyDecayFactor);
        if (nextVal >= val) nextVal = val - 1;
        calibSampleKeyHolder[1][k] = nextVal;
        changed = true;
      } 
      else if (val >= 10 && val < 20) {
        // ZONE 2: Linear -1 every 12s
        calibSampleKeyHolder[1][k] = val - 1;
        changed = true;
      }
    }
    if (changed) sortKeyHolder();
  }

  // --- GATE 2: 54s INTERVAL (LOW LINEAR) ---
  if (now - lastSlowDecayTime >= 54000) { 
    lastSlowDecayTime = now;
    bool changed = false;

    for (int k = 0; k < 63; k++) {
      int val = calibSampleKeyHolder[1][k];
      // ZONE 3: Linear -1 every 54s for values below 10
      if (val > 0 && val < 10) {
        calibSampleKeyHolder[1][k] = val - 1;
        changed = true;
      }
    }
    if (changed) sortKeyHolder();
  }

  // --- GATE 3: 36s INTERVAL (HISTORY SYNC) ---
  if (now - lastCMPUpdateTime >= calibKeyDecayCD) { 
    lastCMPUpdateTime = now;

    for (int k = 0; k < 63; k++) {
      int occ = calibSampleKeyHolder[1][k];
      int his = calibSampleKeyHolder[2][k];

      if (occ > 0 || his > 0) {
        if (occ < 2 && his < 2) {
          for(int d=0; d<3; d++) calibSampleKeyHolder[d][k] = 0;
          for(int d=0; d<2; d++) calibSampleKeyPercHolder[d][k] = 0.0f;
          continue;
        }
        calibSampleKeyHolder[2][k] = occ;
      }
    }
  }
}

void lockCurrentCalibration() {
  if (pHValuesIndex < 0 || pHValuesIndex >= diffPHVals) return;

  // --- 1. PROTECT: Backup current data to protector before wiping ---
  for (int k = 0; k < MaxKeySize; k++) {
    keyProtector[k] = calibKeyBundle[pHValuesIndex][k];
    keyPercProtector[k][0] = calibKeyBundlePerc[pHValuesIndex][k][0];
    keyPercProtector[k][1] = calibKeyBundlePerc[pHValuesIndex][k][1];
  }

  // --- 2. PREPARE: Find peak occurrence for thresholding ---
  int maxOcc = 0;
  for (int i = 0; i < MaxKeySize; i++) {
    if (calibSampleKeyHolder[1][i] > maxOcc) {
      maxOcc = calibSampleKeyHolder[1][i];
    }
  }

  // Clear target row in bundle to ensure no legacy data remains
  for (int i = 0; i < MaxKeySize; i++) {
    calibKeyBundle[pHValuesIndex][i] = 0;
    calibKeyBundlePerc[pHValuesIndex][i][0] = 0.0f; 
    calibKeyBundlePerc[pHValuesIndex][i][1] = 0.0f; 
  }

  // --- 3. TRANSFER: Filter and write staging data to bundle ---
  int threshold = (int)(maxOcc * 0.10f);
  int targetIdx = 0;

  for (int sourceIdx = 0; sourceIdx < MaxKeySize; sourceIdx++) {
    if (targetIdx >= MaxKeySize) break;

    int key = calibSampleKeyHolder[0][sourceIdx];
    int occ = calibSampleKeyHolder[1][sourceIdx];

    // Transfer only if valid PIN exists and meets 10% peak requirement
    if (key > 0 && occ >= threshold && occ > 0) {
      calibKeyBundle[pHValuesIndex][targetIdx] = key;
      calibKeyBundlePerc[pHValuesIndex][targetIdx][0] = calibSampleKeyPercHolder[0][sourceIdx];
      calibKeyBundlePerc[pHValuesIndex][targetIdx][1] = calibSampleKeyPercHolder[1][sourceIdx];
      targetIdx++;
    }
  }
}

void updateSamplingState(unsigned long now) {
  if (!sampleKey) {
    // Optional: Reset if you want it to trigger fresh next time sampleKey is toggled
    // sampleStartTime = 0;
    return;
  }

  // Initial trigger
  if (sampleStartTime == 0) {
    sampleStartTime = now;
    samplingComplete = false;
  }

  // Check for completion using the 'now' timestamp
  if (!samplingComplete && (now - sampleStartTime >= (maxSampleTime * 1000))) {
    samplingComplete = true;
  }
}


void resetSampleKey() {
  // 1. Wipe all count history (Dimensions: 0=Values, 1=Occurrences, 2=Baseline)
  for (int d = 0; d < 3; d++) {
    for (int k = 0; k < 63; k++) {
      calibSampleKeyHolder[d][k] = 0;
    }
  }

  // 2. Wipe all percentage data
  for (int d = 0; d < 2; d++) {
    for (int k = 0; k < 63; k++) {
      calibSampleKeyPercHolder[d][k] = 0.0f;
    }
  }

  // 3. Reset Timing/State Variables
  sampleKey = false;
  LastcalibKeyDecayTime = 0;
  lastCMPUpdateTime = 0;

  // 4. Force a sort to clear the display structure
  sortKeyHolder();
}

void protectKey() {
  // Ensure we are within array bounds before accessing
  if (pHValuesIndex < 0 || pHValuesIndex >= diffPHVals) return;

  for (int k = 0; k < MaxKeySize; k++) {
    int currentPin = calibKeyBundle[pHValuesIndex][k];

    if (currentPin > 0) {
      // Data exists: Map PIN and Percentages row-wise
      keyProtector[k] = currentPin;
      keyPercProtector[k][0] = calibKeyBundlePerc[pHValuesIndex][k][0]; // HI%
      keyPercProtector[k][1] = calibKeyBundlePerc[pHValuesIndex][k][1]; // LO%
    } else {
      // No data: Explicitly zero out to maintain integrity for this row index
      keyProtector[k] = 0;
      keyPercProtector[k][0] = 0;
      keyPercProtector[k][1] = 0;
    }
  }
}

void restoreFromProtector() {
  if (pHValuesIndex < 0 || pHValuesIndex >= diffPHVals) return;

  for (int k = 0; k < MaxKeySize; k++) {
    calibKeyBundle[pHValuesIndex][k] = keyProtector[k];
    calibKeyBundlePerc[pHValuesIndex][k][0] = keyPercProtector[k][0];
    calibKeyBundlePerc[pHValuesIndex][k][1] = keyPercProtector[k][1];

    // Safety: ensure stale percentages don't exist if PIN is 0
    if (keyProtector[k] == 0) {
      calibKeyBundlePerc[pHValuesIndex][k][0] = 0.0f;
      calibKeyBundlePerc[pHValuesIndex][k][1] = 0.0f;
    }
  }
}