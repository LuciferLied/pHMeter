#include <data.h>
#pragma once

inline const int analDiCoArrSize = 1000;
inline int analDiCoArr[analDiCoArrSize];
inline int analDicoArrIndex = 0;

inline const int trimMeanArrSize = 360;
inline int trimMeanArray[trimMeanArrSize];
inline int trimMeanArrayIndex = 0;

inline const int trimMeanMedianArrSize = 360;
inline int trimMeanMedianArray[trimMeanMedianArrSize];
inline int trimMeanMedianArrayIndex = 0;

inline int clusteredSamplesArray[diffPHVals]; //look data.h
inline int clusteredSamplesCompArray[diffPHVals];

inline const int rollingArrSize = 60; //1 pr sek
inline int rollingPHArr[rollingArrSize];
inline int rollingPHArrIndex = 0;

//////calibrator//////calibrator//////calibrator//////
inline float stdDevArr[diffPHVals];

inline const int calibValArrSize = 100;
inline int calibValueArr[calibValArrSize];
inline int calibOccurArr[calibValArrSize];
inline float CalibOccSTDDev = 0;
inline float CalibOccMedi = 0;
inline float CalibOccTrim = 0;
inline int usedSize = 0;
inline int highestOcc = 0;
inline int minSmpls = 1;
inline float largeWindowMult = 0.10;
inline float mediumWindowMult = 0.36;
inline float smallWindowMult = 0.50;
inline float keyWindowMult = 0.60;
inline int largeWindow = 0;
inline int mediumWindow = 0;
inline int smallWindow = 0;
inline int keyWindow = 0;
inline int ammSamplesCollected = 0;
inline const int MaxKeySize = 21;
inline int CurrentSampledKey[MaxKeySize]= {0};
inline int calibKeyBundle[diffPHVals][MaxKeySize]= {0};
inline int keyStart = 0;
inline int keyEnd = 0;
inline int currLargestKey = 0;
void sortRow(int rowNumber, int array2D[diffPHVals][MaxKeySize]);
inline int upperShift = 0;
inline int lowerShift = 0;
inline int maxShift = 3;
inline int DistToLock = 1;
inline int currentKeyPrinted = 0;
inline float calibTrimPercent = keyWindowMult;
inline bool swapSampleKey = true;
inline bool capKeys = true;
inline int maxPrintedKeys = 10;

inline bool sampleKey=false;
inline int calibKeyOcc[diffPHVals][MaxKeySize]= {0};
void sortRow2D(int row, int valArr[diffPHVals][MaxKeySize], int occArr[diffPHVals][MaxKeySize]);
inline unsigned long  LastcalibKeyDecayTime = 0;
inline unsigned long  calibKeyDecayCD = 12 *1000;
inline float calibKeyDecayFactor = 0.95;
inline int calibSampleKeyHolder[3][63] = {0};
inline unsigned long lastCMPUpdateTime = 0;
inline unsigned long CMPUpdateCD = 36*1000;
inline int keySamplerIte = 0;
inline float calibSampleKeyPercHolder[2][63] = {0};
inline int currentWindow = 0;
inline float calibKeyBundlePerc[diffPHVals][MaxKeySize][2] = {0};
inline bool showKeyDetails = false;
inline bool idle = false;
inline unsigned long sampleStartTime = 0;
inline unsigned long lastSampleTime = 0;
inline unsigned long maxSampleTime = 60;
inline bool samplingComplete = false;
inline int decayCycles = 3;
inline int possibleReset[63][2];
inline int keyProtector[MaxKeySize];
inline int keyPercProtector[MaxKeySize][2];
inline bool newKeyInSampler = false;
inline bool showPHKey = true;


//////calibrator//////calibrator//////calibrator//////


