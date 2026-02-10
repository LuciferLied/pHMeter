#include <config.h>

void calibrater(unsigned long now){
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
    for (int i = 0; i < medMedianArrSize; i++){
        bool exists = false;
        for (int k = 0; k < ADCSize; k++){
            if(medMedVals[k] == medMedianArr[i]){
                exists = true;
                medMedOcc[k]++;
                break;
            }
        }
        if(exists == false){
            medMedVals[medMedIndex] = medMedianArr[i];
            medMedOcc[medMedIndex] = 1;
            medMedIndex++;
        }
    }
        medianSTD = StdDev(medianArr, medianArrSize);
        if(EnoughMedMedVals == true){
          medMedianSTD = StdDev(medMedianArr, medMedianArrSize);
          medMedMed = getMedianValue(medMedianArr, medMedianArrSize);
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

        medMedianArrIndex++; if(medMedianArrIndex == medMedianArrSize){medMedianArrIndex = 0;EnoughMedMedVals = true;}
        printer(now, mode,printerTimer, printerCD, printIteration);
        calibDecay(now, ADCValues, ADCOccurrences, medMedVals, medMedOcc, medMedOcc, medMedOccCompVals, ADCSize ,decayTimer, printerCD, 30*1000);
}