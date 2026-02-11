///////Callibration
#include <vector>

inline bool calibrationScreen = false;
inline const int phValuesAmm = 31;

inline int pHCallibrationArr[phValuesAmm];
inline int pHCallibrationArrIndex = 0;
inline float stdDevArr[phValuesAmm];
inline int pHValuesIndex = 0;

inline unsigned long  titterTimer = 0;
inline unsigned long titterCD = 3*60*1000;
inline int titTime = 0;
inline int totalTitTime = 0;

inline bool EnoughMedMedVals = false;

inline const int ADCSize = 20;
inline int ADCValues[ADCSize];
inline int ADCOccurrences[ADCSize];
inline int medMedVals[ADCSize];
inline int medMedOcc[ADCSize];
inline int medMedOccCompVals[ADCSize];
inline int medMedOccComp[ADCSize];
inline int medMedIndex = 0;
inline int adcIndex = 0;

inline const int trimArrSize = 1024;
inline int trimMeanarrayIndex = 0;
inline int trimMeanArray[trimArrSize];


inline float medianSTD = 0;
inline float medMedianSTD = 0;
inline int medMedMed = 0;
inline float trimMean = 0;

inline unsigned long calibDecayTimer = 60;
inline unsigned long calibDecayCD = 3*60*1000;
inline float CalibDecFactor = 0.80;