//============================================================================
// lcd.h: Adapted from the lcdwiki.com examples.
//============================================================================

#ifndef __DSP_V2_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lcd.h"
#include "stm32f0xx.h"
#include "main.h"
#define SWAP(x, y) do {typeof(x) SWAP = x; x = y; y = SWAP; } while (0)

// Constants
#define PI 3.14159265
#define BUF_LEN 1024 // length of sample buffer
#define SAMPLE_MULT 8
#define SAMPLE_LEN BUF_LEN*SAMPLE_MULT
#define fs_base 55555.56 // sampling rate (Hz)
//#define fs 6944.445 // sampling rate (Hz)
#define fs fs_base/SAMPLE_MULT // sampling rate (Hz)

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

typedef struct floatPair
{
	float data_re[2 * BUF_LEN];
	float data_im[2 * BUF_LEN];
};

union adcData
{
	uint16_t raw[SAMPLE_LEN];
	struct floatPair dspFloat;

};

union adcData buffer;

// Method Declarations
int dspmain();
int dspmain2();
void meanff(float *r1, const unsigned int N, float *av);
void BuildTime(float*);
void Mag(float, float, float *);
float ArgMax(float*, float*, const unsigned int, const float, bool);
void HighPass(float*, float, float, const unsigned int);
void LowPass(float*, float, const float, const unsigned int);

void RearrangeFFT(float*, float*, const unsigned int);
void ComputeFFT(float*, float*, const unsigned int, bool);
void FFT(float*, float*, const unsigned int, bool);
void Autocorr(float*, float*, const unsigned int);
void AutocorrFreq(float*, const unsigned int, const float, float *);
#endif
