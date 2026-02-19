#include <config.h>
int z = 0;
void linePrinter(unsigned long now, int line) {
  printerCD = 20 * 1000;
  switch (line) {
  case 0: {
    Serial.print(
        "|/|B=E=G=I=N=N=I=N=G=B=E=G=I=N=N=I=N=G=B=E=G=I=N=N=I=N=G=B=E=G=I=N=N=I=N=G=B=E=G=I=N=N=I=N|/|");
    Serial.println();
    Serial.print("|/| ");
    Serial.print("V0.0.9");
    Serial.print(" | ");
    Serial.print("prntNr: ");
    printPadded(printIteration, 4);
    Serial.print(" | ");
    Serial.print("Mode: ");
    Serial.print(mode);
    Serial.print(" | ");
    Serial.print("phase: ");
    for (int k = 0; k < 36; k++)
      Serial.print(" ");
    Serial.println("|/|");

    unsigned long elapsed = 0;
    unsigned long remaining = 0;
    Serial.print(
        "|/|---------------------------------------------------------------------------------------|/|");
    Serial.println();
    Serial.print("|/| ");
    Serial.print("PH: ");
    Serial.print(currentPH);
    Serial.print(" | ");
    if (mode == "Doser") {
      if (phase == "Watching") {
        Serial.print("SetterCD: ");
        elapsed = millis() - lastSetterTime;
        remaining = (elapsed < setterCD) ? (setterCD - elapsed) : 0;
      }
      if (phase == "Lowering") {
        Serial.print("pumpCD: ");
        elapsed = millis() - lastPumpTime;
        remaining = (elapsed < pumpCD) ? (pumpCD - elapsed) : 0;
      }
    } else if (mode == "Calibrator") {
      Serial.print("titCD: ");
      elapsed = millis() - lastTitTime;
      remaining = (elapsed < titCD) ? (titCD - elapsed) : 0;
    }
    printPadded((remaining / 1000), 4);
    Serial.print(" | ");
    if (mode == "Doser") {
      Serial.print("PumpTime: ");
      printPadded(currentPumpTiming, 4);
      Serial.print("(ms)");
      Serial.print("          |/| ");
    } else if (mode == "Calibrator") {
    }
    for (int k = 0; k < 61; k++)
      Serial.print(" ");
    Serial.println("|/|");
  } break;
  case 1: {
    Serial.print("|/|===PH===ClUSTER==SAMPLES=================================|/|");
    Serial.println();
  } break;
  case 2: {
    for (int i = 0; i < diffPHVals; i++) {
      int sample = clusteredSamplesArray[i];

      Serial.print("|/|");

      if (currentPH == phValues[i]) {
        // Active Row: Uses arrows
        Serial.print("->");
        Serial.print(phValues[i]);
        Serial.print("<-|->");
        Serial.print(clusterCenters[i]);
        Serial.print("<-|->");

        // Fixed-width Sample Container (Width of 5)
        int chars = Serial.print(sample);
        Serial.print("<-");
        for (int s = 0; s < (5 - chars); s++)
          Serial.print(" ");
      } else {
        // Normal Row: Uses spaces to match the arrows exactly
        Serial.print("  "); // Matches "->"
        Serial.print(phValues[i]);
        Serial.print("  |  "); // Matches "<-|->" (5 chars)
        Serial.print(clusterCenters[i]);
        Serial.print("  |  "); // Matches "<-|->" (5 chars)

        // Fixed-width Sample Container (Width of 5)
        int chars = Serial.print(sample);
        for (int s = 0; s < (5 - chars); s++)
          Serial.print(" ");

        Serial.print("  "); // Matches "<-"
      }

      Serial.println("|/|");
    }
  } break;
  case 4: {

  } break;
  case 5: {

  } break;
  case 6: {

  } break;
  case 600: {
    Serial.print("|/|========================================================================|/|");
    Serial.println();
    Serial.print("|/| ");
    Serial.print("stdDevOfADC: ");
    printFixedFloat(stdDevOfADC, 2, 4);
    Serial.print("stdDevOfTrim: ");
    printFixedFloat(stdDevOfTrim, 2, 4);
    Serial.print(" | ");
    Serial.print("trimOfTrim: ");
    printFixedFloat(trimOfTrim, 2, 6);
    Serial.print(" | ");
    Serial.print("mediOfTrim: ");
    printFixedFloat(mediOfTrim, 2, 6);
    Serial.print(" | ");
    Serial.print("(");
    printPadded(trimMeanArrayIndex, 3);
    Serial.print("/");
    Serial.print(trimMeanArrSize);
    Serial.print(")");
    if (enoughSamples == true) {
      printPaddedText("(READY)", 5);
    } else {
      printPaddedText("(WAIT)", 7);
    }
    Serial.print(" |/|");
    Serial.println();
  } break;
  case 601: {
    unsigned long elapsed = millis() - lastTitTime;
    unsigned long remaining = (elapsed < titCD) ? (titCD - elapsed) : 0;
    Serial.print(
        "|/|=======================================================================================|/|");
    Serial.println();
    Serial.print("|/| ");
    Serial.print("titTime(ms): ");
    printPadded(currentPumpTiming, 8);
    Serial.print(" | ");
    Serial.print("TitCD: ");
    printPadded((remaining / 1000), 4);
    Serial.print(" | ");
    Serial.print("totalTitTime: ");
    printPadded(pumpTotalONTime, 10);
    for (int k = 0; k < 24; k++) {
      Serial.print(" ");
    }
    Serial.println("|/|");
  } break;
  case 602: {
    Serial.print("|/|==PH======CLUSTERCENTER===STDDEV=========================|/|");
    Serial.println();
    int colWidth = 6;
    for (size_t i = 0; i < diffPHVals; i++) {
      Serial.print("|/| ");
      printFixedFloat(phValues[i], 2, colWidth);
      Serial.print(" | ");
      printFixedFloat(clusterCenters[i], 6, colWidth);
      Serial.println(" |/|");
    }

  } break;
  case 603: {
    Serial.print(
        "|/|=======================================================================================|/|");
    Serial.println();
    Serial.print("|/| ");
    Serial.print("OccSTDDev: ");
    printFixedFloat(CalibOccSTDDev, 2, 6);
    Serial.print(" | ");
    Serial.print("OccMedian: ");
    printPadded(CalibOccMedi, 6);
    Serial.print(" | ");
    Serial.print("OccTrimMean: ");
    printFixedFloat(CalibOccTrim, 2, 6);
    for (int k = 0; k < 27; k++)
      Serial.print(" ");
    Serial.println("|/|");
    Serial.print(
        "|/|=======================================================================================|/|");
    Serial.println();
    Serial.print("|/|");
    Serial.print("NrSmpls:");
    printPadded(ammSamplesCollected, 6);
    Serial.print("|");
    Serial.print("minOcc:");
    printPadded(minSmpls, 4);
    Serial.print("|");
    Serial.print("LrgWin:");
    printPadded(largeWindowMult * 100, 2);
    Serial.print("%");
    Serial.print("|");
    Serial.print("MedWin:");
    printPadded(mediumWindowMult * 100, 2);
    Serial.print("%");
    Serial.print("|");
    Serial.print("SmolWin:");
    printPadded(smallWindowMult * 100, 2);
    Serial.print("%");
    Serial.print("|");
    Serial.print("KeyWin:");
    printPadded(keyWindowMult * 100, 2);
    Serial.print("%");
    Serial.print("|");
    Serial.print("Key{");
    Serial.print(keyStart);
    Serial.print("/");
    Serial.print(keyEnd);
    Serial.print("}");
    for (int k = 0; k < 5; k++)
      Serial.print(" ");
    Serial.println("|/|");
    Serial.println(
        "---------------------------------------------------------------------------------------------");

    ////UPPER LOCK
    Serial.println(
        "|/|ADC|OCCU|LARG|MEDI|SMOL|KEY|=|======================LOCKARRAY===================|||=PH=|/|");
    upperShift = maxShift;
    lowerShift = 0;
    currentKeyPrinted = 0;
    for (int i = 0; i < 100; i++) {
      int printedKeys = 0;
      if (calibOccurArr[i] < minSmpls) {
        continue;
      }
      if (i == keyStart || i == keyEnd) {
        Serial.println("|/|=K=E=Y=K=E=Y=K=E=Y=K=E=Y=K=|/"
                       "|L=O=C=K=L=O=C=K=L=O=C=K=L=O=C=K=L=O=C=K=L=O=C=K=L=|||    |/|");
      }
      Serial.print("|/|");
      printPadded(calibValueArr[i], 3); ///// 0. ADC'S

      Serial.print("|");
      printPadded(calibOccurArr[i], 4); /////  1. OCC

      Serial.print("|");
      if (calibOccurArr[i] >= largeWindow) { // LargeWin
        printPadded(calibOccurArr[i], 4);
      } else {
        for (int k = 0; k < 4; k++) {
          Serial.print(" ");
        }
      }

      Serial.print("|");
      if (calibOccurArr[i] >= mediumWindow) { /// MEDWIN
        printPadded(calibOccurArr[i], 4);
      } else {
        for (int k = 0; k < 4; k++) {
          Serial.print(" ");
        }
      }

      Serial.print("|");
      if (calibOccurArr[i] >= smallWindow) { // SMOLWIN
        printPadded(calibOccurArr[i], 4);
      } else {
        for (int k = 0; k < 4; k++) {
          Serial.print(" ");
        }
      }
      Serial.print("|");
      if (calibOccurArr[i] >= keyWindow) { // KEY
        printPadded(calibValueArr[i], 3);
        Serial.print("==>");
      } else {
        for (int k = 0; k < 3; k++) {
          Serial.print(" ");
        }
      }

      if (calibOccurArr[i] >= keyWindow) { /// IF PART OF KEY
        int keyinBothIndex = 0;
        bool printedAll = false;
        for (int k = 0; k < MaxKeySize; k++) {
          if (calibKeyBundle[pHValuesIndex][k] == calibValueArr[i])
            keyinBothIndex = k;
        }
        for (int k = keyinBothIndex; k < MaxKeySize; k++) {
          if (maxPrintedKeys == printedKeys)
            break;
          if (k == keyinBothIndex && printedAll == true)
            break;
          if (calibKeyBundle[pHValuesIndex][k] != 0) {
            Serial.print("{");
            Serial.print(calibKeyBundle[pHValuesIndex][k]); //// PRINT REAL
            Serial.print("}");
            printedKeys++;
            if (printedAll == false && k == MaxKeySize - 1) {
              k = 0;
              printedAll = true;
            }
          }
        }
        for (int k = printedKeys; k < MaxKeySize; k++) {
          if (maxPrintedKeys == printedKeys)
            break;
          Serial.print("{");
          Serial.print("000"); ///// PRINT FAKE
          Serial.print("}");
          printedKeys++;
        }
        Serial.print("==>");
        Serial.print(phValues[pHValuesIndex]);
        for (int k = 0; k < 0; k++) {
          Serial.print(" ");
        }
        Serial.print("|");
        Serial.print(currentKeyPrinted);
        if (currentKeyPrinted < maxPrintedKeys)
          Serial.println("|");
        currentKeyPrinted++;
      }
      if (calibOccurArr[i] < keyWindow) { ////IF NOT PART OF KEY
        Serial.print("|/|");

        int holderpHValueIndex = -1;

        // 1. UPPER NEIGHBORS (Data at -4, -3, -2 | Gap at -1)
        if (i >= (keyStart - 4) && i <= (keyStart - 2)) {
          // Offset logic: i=(keyStart-2) -> offset 1, i=(keyStart-4) -> offset 3
          int offset = (keyStart - 1) - i;
          holderpHValueIndex = getWrappedIndex(pHValuesIndex, -offset, diffPHVals);
        }
        // 2. LOWER NEIGHBORS (Gap at keyEnd | Data at +1, +2, +3)
        else if (i >= (keyEnd + 1) && i <= (keyEnd + 3)) {
          // Since keyEnd is the spacer, i=(keyEnd+1) is neighbor offset 1
          int offset = i - keyEnd;
          holderpHValueIndex = getWrappedIndex(pHValuesIndex, offset, diffPHVals);
        }

        // --- RENDER BLOCK ---
        if (holderpHValueIndex != -1) {
          printedKeys = 0;
          for (int k = 0; k < MaxKeySize; k++) {
            if (printedKeys >= maxPrintedKeys)
              break;
            int val = calibKeyBundle[holderpHValueIndex][k];
            if (val != 0) {
              Serial.print("{");
              printPadded(val, 3);
              Serial.print("}");
              printedKeys++;
            }
          }
          while (printedKeys < maxPrintedKeys) {
            Serial.print("{000}");
            printedKeys++;
          }
          Serial.print("|||");

          // Width 6 for 2 decimals: " X.XX "
          printFixedFloat(phValues[holderpHValueIndex], 2, 3);
        } else {
          // Empty formatted rows (Everything else, including spacers)
          for (int k = 0; k < 50; k++) {
            Serial.print(" ");
          }
          // Spacing here must match the width of the printFixedFloat column (6 chars)
          Serial.print("|||    ");
        }

        Serial.println("|/|");
      }
    }
    Serial.println(
        "|/|ADC|OCCU|LARG|MEDI|SMOL|KEY|/|======================LOCKARRAY===================|||=PH=|/|");
  } break;
  case 604: {
    // Find the last index that actually has data (OCC > 0)
    int lastActiveIndex = -1;
    for (int k = 62; k >= 0; k--) {
      if (calibSampleKeyHolder[1][k] > 0) {
        lastActiveIndex = k;
        break;
      }
    }

    // If no data, just print a "No Data" row or exit
    if (lastActiveIndex == -1) {
      Serial.println("|/| NO DATA |/|");
      break;
    }

    // Process only as many 21-column chunks as needed
    for (int chunkStart = 0; chunkStart <= lastActiveIndex; chunkStart += 21) {
      int chunkEnd = chunkStart + 21;
      if (chunkEnd > 63)
        chunkEnd = 63; // Hard limit

      // --- 1. HEADER ---
      Serial.print("|/|=====");
      for (int i = chunkStart; i < chunkEnd; i++) {
        int colNum = i + 1;
        Serial.print(colNum);
        if (i < chunkEnd - 1) {
          if (colNum < 10)
            Serial.print("===");
          else if (colNum < 100)
            Serial.print("==");
        }
      }
      Serial.println("|/|");

      // --- 2. PIN ROW ---
      Serial.print("|/|PIN|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printPadded(calibSampleKeyHolder[0][i], 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- 3. OCC ROW ---
      Serial.print("|/|OCC|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printPadded(calibSampleKeyHolder[1][i], 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- 4. HIS ROW ---
      Serial.print("|/|HIS|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printPadded(calibSampleKeyHolder[2][i], 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- 5. HI% ROW ---
      Serial.print("|/|HI%|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printFixedFloat(calibSampleKeyPercHolder[0][i], 1, 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- 6. LO% ROW ---
      Serial.print("|/|LO%|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printFixedFloat(calibSampleKeyPercHolder[1][i], 1, 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");
    }
  } break;
  case 605: {
    if (sampleStartTime == 0) {
      Serial.println("|/| STATUS: IDLE |/|");
      break;
    }

    const int barWidth = 87;
    unsigned long durationMs = maxSampleTime * 1000;
    unsigned long elapsed = millis() - sampleStartTime;
    if (elapsed > durationMs)
      elapsed = durationMs;

    float progress = (float)elapsed / (float)durationMs;
    int pos = (int)(barWidth * progress);

    // Buffer for centered text
    char label[24];
    if (samplingComplete) {
      sprintf(label, " SAMPLING COMPLETE ");
    } else {
      sprintf(label, " PROGRESS: %3d%% ", (int)(progress * 100));
    }

    int labelLen = strlen(label);
    int labelStart = (barWidth / 2) - (labelLen / 2);

    // --- Render ---
    Serial.print("|/|");
    for (int b = 0; b < barWidth; b++) {
      // Label overlap check
      if (b >= labelStart && b < (labelStart + labelLen)) {
        Serial.print(label[b - labelStart]);
      }
      // Bar fill
      else {
        if (b < pos)
          Serial.print("=");
        else if (b == pos && !samplingComplete)
          Serial.print(">");
        else if (b == pos && samplingComplete)
          Serial.print("=");
        else
          Serial.print(" ");
      }
    }
    Serial.println("|/|");
  } break;
  case 606: {
    const int totalWidth = 87;
    char title[32];

    // 1. Create the core text: "PH X.Y SAMPLED KEY"
    // Using %.1f for the float value from your array
    sprintf(title, " PH %.1f SAMPLED KEY ", phValues[pHValuesIndex]);

    int titleLen = strlen(title);
    int sideBarLen = (totalWidth - titleLen) / 2;

    // 2. Render the line
    Serial.print("|/|");

    // Left side symbols
    for (int i = 0; i < sideBarLen; i++)
      Serial.print("=");

    // The actual text
    Serial.print(title);

    // Right side symbols (accounting for odd numbers with totalWidth % 2)
    int rightSideLen = totalWidth - titleLen - sideBarLen;
    for (int i = 0; i < rightSideLen; i++)
      Serial.print("=");

    Serial.println("|/|");
    ////////////////////////////////////////////////////////////
    // Process the bundle buffer in chunks of 21 for terminal width
    for (int chunkStart = 0; chunkStart < MaxKeySize; chunkStart += 21) {
      int chunkEnd = min(chunkStart + 21, MaxKeySize);

      // --- 1. HEADER (Decorative indices) ---
      Serial.print("|/|=====");
      for (int i = chunkStart; i < chunkEnd; i++) {
        int colNum = i + 1;
        Serial.print(colNum);
        if (i < chunkEnd - 1) {
          if (colNum < 10)
            Serial.print("===");
          else if (colNum < 100)
            Serial.print("==");
        }
      }
      Serial.println("|/|");

      // --- 2. ADC ROW (calibKeyBundle) ---
      Serial.print("|/|ADC|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printPadded(calibKeyBundle[pHValuesIndex][i], 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- 3. HI% ROW (calibKeyBundlePerc index 0) ---
      Serial.print("|/|HI%|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printFixedFloat(calibKeyBundlePerc[pHValuesIndex][i][0], 1, 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- 4. LO% ROW (calibKeyBundlePerc index 1) ---
      Serial.print("|/|LO%|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printFixedFloat(calibKeyBundlePerc[pHValuesIndex][i][1], 1, 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");
    }
  } break;
  case 607: {
    Serial.println(
        "|/|=======================================COMMANDS========================================|/|");
    Serial.println(
        "|/| changeph: PREV/NEXT | setTitTime: TIT+ XXX | startTit: TITTIME | emptyPump: EMPTYPUMP |/|");
    Serial.println(
        "|/| sampleKey:   KEY    | setKey:     LOCKKEY  | winScope: WIN RESET/LARGE/MEDI/SMALL/KEY |/|");
    Serial.println(
        "|/| printResult: RESULT | togglePrint: PRINT   | minOccSet: MINOCC XXX                    |/|");
  } break;
  case 999: {
    Serial.println(
        "|/|E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N=D=E=N|/|");
    // Serial.println();
    // Serial.println();
    // Serial.println();
    // Serial.println();
    // Serial.println();
    // Serial.println();
    // Serial.println();
    // Serial.println();
  } break;
  case 608: { // Using a new case number for the Protector view
    // 1. Find the last index in the protector that has a valid PIN
    int lastActiveIndex = -1;
    for (int k = MaxKeySize - 1; k >= 0; k--) {
      if (keyProtector[k] > 0) {
        lastActiveIndex = k;
        break;
      }
    }

    if (lastActiveIndex == -1) {
      Serial.println("|/| PROTECTOR EMPTY |/|");
      break;
    }

    // 2. Process in chunks of 21 for serial monitor width
    for (int chunkStart = 0; chunkStart <= lastActiveIndex; chunkStart += 21) {
      int chunkEnd = chunkStart + 21;
      if (chunkEnd > MaxKeySize)
        chunkEnd = MaxKeySize;

      // --- HEADER ---
      Serial.print("|/|=====");
      for (int i = chunkStart; i < chunkEnd; i++) {
        int colNum = i + 1;
        Serial.print(colNum);
        if (i < chunkEnd - 1) {
          if (colNum < 10)
            Serial.print("===");
          else if (colNum < 100)
            Serial.print("==");
        }
      }
      Serial.println("|/|");

      // --- PIN ROW (keyProtector) ---
      Serial.print("|/|PIN|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printPadded(keyProtector[i], 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- HI% ROW (keyPercProtector[i][0]) ---
      Serial.print("|/|HI%|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printFixedFloat(keyPercProtector[i][0], 1, 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      // --- LO% ROW (keyPercProtector[i][1]) ---
      Serial.print("|/|LO%|");
      for (int i = chunkStart; i < chunkEnd; i++) {
        printFixedFloat(keyPercProtector[i][1], 1, 3);
        if (i < chunkEnd - 1)
          Serial.print("|");
      }
      Serial.println("|/|");

      Serial.println(""); // Spacer between chunks
    }
  } break;
  default: {

  } break;
  }
}