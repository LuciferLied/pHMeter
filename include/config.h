#pragma once
#include <Arduino.h>
#include <data.h>
#include <functions.h>
#include <callibration.h>
#include <Timers&cds.h>


inline String mode= "calibrater";
inline String phase = "";
inline String incCommand = "";

inline const int digiPin = 7;
inline const int analPin= A5;

inline const int minADC = 300;
inline const int maxADC = 900;

inline int anal5ArrSize = 360;
inline int medianArrSize = 100;

inline const int medMedianArrSize = 360;
inline int       medMedianArrIndex = 0;
inline int       medMedianArr[medMedianArrSize];

inline int       clusteredArray[diffPHVals]; 
inline int       clusteredAmmLimit = 360;
inline float     decayFactor = 0.95;

inline int       MAX_DESIRED_PH = 6.5;
inline int       MIN_DESIRED_PH = 5.5;
inline float     currentPH = 0;
inline int       highest = 0;

inline unsigned long pumpDesRuntime = 0;
inline unsigned long pHSetterArr[] = {10, 5, 3, 2, 1, 0.5};
inline int           CompMedmedArr[medMedianArrSize];

inline int printIteration = 0;