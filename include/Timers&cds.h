#pragma once

///// checks
inline bool readyForPump = false;
inline bool pumpRunning = false;


/// timers and cds
inline unsigned long loopTimer = 0;
inline int loopCD = 10;

inline unsigned long setterTimer = 0;
inline int setterCD = 36*1000;

inline unsigned long pumperTimer = 0;
inline unsigned long pumperCD = 5*60*1000;

inline unsigned long printerTimer = 0;
inline unsigned long printerCD = 10*1000;
//inline unsigned long printerCD = 999999*1000;


inline unsigned long decayTimer = 0;
inline unsigned long decayCD = 36*1000;

inline unsigned long  compTimer = 0;
inline unsigned long compCD = 36*1000;

inline unsigned long  phaseTimer = 0;
inline unsigned long phaseCD = 36*1000;
