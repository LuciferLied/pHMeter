#include <config.h>

void calibrater(unsigned long now){
    currentPH = phValues[pHValuesIndex];
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
    adcIndex = 0; medMedIndex = 0;
    for (int i = 0; i < medianArrSize; i++){
        bool exists = false;
        for (int k = 0; k < ADCSize; k++){
            if(ADCValues[k] == medianArr[i]){
                exists = true;
                ADCOccurrences[k]++;
                break;
            }
        } 
            if(exists == false){
                ADCValues[adcIndex] = medianArr[i];
                ADCOccurrences[adcIndex] = 1;
                adcIndex++;
            }
    }
    bool exists = false;
    for (int i = 0; i < ADCSize; i++){
        if(medMedVals[i] == medMedianArr[medMedianArrIndex]){
            exists = true;
            medMedOcc[i]++;
            break;
        }
    }
    if(exists == false){
        medMedVals[medMedIndex] = medMedianArr[medMedianArrIndex];
        medMedOcc[medMedIndex] = 1;
        medMedIndex++;
    }
    trimMean = trimmedMean(anal5Array, anal5ArrSize, 0.25);
    trimMeanArray[trimMeanarrayIndex] = trimMean;
    //medianSTD = StdDev(medianArr, medianArrSize);
    if(EnoughMedMedVals == true){
        medMedianSTD = StdDev(trimMeanArray, trimArrSize);
        //medMedMed =  getMedianValue(trimMeanArray, trimArrSize);
        medMedMed =  trimmedMean(trimMeanArray, trimArrSize, 0.25);
        //medMedMed = getMedianValue(medMedianArr, medMedianArrSize);

    }
    if(now - compTimer >= 30*1000){
        for (int i = 0; i < ADCSize; i++)
        {
            medMedOccCompVals[i] = medMedVals[i];
            medMedOccComp[i] = medMedOcc[i];
        }
        
    }
    sortData(ADCValues, ADCOccurrences, ADCSize);
    sortData(medMedVals, medMedOcc, ADCSize);

    bool stableValues = false;
    stableValues = stable();
    trimMeanarrayIndex++; if(trimMeanarrayIndex == trimArrSize){trimMeanarrayIndex = 0;EnoughMedMedVals = true;}
    //medMedianArrIndex++; if(medMedianArrIndex == medMedianArrSize){medMedianArrIndex = 0;EnoughMedMedVals = true;}
    printer(now, mode,printerTimer, printerCD, printIteration);
    calibDecay(now, ADCValues, ADCOccurrences, medMedVals, medMedOcc, medMedOcc, medMedOccCompVals, ADCSize ,decayTimer, printerCD, calibDecayCD);
}