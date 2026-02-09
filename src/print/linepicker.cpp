#include <Arduino.h>

void linePrinter(int line, int printIteration, float currentPH, int diffPHVals, int clusteredArray[], float phValues[], int clusterCenters[]){
  switch(line){
    case 0:
    {
      Serial.print("|/|=========================================================|/|");
      Serial.println();
      Serial.print("|/|");
      Serial.print("Version: 0.0.8");
      Serial.print(" | ");
      Serial.print("timesPrinted: ");
      Serial.print (printIteration);
      // Serial.print("  |  ");
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
    case 3:
    {

    }
    break;
    default:
    {

    }
    break;
  }
}