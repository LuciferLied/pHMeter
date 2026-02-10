#include <config.h>


void doser(unsigned long now){
    int anal5Array[anal5ArrSize];
    int medianArr[medianArrSize];
    int anal5Index = 0;
    int medianArrIndex = 0;
    while(medianArrIndex < medianArrSize){
      while(anal5Index < anal5ArrSize){
        anal5Array[anal5Index]=sensor(analPin, minADC, maxADC);
        anal5Index++;
      }
      medianArr[medianArrIndex] = getMedianValue(anal5Array, anal5ArrSize);
      medianArrIndex++;
    }
    medMedianArr[medMedianArrIndex] = getMedianValue(medianArr, medianArrSize);
      if(now - compTimer>= compTimer){
        for (int  i = 0; i < medMedianArrSize; i++)
        {
          CompMedmedArr[i] = medMedianArr[i];
        }
      }
      clusterer(clusterCenters, diffPHVals, medMedianArr[medMedianArrIndex], clusteredArray);
      medMedianArrIndex++; if(medMedianArrIndex == medMedianArrSize){medMedianArrIndex = 0;}
      pHGetter(now, clusteredAmmLimit, diffPHVals, phValues, clusteredArray, currentPH, highest);
      pHSetter(now, phase, currentPH, setterTimer, setterCD, readyForPump, pumpDesRuntime, pHSetterArr);
      printer(now, mode,printerTimer, printerCD, printIteration);
      decay(now, clusteredArray, CompMedmedArr, diffPHVals, decayFactor, decayTimer, decayCD, compTimer, compCD);
}