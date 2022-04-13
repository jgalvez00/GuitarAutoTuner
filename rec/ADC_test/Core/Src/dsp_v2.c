// Libraries
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lcd.h"
#include "stm32f0xx.h"
#include "dsp_v2.h"
#include "main.h"
#include "menu.h"
// Macros
#define SWAP(x, y) do {typeof(x) SWAP = x; x = y; y = SWAP; } while (0)

float notefreq[6] = {81.38, 108.5,135.6, 189.9, 244.1,325.5};
float AveDiff[6] = {5.5, 7, 9.75, 18.25, 15.5, 19.25};
/*/ Method Declarations
double randn(void);
void BuildTime(float*);

//void PrintTime(float*);
//void AWGN(float*, float);
void AWGN(float* noise, float Pn, const unsigned int N);
void RearrangeFFT(float*, float*, const unsigned int);
void ComputeFFT(float*, float*, const unsigned int);
//float Mag(float, float);
float ArgMax(float*, float*, const unsigned int, const float, bool);
//void PrintData(float*, float*, const unsigned int, const float, bool, bool);
void LCD_DrawFmax(int size, int side, int row, float * num, float *num2);*/
int dspmain()
{
	//printf("--------program start--------\n");
	
	// define standard mapping
	TuneMap standard;
	standard.E1 = 329.63;
	standard.B = 246.94;
	standard.G = 196.00;
	standard.D = 146.83;
	standard.A = 110.00;
	standard.E2 = 82.41;
	/*
	// construct the time array
	float t[BUF_LEN];
	BuildTime(t);
	
	// printing the time array
	bool print_time = false;
	
	// construct the signal
	float freq = 100.0; // hertz
	float data_re[BUF_LEN] = {0};
	float data_im[BUF_LEN] = {0};
	bool center = true;
	//float noise[BUF_LEN] = {0};
	//AWGN(noise, Pn, BUF_LEN)
	for (int n = 0; n < BUF_LEN; n++)
	{
		data_re[n] = center ? (sin(2 * PI * freq * t[n]) * pow(-1, n)) : sin(2 * PI * freq * t[n]); // real part
		//data_re[n] += noise[n];
	}
	
	// Apply the Danielson-Lanczos Algorithm
	RearrangeFFT(data_re, data_im, BUF_LEN);
	ComputeFFT(data_re, data_im, BUF_LEN);
	
	// Print Output
	bool print_mag = true;
	//PrintData(data_re, data_im, BUF_LEN, fs, center, print_mag);
	
	// Find the Fundamental Frequency
	float fmax = ArgMax(data_re, data_im, BUF_LEN, fs, center);
	//printf("fmax = %f\n", fmax);

	//printf("---------program end---------\n");
	LCD_DrawFmax(3, 0, 1, &freq, &fmax);
*/
	bool center = true;
	float data_re[BUF_LEN] = {0};
	float sum =0;
	for(int i =0; i < BUF_LEN; i++)
	{
		//data_re[i] =(center)? ((float) adc_buf[i]) * (pow(-1,i)): (float) adc_buf[i];
		data_re[i] = (float) adc_buf[i];
		sum += adc_buf[i];
	}
	float data_im[BUF_LEN] = {0};
	float avg = sum/BUF_LEN;
	for(int i =0; i < BUF_LEN; i++)
		{
			data_re[i] =(center) ? (data_re[i] - avg) * (pow(-1,i)) : data_re[i] -avg;
		}
	//LCD_DrawFmax(3, 0, 1, 0, &avg);
	RearrangeFFT(data_re, data_im, BUF_LEN);
	ComputeFFT(data_re, data_im, BUF_LEN);
	float fmax = ArgMax(data_re, data_im, BUF_LEN, fs, center);
	float freq = 100.0;
	fmax = (fmax< 0)? (fmax * -1) : fmax;
	LCD_DrawFmax(3, 0, 1, &freq, &fmax);
	//Jacobs algorithm (AKA the J algo)
	int angle = (notefreq[currentPeg] - fmax) / (AveDiff[currentPeg]/180.0);
	char text[6];
	sprintf(text, "%d", angle);
	LCD_DrawString(60,180,YELLOW, BLUE, "ANGLE", 16, 0);
	LCD_DrawString(120,180,YELLOW, BLUE, text, 16, 0);
	int dir = (angle < 0)? 2: 1;
	if(abs(angle) < 500 ){stepperMotor(dir, 7500, angle, 2);}
	//
	return 0;
}
void LCD_DrawFmax(int size, int side, int row, float *num, float *num2)
{
	char fma[15];
	gcvt(notefreq[currentPeg], 6, fma);
	LCD_DrawString(60,100,YELLOW, BLUE, "Target FMAX", 16, 0);
	LCD_DrawString(60,120,YELLOW, BLUE, fma, 16, 0);
	gcvt(*num2, 6, fma);
	LCD_DrawString(60,140,YELLOW, BLUE, "FMAX", 16, 0);
	LCD_DrawString(60,160,YELLOW, BLUE, fma, 16, 0);

}
double randn(void)
{
	return (double)rand() / (double)RAND_MAX;
}

