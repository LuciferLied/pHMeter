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
    printPadded(currentPumpTiming, 4);
    Serial.print(" | ");
    Serial.print("TitCD: ");
    printPadded((remaining / 1000), 4);
    Serial.print(" | ");
    Serial.print("totalTitTime: ");
    printPadded(pumpTotalONTime, 7);
    for (int k = 0; k < 31; k++) {
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
    Serial.print("CalibOccSTDDev: ");
    printFixedFloat(CalibOccSTDDev, 2, 6);
    Serial.print(" | ");
    Serial.print("CalibOccMedi: ");
    printPadded(CalibOccMedi, 6);
    Serial.print(" | ");
    Serial.print("CalibOccTrim: ");
    printFixedFloat(CalibOccTrim, 2, 6);
    for (int k = 0; k < 18; k++)
      Serial.print(" ");
    Serial.println("|/|");
    Serial.print(
        "|/|=======================================================================================|/|");
    Serial.println();
    Serial.print("|/| ");
    Serial.print("NrSmpls: ");
    printPadded(ammSamplesCollected, 6);
    Serial.print(" | ");
    Serial.print("minSmpls ");
    printPadded(minSmpls, 3);
    Serial.print(" | ");
    Serial.print("LrgWin: ");
    printPadded(largeWindowMult * 100, 2);
    Serial.print("%");
    Serial.print(" | ");
    Serial.print("MedWin: ");
    printPadded(mediumWindowMult * 100, 2);
    Serial.print("%");
    Serial.print(" | ");
    Serial.print("SmolWin: ");
    printPadded(smallWindowMult * 100, 2);
    Serial.print("%");
    Serial.print(" | ");
    Serial.print("Key{");
    Serial.print(keyStart);
    Serial.print("/");
    Serial.print(keyEnd);
    Serial.print("}");
    for (int k = 0; k < 0; k++)
      Serial.print(" ");
    Serial.println("|/|");
    Serial.println(
        "---------------------------------------------------------------------------------------------");
    Serial.println(
        "|/|ADC|OCCU|LARG|MEDI|SMOL|KEY|==========LOCKARRAY===================================|=PH=|/|");
    upperShift = 3;
    lowerShift = 1;
    currentKeyPrinted = 0;
    for (int i = 0; i < 100; i++) {
      int printedKeys = 0;
      if (calibOccurArr[i] < minSmpls) {
        continue;
      }
      if (i == keyStart || i == keyEnd + 1) {
        Serial.println("|/|=K=E=Y=K=E=Y=K=E=Y=K=E=Y=K=|/"
                       "|L=O=C=K=L=O=C=K=L=O=C=K=L=O=C=K=L=O=C=K=L=O=C=K=L=O=|    |/|");
      }
      Serial.print("|/|");
      printPadded(calibValueArr[i], 3);
      Serial.print("|");
      printPadded(calibOccurArr[i], 4);
      Serial.print("|");
      if (calibOccurArr[i] >= largeWindow) {
        printPadded(calibOccurArr[i], 4);
      } else {
        for (int k = 0; k < 4; k++) {
          Serial.print(" ");
        }
      }
      Serial.print("|");
      if (calibOccurArr[i] >= mediumWindow) {
        printPadded(calibOccurArr[i], 4);
      } else {
        for (int k = 0; k < 4; k++) {
          Serial.print(" ");
        }
      }
      Serial.print("|");
      if (calibOccurArr[i] >= smallWindow) {
        printPadded(calibOccurArr[i], 4);
      } else {
        for (int k = 0; k < 4; k++) {
          Serial.print(" ");
        }
      }
      Serial.print("|");
      if (calibOccurArr[i] >= smallWindow) {
        printPadded(calibValueArr[i], 3);
        Serial.print("==>");
      } else {
        for (int k = 0; k < 3; k++) {
          Serial.print(" ");
        }
      }
      if (calibOccurArr[i] >= smallWindow) {
        int keyinBothIndex = 0;
        bool printedAll = false;
        for (int k = 0; k < MaxKeySize; k++) {
          if (calibKeyBook[pHValuesIndex][k] == calibValueArr[i])
            keyinBothIndex = k;
        }
        for (int k = keyinBothIndex; k < MaxKeySize; k++) {
          if (maxPrintedKeys == printedKeys)
            break;
          if (k == keyinBothIndex && printedAll == true)
            break;
          if (calibKeyBook[pHValuesIndex][k] != 0) {
            Serial.print("{");
            Serial.print(calibKeyBook[pHValuesIndex][k]);
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
          Serial.print("000");
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
      if (calibOccurArr[i] < smallWindow) {
        int holderpHValueIndex = pHValuesIndex;
        Serial.print("|/|");
        if (i < keyStart - DistToLock && upperShift < maxShift) {
          holderpHValueIndex = getWrappedIndex(pHValuesIndex, -upperShift, diffPHVals);
          if (holderpHValueIndex != pHValuesIndex) {
            for (int k = 0; k < MaxKeySize; k++) {
              if (maxPrintedKeys == printedKeys)
                break;
              if (calibKeyBook[holderpHValueIndex][k] != 0) {
                Serial.print("{");
                Serial.print(calibKeyBook[holderpHValueIndex][k]);
                Serial.print("}");
                printedKeys++;
              }
            }
            for (int k = printedKeys; k < MaxKeySize; k++) {
              if (maxPrintedKeys == printedKeys)
                break;
              Serial.print("{");
              Serial.print("000");
              Serial.print("}");
              printedKeys++;
            }
            for (int k = 0; k < 0; k++) {
              Serial.print(" ");
            }
            Serial.print("|||");
            Serial.print(phValues[holderpHValueIndex]);

            upperShift--;
          } else { // WEIRD EDGE CASE - CORRECT LATER
            for (int k = 0; k < 50; k++) {
              Serial.print(" ");
            }
            Serial.print("|||    ");
          }
        } else if (keyEnd + DistToLock < i && lowerShift < maxShift) {
          holderpHValueIndex = holderpHValueIndex;
          holderpHValueIndex = getWrappedIndex(pHValuesIndex, lowerShift, diffPHVals);
          if (0 <= holderpHValueIndex && holderpHValueIndex < diffPHVals) {
            for (int k = 0; k < MaxKeySize; k++) {
              if (maxPrintedKeys == printedKeys)
                break;
              if (calibKeyBook[holderpHValueIndex][k] != 0) {
                Serial.print("{");
                Serial.print(calibKeyBook[holderpHValueIndex][k]);
                Serial.print("}");
                printedKeys++;
              }
            }
            for (int k = printedKeys; k < MaxKeySize; k++) {
              if (maxPrintedKeys == printedKeys)
               break;
              Serial.print("{");
              Serial.print("000");
              Serial.print("}");
              printedKeys++;
            }
            for (int k = 0; k < 0; k++) {
              Serial.print(" ");
            }
            Serial.print("|||");
            Serial.print(phValues[holderpHValueIndex]);
          }
          lowerShift++;
        } else {
          for (int k = 0; k < 50; k++) {
            Serial.print(" ");
          }
          Serial.print("|||    ");
        }
        Serial.println("|/|");
      }
    }
  } break;
  case 607: {
    // int helpLineIndex = 0;
    // switch (helpLineIndex)
    // {
    // case constant expression:
    //   /* code */
    //   break;

    // default:
    //   break;
    // }
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
  default: {

  } break;
  }
}