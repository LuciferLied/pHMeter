#include <config.h>

void calibrater(unsigned long now){
    currentPH = phValues[pHValuesIndex];
    int anal5Array[anal5ArrSize];
    int medianArr[medianArrSize];
    int anal5Index = 0;
    int medianArrIndex = 0;
    while(anal5Index < anal5ArrSize){
        anal5Array[anal5Index]=sensor(analPin, minADC, maxADC);
        anal5Index++;
    }
    trimMean = trimmedMean(anal5Array, anal5ArrSize, 0.25);
    trimMeanArray[trimMeanarrayIndex] = trimMean;
    if(EnoughMedMedVals == true){
        medMedianSTD = StdDev(trimMeanArray, trimArrSize);
        medMedMed =  trimmedMean(trimMeanArray, trimArrSize, 0.25);
    }
    if(now - compTimer >= 30*1000){
        for (int i = 0; i < ADCSize; i++)
        {
            medMedOccCompVals[i] = medMedVals[i];
            medMedOccComp[i] = medMedOcc[i];
        }
        
    }
    //sortData(ADCValues, ADCOccurrences, ADCSize);
    //sortData(medMedVals, medMedOcc, ADCSize);

    //bool stableValues = false;
    //stableValues = stable();
    trimMeanarrayIndex++; if(trimMeanarrayIndex == trimArrSize){trimMeanarrayIndex = 0;EnoughMedMedVals = true;}
    //medMedianArrIndex++; if(medMedianArrIndex == medMedianArrSize){medMedianArrIndex = 0;EnoughMedMedVals = true;}
    printer(now, mode,printerTimer, printerCD, printIteration);
    //calibDecay(now, ADCValues, ADCOccurrences, medMedVals, medMedOcc, medMedOcc, medMedOccCompVals, ADCSize ,decayTimer, printerCD, calibDecayCD);
}