void BuildTime(float* t)
{
	t[0] = 0.0;
	float dt = 1 / fs;
	for (int i = 1; i < BUF_LEN; i++)
	{
		t[i] = t[i - 1] + dt;
	}
	return;
}

/*void PrintTime(float* t)
{
	for (int i = 0; i < BUF_LEN; i++)
	{
		printf("t[%d] = %f\n", i, t[i]);
	}
	return;
}*/

void AWGN(float* noise, float Pn, const unsigned int N)
{
	float avgNoise = 0.0;
	for (int i = 0; i < N; i++)
	{
		float n = randn();
		avgNoise += n;
		noise[i] = n;
	}
	avgNoise /= N;
	
	// ensure noise is zero-mean
	for (int i = 0; i < N; i++)
	{
		noise[i] -= avgNoise;
	}
	
	// compute zero-mean noise power
	float Pw = 0.0;
	for (int i = 0; i < N; i++)
	{
		Pw += pow(noise[i], 2);
	}
	Pw /= N;
	
	// scale noise to desired power level
	for (int i = 0; i < N; i++)
	{
		noise[i] *= sqrt(Pn / Pw);
	}
	
	return;
}

void RearrangeFFT(float* data_re, float* data_im, const unsigned int N)
{
	unsigned int target = 0;
	for (int n = 0; n < N; n++)
	{
		if (target > n)
		{
			SWAP(data_re[target], data_re[n]);
			SWAP(data_im[target], data_im[n]);
		}
		unsigned int mask = N;
		while (target & (mask >>= 1))
			target &= ~mask;
		target |= mask;
	}
}

void ComputeFFT(float* data_re, float* data_im, const unsigned int N)
{
	for (int step = 1; step < N; step <<= 1)
	{
		const unsigned int jump = step << 1;
		const float step_d = (float) step;
		float twiddle_re = 1.0;
		float twiddle_im = 0.0;
		for (int group = 0; group < step; group++)
		{
			for (int pair = group; pair < N; pair += jump)
			{
				const unsigned int match = pair + step;
				const float product_re = twiddle_re * data_re[match] - twiddle_im * data_im[match];
				const float product_im = twiddle_im * data_re[match] + twiddle_re * data_im[match];
				data_re[match] = data_re[pair] - product_re;
				data_im[match] = data_im[pair] - product_im;
				data_re[pair] += product_re;
				data_im[pair] += product_im;
			}
			if ((group + 1) == step)
				continue;
			float angle = -PI * ((float) group + 1) / step_d;
			twiddle_re = cos(angle);
			twiddle_im = sin(angle);
		}
	}
}

void Mag(float x1, float x2, float * result)
{
	*result  = sqrt(pow(x1, 2) + pow(x2, 2));
}

float ArgMax(float* data_re, float* data_im, const unsigned int N, const float samp_freq, bool center)
{
	float df = samp_freq / N;
	float vmax = 0.0;
	float fmax = 0.0;
	for (int n = 0; n < N; n++)
	{
		const float val = 0;
		Mag(data_re[n], data_im[n], &val);
		if (val > vmax)
		{
			vmax = val;
			float f = 0.0;
			if (center)
				f = (-samp_freq / 2 + n * df) + (df / 2) * (N % 2);
			else
				f = n * df;
			fmax = f;
		}
	}
	return fmax;
}
void meanff(float *r1, const unsigned int N, float *av)
{
	float sum = 0;
	for(int i = 0; i < N; i++)
	{
		sum += r1[i];
	}
	*av = sum/N;
}
/*void PrintData(float* data_re, float* data_im, const unsigned int N, const float samp_freq, bool center, bool mag)
{
	float df = samp_freq / N;
	for (int n = 0; n < N; n++)
	{
		float f = 0.0;
		if (center)
			f = (-samp_freq / 2 + n * df) + (df / 2) * (N % 2);
		else
			f = n * df;
		if (mag)
			printf("%f, %f\n", f, Mag(data_re[n], data_im[n]));
		else
			printf("%f, %f, %f\n", f, data_re[n], data_im[n]);
	}
}*/