#include <stdlib.h>
#pragma once

typedef struct protocolIO {
    int length;
    int list[8];     //list of n (power of 2) distinct numerical values from a domain of size N
    int res;	     //median of the union
} protocolIO;

void median(void* args);
int cmpint(const void* i1, const void* i2);   //comparator for qsort


// Generic utilities
extern double lap;
double wallClock();
const char* mySide();
