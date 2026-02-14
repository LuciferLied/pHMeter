#pragma once
#include <Arduino.h>

inline const int diffPHVals = 30;
// inline int clusterCenters[diffPHVals] = {
//   620,623,627,630.,635,
//   639,640,644,648.,650,
//   655,658,664,668,670,
//   674,678,681,683,687,
//   692
// };

// String phValues[diffPHVals] = {
//   "7.0", "6.9", "6.8", "6.7", "6.6", 
//   "6.5", "6.4", "6.3", "6.2", "6.1", 
//   "6.0", "5.9", "5.8", "5.7", "5.6", 
//   "5.5", "5.4", "5.3", "5.2", "5.1", 
//   "5.0"
// };

// inline float phValues[diffPHVals] = {
//   7.0, 6.9, 6.8, 6.7, 6.6, 
//   6.5, 6.4, 6.3, 6.2, 6.1, 
//   6.0, 5.9, 5.8, 5.7, 5.6, 
//   5.5, 5.4, 5.3, 5.2, 5.1, 
//   5.0
// };

inline float phValues[diffPHVals] = {
  7.4, 7.3, 7.2, 7.1,
  7.0, 6.9, 6.8, 6.7, 6.6, 
  6.5, 6.4, 6.3, 6.2, 6.1, 
  6.0, 5.9, 5.8, 5.7, 5.6, 
  5.5, 5.4, 5.3, 5.2, 5.1, 
  5.0, 4.9, 4.8, 4.7, 4.6,
  4.5
};



// inline int clusterCenters[diffPHVals] = { //orig
// 592,596,600,604,610,
// 614,618,619,622,627,
// 630,634,637,642,647,
// 651,655,658,660,664,
// 668,672,678,681,685,
// 690,694,697,700,704,
// 707
// };

// inline int clusterCenters[diffPHVals] = { //edited to better fit  at uneven incrememnts
// 592,596,600,604,608, // pH 7.5 down to 7.1
// 612,616,620,624,628, // pH 7.0 (at 620) down to 6.6
// 632,636,640,644,648, // pH 6.5 down to 6.1
// 651,654,658,660,664,
// 668,672,676,680,684,
// 688,692,696,700,704,
// 708
// };


// inline int clusterCenters[diffPHVals] = { //edited to better fit # 2. Removed first ADC value and last pH-value to bring it closer to refMeter && hey, reversed it. removed last cluster and first pH
// 592,596,600,604,608, // pH 7.5 down to 7.1                // As i suspected, this is so far the best solution.
// 612,616,620,624,628, // pH 7.0 (at 620) down to 6.6
// 632,636,640,644,648, // pH 6.5 down to 6.1
// 651,654,658,660,664,
// 668,672,676,680,684,
// 688,692,696,700,704,
// };

// Every value from your list increased by 1 //// pretty much identical readings to the reference meter.
inline int clusterCenters[diffPHVals] = { 
  593, 597, 601, 605, 609, // pH 7.4 down to 7.1
  613, 617, 621, 625, 629, // pH 7.0 (now at 621) down to 6.6
  633, 637, 641, 645, 649, // pH 6.5 down to 6.1
  652, 655, 659, 661, 665, // pH 6.0 down to 5.6
  669, 673, 677, 681, 685, // pH 5.5 down to 5.1
  689, 693, 697, 701, 705  // pH 5.0 down to 4.5
};

//// Next tests. increase/decrease all by 1. Also,  

// double stdDevArr[diffPHVals] = {
// 1.00,1.01,1.05,1.12,0.92,
// 1.02,1.07,3.47,0.99,1.14,
// 1.02,1.01,1.06,1.21,1.11,
// 0.99,1.18,1.05,0.89,1.12,
// 1.20,1.19,1.20,0.97,1.27,
// 1.13,1.11,1.21,1.32,1.31,
// 1.04
// };

