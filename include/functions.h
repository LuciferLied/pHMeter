

//////commander//////commander//////commander
void phaseHandler(unsigned long now);
void reader(unsigned long now);
void commander(unsigned long now);
void doser(unsigned long now);
void calibrator(unsigned long now);
//////commander//////commander//////commander//////
//////equipment//////equipment//////equipment//////
void matrixPicker();
int sensor();
void pump(unsigned long now);
void startPump(unsigned long now);
void stopPump();
//////math//////math//////math//////math//////math
float trimmedMean(int *values, int size, float trimFraction);
float StdDev(int array[], int size);
int getMedianValue(int array[], int size);
void clusterer(int arr[], int size, int sample, int outputArray[]);
void calibClusterer(int arr[], int size, float sample, int outputArray[]);
void sampleDecay(unsigned long now);
void trimMeanGetter(unsigned long now);
void sortData(int values[], int occurrences[], int size);
//////math//////math//////math//////math//////math
//////pH//////pH//////pH//////pH//////pH//////pH//////pH
void pHGetter(unsigned long now, int clusteredAmmLimit, int diffPHVals, float phValues[], int clusteredArray[], float &currentPH, int &highest);
void pHSetter(unsigned long now, String phase, float currentPH, unsigned long &setterTime, int setterCD, bool &readyForPump, unsigned long &pumpDesRuntime, unsigned long pHSetterArr[]);
//////pH//////pH//////pH//////pH//////pH//////pH//////pH
//////printer//////printer//////printer//////printer
void printer(unsigned long now, String mode, unsigned long &printerTimer, unsigned long printerCD, int &printIteration);
void linePrinter(unsigned long now, int line);
void printPadded(int value, int width);
void printFixedFloat(float value, int precision, int width);
void printPaddedText(const char* text, int width);
void printPaddedString(String text, int width);
//////printer//////printer//////printer//////printer
//////calibrator//////calibrator//////calibrator//////
void calibrator2(unsigned long now);
void resetter();
void getADCSamples(int values[], int occurrences[], int size, int &usedSpace);

