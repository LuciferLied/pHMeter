#include <Arduino.h>
#include <arrays.h>
#include <functions.h>
#include <math.h>

////////equipment//////equipment//////equipment//////
inline const int DIGIPIN = 7;
inline const int ANALPIN = A5;
inline const int MINADC = 1;
inline const int MAXADC = 1023;
inline bool runPump = false;
inline unsigned long lastPumpTime = 0;
inline unsigned long pumpCD = 3*60*1000;
inline unsigned long pumpTimingOptionsArr[] = {36, 30, 24, 18, 12, 6};
inline unsigned long currentPumpTiming = 0;
inline unsigned long pumpTotalONTime = 0;
////////equipment//////equipment//////equipment//////

//////loop//////loop//////loop//////loop//////loop
//inline String mode = "Doser";
inline String mode = "Calibrator";
inline String phase = "Watching";
inline unsigned long lastPhaseCheckTime = 0;
inline unsigned long phaseCheckCD = 6*1000;
inline bool handlingPump = false;
inline String incCommand = "";
inline unsigned long lastLoopTime = 0;
inline unsigned long loopCD = 10;
//////loop//////loop//////loop//////loop//////loop

//////doser//////doser//////doser//////doser//////
inline int trimPercADC = 0.15;
inline float trimMeanArrSTD = 0;
inline float stdLim = 1.5;


// Arrays can be found in array.h and data.h
//////doser//////doser//////doser//////doser//////

//////pH//////pH//////pH//////pH//////pH//////pH
inline float currentPH = 0;
inline float MIN_DESIRED_PH = 5.4; 
inline float MAX_DESIRED_PH = 6.5;
inline int mostSampled = 0;
inline int minConsSampleSize = 6;
inline unsigned long lastSetterTime = 0;
inline unsigned long setterCD = 3600;
inline bool rollingPHReady = false;
inline float rollingPH = 0;
inline float rollTrimPerc = 0.10;
inline unsigned long lastRollPHTime = 0;
inline unsigned long rollPHCD = 1*1000;
//////pH//////pH//////pH//////pH//////pH//////pH

//////decay//////decay//////decay//////decay//////decay
inline float decayFactor = 0.98;
inline unsigned long lastDecayTime = 0;
inline unsigned long decayCD = 3 * 60 * 1000;
inline float compFactor = 3.6;
inline unsigned long lastCompTime = 0;
inline unsigned long compCD = 6 * 60 * 1000;
//////decay//////decay//////decay//////decay//////decay

//////printer//////printer//////printer//////printer
inline int printIteration = 0;
inline unsigned long lastPrinterTime = 0;
inline unsigned long printerCD = 13 * 1000;
//////printer//////printer//////printer//////printer

//////calibrator//////calibrator//////calibrator//////
inline int pHValuesIndex = 0;
inline int diffADCVals = 0;
inline float stdDevOfADC = 0;
inline float trimPercADCCalib = 0.25;
inline bool enoughSamples = false;
inline float trimTrimPercADCCalib = 0.25;
inline float stdDevOfTrim = 0;
inline float trimOfTrim = 0;
inline int mediOfTrim = 0;

inline unsigned long lastTitTime = lastPumpTime;
inline unsigned long titTimeSetting = 100;
inline unsigned long titCD = 3*60*1000;


inline int medianOfTrimCluster = 0;
inline int trimOfTrimCluster = 0;
//////calibrator//////calibrator//////calibrator//////