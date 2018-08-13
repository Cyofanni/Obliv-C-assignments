#include <math.h>
#pragma once

#define THRESHOLD_DISTANCE 2

typedef struct protocolIO {
  float coords[2];   //stores the spatial (cartesian) coordinates for the current party (two dimensional)
  int res;    /*stores the result of the oblivious computation, that is:
	        For Alice, 'res' is true if Bob is within the distance given by THRESHOLD DISTANCE (and vice versa)*/
} protocolIO;

void exactProximityTesting(void* args);

// Generic utilities
extern double lap;
double wallClock();
const char* mySide();
