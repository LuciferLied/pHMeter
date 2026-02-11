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
    if(incCommand == "rawanal"){
    }
    if(incCommand == "log"){
        pHCallibrationArr[pHValuesIndex] = medMedMed;
        stdDevArr[pHValuesIndex] = medMedianSTD;
        totalTitTime = 0;
        pHValuesIndex++;
    }
    if(incCommand == "tittime"){
        readyForPump = true;
        titterTimer = now;
        resetter();
        pump(now, titTime);
        totalTitTime = totalTitTime + titTime;

    }
    if(incCommand == "reset"){
        resetter();
    }
    if(incCommand == "tit+"){
        titTime = titTime + 10;
    }
    if(incCommand == "tit++"){
        titTime = titTime + 25;
    }
    if(incCommand == "tit+++"){
        titTime = titTime + 100;
    }
    if(incCommand == "tit++++"){
        titTime = titTime + 200;
    }
    if(incCommand == "tit-"){
        titTime = titTime - 10;
    }
    if(incCommand == "tit--"){
        titTime = titTime - 25;
    }
    if(incCommand == "tit---"){
        titTime = titTime - 100;
    }
    if(incCommand == "tit----"){
        titTime = titTime - 200;
    }
    if(incCommand == "emptypump"){
        readyForPump = true;
        pump(now, 10*1000);
    }
    if(incCommand == "prev"){
        if(pHValuesIndex == 0){
            pHValuesIndex = phValuesAmm-1; 
        }
        else{
            pHValuesIndex--;
        }
        }
    if(incCommand == "next"){
        if(pHValuesIndex == diffPHVals -1){
            pHValuesIndex = 0;
        }
        else{
            pHValuesIndex++;
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
        Serial.println("int clusterCenters[diffPHVals] = {");
        int j=0;
        for(int i = 0; i < 7; i++){
            for (int k = 0; k < 5; k++){
                Serial.print(pHCallibrationArr[j]);
                Serial.print(",");
                j++;
                if(j==phValuesAmm){k=5, i=7;}
            }
            Serial.println("");
        }
        Serial.println("};");

        Serial.println("Insertable values");
        Serial.println("int stdDev[diffPHVals] = {");
        j=0;
        for(int i = 0; i < 7; i++){
            for (int k = 0; k < 5; k++){
                Serial.print(stdDevArr[j]);
                Serial.print(",");
                j++;
                if(j==phValuesAmm){k=5, i=7;}
            }
            Serial.println("");
        }
        Serial.println("};");
    }
    if(incCommand == "endcalibration"){

    }
    incCommand = "";
}