void decay(unsigned long now, int array[], int compArray[], int size, float decay, unsigned long &decayTimer, unsigned long decayCD, unsigned long &compTimer, unsigned long compCD){
  if(now - decayTimer >= decayCD){
    decayTimer = now;
    for(int i = 0; i < size; i++ ){
      if(now - compTimer >= compCD)
      if(compArray[i]*0,66 >= array[i]){
        array[i];
      }
      array[i] = array[i] * decay;
    }
  }
}

void calibDecay(unsigned long now, int adcVals[], int ADCOccurrences[], int medMedvals[], int medMedOcc[], int medMedOccComp[], int medMedCompVals[], int size, unsigned long &decayTimer, unsigned long decayCD, unsigned long compTimer){
  if(now - decayTimer >= decayCD){
    decayTimer = now;

    for(int i = 0; i < size; i++ ){
      if(ADCOccurrences[i] != 0){
        // Fixed: Avoided 1/4 (division by zero)
        ADCOccurrences[i] = ADCOccurrences[i] * 0.80; 
  
        if(ADCOccurrences[i] <= 10){
          ADCOccurrences[i] = 0;
          adcVals[i] = 0;
        }
      }
    }
    for (int i = 0; i < size; i++) {
      // Fixed: Added [i] to check the specific occurrence
      if(medMedOcc[i] != 0){ 
        medMedOcc[i] = medMedOcc[i] * 0.90;
        if(medMedOcc[i] > 10000){}
      }
    }
    if(now - compTimer >= 30*1000){
      for (int i = 0; i < size; i++){
        if(medMedCompVals[i] != 0){
          for (int k = 0; k < size; k++){
            if(medMedCompVals[i] == medMedvals[k]){
              if(medMedOccComp[i]*0.80 >= medMedOcc[i]){
                medMedOcc[i] = 0;
                medMedvals[i] = 0;
                medMedOccComp[i] = 0;
                medMedCompVals[i] = 0;
                break;
              }
            }
          }  
        }        
      }
    }
  }
}