#include <config.h>
#include <Timers&cds.h>
#include <functions.h>

//Commands are not cAsEsEnSiTiVe
void commander(unsigned long now, String &incCommand){
    incCommand.toLowerCase();
    if(incCommand == ""){return;}
    if (incCommand == "calibrate")
    {
        mode = "calibrate";
        //resetc
    }
    if (incCommand == "doser")
    {
        mode = "doser";
        //reset
    }    
      if(incCommand == "rawAnal"){
    }
    if(incCommand == "log"){
    }
    if(incCommand == "titTime"){
        titterTimer = now;
        //resetter();
        pumper(now, readyForPump, pumpRunning, pumperTimer, titTime);
    }
    if(incCommand == "tit+"){
        titTime = titTime + 10;
    }
    if(incCommand == "tit++"){
        titTime = titTime + 25;
    }
    if(incCommand == "tit+++"){
        titTime = titTime + 50;
    }
    if(incCommand == "tit-"){
        titTime = titTime - 10;
    }
    if(incCommand == "tit--"){
        titTime = titTime - 25;
    }
    if(incCommand == "tit---"){
        titTime = titTime - 50;
    }
    if(incCommand == "prev"){
        if(pHCallibrationArrIndex == 0){
            pHValuesIndex = diffPHVals-1; 
            pHCallibrationArrIndex = diffPHVals-1; 
            stdDevArrIndex = diffPHVals-1;
        }
        else{
            pHValuesIndex--;
            pHCallibrationArrIndex--; 
            stdDevArrIndex--;
        }
        }
    if(incCommand == "next"){
        if(pHCallibrationArrIndex == diffPHVals -1){
            pHValuesIndex = 0;
            pHCallibrationArrIndex = 0;
            stdDevArrIndex = 0;
        }
        else{
            pHCallibrationArrIndex++;
            pHValuesIndex++;
            pHCallibrationArrIndex++; 
            stdDevArrIndex++;
        }
        }
    if(incCommand == "led"){
        matrixPicker();
    }
    if(incCommand == "calibScreen"){
        if(calibrationScreen == false){calibrationScreen = true;}
        else if(calibrationScreen == true){calibrationScreen = false;}
    }

    if(incCommand == "result"){
        Serial.println("Insertable values");
        Serial.println("double clusterCenters[diffPHVals] = {");
        int j=0;
        for(int i = 0; i < 5; i++){
        for (int k = 0; k < 5; k++){
            Serial.print(pHCallibrationArr[j]);
            Serial.print(",");
            j++;
            if(j==diffPHVals){k=5, i=5;}
        }
        Serial.println("");
        }
        Serial.println("};");
    }
    if(incCommand == "endcalibration"){

    }
    incCommand = "";
}