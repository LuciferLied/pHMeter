#include <config.h>

void doser2(unsigned long now){
    int anal5Array[anal5ArrSize];
    int anal5Index = 0;
    int trimMeanArray[trimMeanArrSize];
    int trimMeanArrayIndex = 0;
    while(trimMeanArrayIndex < trimMeanArrSize){
        anal5Index = 0;
        while(anal5Index < anal5ArrSize){
            anal5Array[anal5Index]=sensor(analPin, minADC, maxADC);
            anal5Index++;
        }
        trimMean = trimmedMean(anal5Array, anal5ArrSize, trimPerc);
        trimMeanArray[trimMeanArrayIndex] = trimMean;
        trimMeanArrayIndex++;
    }
    trimMeanSTD = StdDev(trimMeanArray, trimMeanArrSize);
    if(trimMeanSTD < stdLim){
        trimmedMeanMedian =  trimmedMean(trimMeanArray, trimMeanArrSize, trimPercMed);
        trimMeanMediArray[trimMeanMediArrayIndex] = trimmedMeanMedian;
        clusterer(clusterCenters, diffPHVals, trimMeanMediArray[trimMeanMediArrayIndex], clusteredArray);
    }
    trimMeanMediArrayIndex++; if(trimMeanMediArrayIndex == trimMeanMediArraySize){trimMeanMediArrayIndex = 0;}
    pHGetter(now, clusteredAmmLimit, diffPHVals, phValues, clusteredArray, currentPH, highest);
    pHSetter(now, phase, currentPH, setterTimer, setterCD, readyForPump, pumpDesRuntime, pHSetterArr);
    printer(now, mode,printerTimer, printerCD, printIteration);
    decay(now, clusteredArray, compClusterArrar, diffPHVals, decayFactor, decayTimer, decayCD, compTimer, compCD);
    if(now - compTimer >= compCD){
        for (int i = 0; i < trimMeanMediArraySize; i++){
            compClusterArrar[i] = clusteredArray[i];
        }
    }
}