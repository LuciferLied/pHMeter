#include <data.h>

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
inline int calibOccurArrClean1[calibValArrSize];
inline float CalibOccSTDDev = 0;
inline float CalibOccMedi = 0;
inline float CalibOccTrim = 0;
inline int usedSize = 0;
inline int highestOcc = 0;
inline int minSmpls = 200;
inline float largeWindowMult = 0.10;
inline float mediumWindowMult = 0.36;
inline float smallWindowMult = 0.60;
inline int largeWindow = 0;
inline int mediumWindow = 0;
inline int smallWindow = 0;
inline int ammSamplesCollected = 0;
inline const int maxKeys = 9;
inline int CurrentKeys[]={0,0,0,0,0,0,0,0,0};
inline int calibKeyBook[diffPHVals][maxKeys]= {0};
inline int keyStart = 0;
inline int keyEnd = 0;
inline int currLargestKey = 0;
void sortRow(int rowNumber, int array2D[diffPHVals][maxKeys]);
inline int printedUpper = 0;
inline int printedLower = 0;
inline int maxPrint = 3;
inline int DistToLock = 3;
//////calibrator//////calibrator//////calibrator//////
