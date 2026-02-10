#include <Arduino.h>
#include <config.h>
#include <vector>

void linePrinter(int line){
  switch(line){
    case 0:
    {
      Serial.print("|/|=========================================================|/|");
      Serial.println();
      Serial.print("|/|");
      Serial.print("Version: 0.0.8");
      Serial.print(" | ");      
      Serial.print("timesPrinted: ");
      printPadded(printIteration, 7);
      Serial.print(" | ");
      Serial.print("CurrentPH: ");
      Serial.print (currentPH);     
      Serial.print(" |/|");

      // Serial.print("phase:  ");
      // if(watching == true){
      //   Serial.print("Watching");
      // }
      // if(lowering == true){
      //   Serial.print("Lowering");
      // }
      // if(calibrating == true){
      //   Serial.print("Watching");
      // }
      //Serial.print(" |/|");
      Serial.println();
    }
    break;
    case 1:
    {
      Serial.print("|/|===PH===ClUSTER==SAMPLES=================================|/|");
      Serial.println();
    }
    break;
    case 2:
    {
    int phWidth = 1;
    if(10 <= currentPH && currentPH < 100)
      phWidth = 2;
    if(100 <= currentPH && currentPH < 1000)
      phWidth = 3;
    if(1000 <= currentPH && currentPH < 10000)
      phWidth = 4;
    for(int i = 0; i < diffPHVals; i++){
      int sample = clusteredArray[i];
      int sampleColWidth = 1;
      if(10 <= sample && sample < 100)
        sampleColWidth = 2;
      if(100 <= sample && sample < 1000)
        sampleColWidth = 3;
      if(1000 <= sample && sample < 10000)
        sampleColWidth = 4;
      Serial.print("|/|");
      if(currentPH == phValues[i]){
        Serial.print("->");
        Serial.print(phValues[i]);
        Serial.print("<-|->");
        Serial.print(clusterCenters[i]);
        Serial.print("<-|->");
        Serial.print(clusteredArray[i]);
      }
      else{
        Serial.print("  ");
        Serial.print(phValues[i]);
        Serial.print("  |  ");
        Serial.print(clusterCenters[i]);
        Serial.print("  |  ");
        Serial.print(clusteredArray[i]);
      }
      if(currentPH == phValues[i]){
        Serial.print("<-");
        if(100 < sample && sample < 1000)
          Serial.print(" ");
        else if(10 < sample && sample < 100)
          Serial.print("  ");
      }
      else {
        int arrow = 2;
        int neededSpaces = (arrow * 2 + phWidth) - sampleColWidth+1;
        for (int j = 0; j < neededSpaces; j++) {
            Serial.print(" ");
        }
      }
      Serial.print("|/|");
      Serial.println(); 
      }
    }
    break;
    case 4:
    {

    }
    break;
    case 5:
    {

    }
    break;
    case 6:
    {

    }
    break;
    case 600:
    {
      Serial.print("|/|=MEDADC==SAMPLES==MEDMEDADC==SAMPLES=====================|/|");
      Serial.println();
    }
    break;
    case 601:
    {
      int columnWidth = 6; // Adjust this to fit your largest numbers
      for(int i = 0; i < ADCSize; i++){
        bool fake = true;
        if(ADCValues[i] != 0) {
          Serial.print("|/| ");
          printPadded(ADCValues[i], columnWidth);
          Serial.print(" | ");
          printPadded(ADCOccurrences[i], columnWidth);
          for (int k = 0; k < ADCSize; k++){
            if(medMedVals[k] != 0){
              if(medMedVals[k] == ADCValues[i]){
                Serial.print(" | ");
                printPadded(medMedVals[k], columnWidth);
                Serial.print(" |   ");
                printPadded(medMedOcc[k], columnWidth);
                fake = false;
              }
            }
          }
          if(fake == true){
            Serial.print(" | ");
            printPadded(ADCValues[i], columnWidth);
            Serial.print(" |   ");
            Serial.print("0 (x) ");
            fake = false;
          }
          Serial.println(" |/|");
        }
      }
    }
    break;
    case 602:
    {
      Serial.print("|/|=========================================================|/|");
      Serial.println(); 
      Serial.print("|/| ");
      Serial.print("STDDev: ");
      printFixedFloat(medMedianSTD, 2, 4);
      Serial.print(" | ");
      Serial.print("trimMeanMedi: ");
      printFixedFloat(medMedMed, 2, 6);
      // Serial.print("trimMean: ");
      // printFixedFloat(trimMean, 2, 6);     
      Serial.print(" | ");
      Serial.print("(");
      Serial.print(trimMeanarrayIndex);
      Serial.print("/");
      Serial.print(trimArrSize);
      Serial.print(")");
      if(EnoughMedMedVals == true){
        Serial.print("(READY)");
      }
      Serial.print(" |/|");
      Serial.println();
    }
    break;
    case 603:
    {
      Serial.print("|/|==PH======CLUSTERCENTER===STDDEV=========================|/|");
      Serial.println(); 
      int colWidth = 6;
      for (size_t i = 0; i < diffPHVals; i++) {
        Serial.print("|/| ");
        printFixedFloat(phValues[i], 2, colWidth);
        Serial.print(" |     ");
        printFixedFloat(pHCallibrationArr[i], 2, colWidth);
        Serial.print("     | ");
        printFixedFloat(stdDevArr[i], 2, colWidth);
        Serial.println(" |/|");
      }
    }
    break;
    case 604:
    {
      Serial.print("|/|=========================================================|/|");
      Serial.println(); 
      Serial.print("|/| ");
      Serial.print("TitCD: ");
      Serial.print(titterTimer);
      Serial.print(" | ");
      Serial.print("titTime(ms): ");
      printFixedFloat(titTime, 2, 6);
      Serial.print(" |/|");
      Serial.println();
    }
    case 999:
    {
      Serial.print("|/|==========================END============================|/|");
      Serial.println();
    }
    break;
    default:
    {

    }
    break;
  }
}