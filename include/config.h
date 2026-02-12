#pragma once
#include <Arduino.h>
#include <data.h>
#include <functions.h>
#include <callibration.h>
#include <Timers&cds.h>


//inline String mode= "Doser";
inline String mode= "Calibrator";

inline String phase = "Watching"; //add a sepperate location for phase/mode strings
inline String incCommand;

inline const int digiPin = 7;
inline const int analPin= A5;

inline const int minADC = 300;
inline const int maxADC = 900;

inline int anal5ArrSize = 360;
inline int medianArrSize = 100;
inline const int medMedianArrSize = 60;

inline int       medMedianArrIndex = 0;
inline int       medMedianArr[medMedianArrSize];

inline int       clusteredArray[diffPHVals]; 
inline int       clusteredAmmLimit = 36;
inline float     decayFactor = 0.95;

inline float       MAX_DESIRED_PH = 6.4;
inline float       MIN_DESIRED_PH = 5.6;
inline float     currentPH = 0;
inline int       highest = 0;

inline unsigned long pumpDesRuntime = 0;
inline unsigned long pHSetterArr[] = {8, 4, 2, 1, 0.5};
inline float testerMultiplier = 0.36;   // set to 1 in production

//                                     40ml 40 30 20 10

//                                          6*6 4*6 2*6 1*6
//inline unsigned long pHSetterArr[] = {36, 36, 26, 16, 8};




inline int           CompMedmedArr[medMedianArrSize];

inline const  int trimMeanArrSize = 36;
inline float trimPerc = 0.25;
inline float trimMeanSTD = 0;
inline float stdLim = 1.5;
inline float trimPercMed = 0.15;
inline const  int trimMeanMediArraySize = 36;
inline int trimMeanMediArray[trimMeanMediArraySize];
inline int trimMeanMediArrayIndex = 0;
inline int trimmedMeanMedian = 0;
inline int compClusterArrar[trimMeanMediArraySize];

inline int printIteration = 0;