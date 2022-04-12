#ifndef __MENU_H
#define __MENU_H

// libraries
#include "stdbool.h"
#include "fftw3.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// Constants
#define PI 3.14159265
#define BUF_LEN 500 // length of sample buffer
#define fs 250.0 // sampling rate (Hz)

// Structures
typedef struct TuneMap
{
	float E1;
	float B;
	float G;
	float D;
	float A;
	float E2;
} TuneMap;

// Method Declarations
double DSPMain(void);
double randn(void);
void BuildTime(float*);
void AWGN(float*, float);
void BuildInput(fftw_complex*, float*, float, bool, bool, float);
float argmax(fftw_complex*, bool);

#endif
