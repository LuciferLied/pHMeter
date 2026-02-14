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

inline int calibValueArr[100];
inline int calibOccurArr[100];
//////calibrator//////calibrator//////calibrator//////