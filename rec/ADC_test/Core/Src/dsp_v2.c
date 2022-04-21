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

// Global Variables
const float notefreq[6] = {82.41, 110.00,146.83, 196.00, 246.94,329.63};
const float AveDiff[6] = {5.5, 7, 9.75, 18.25, 15.5, 19.25};
int dspmain2()
{
	// construct the signal
		float data_re[2 * BUF_LEN] = {0}; // 2 * BUF_LEN because of Autocorrelation (otherwise, would result in circular autocorrelation)
		float data_im[2 * BUF_LEN] = {0}; // same reason for 2 * BUF_LEN as data_re[]

		float avg = 0.0;
		for(int i =0; i < BUF_LEN; i++)
			{
				data_re[i] = (float) adc_buf[i];
				avg += data_re[i];
		}
		avg /= BUF_LEN;

		// remove any possible DC bias
		for (int n = 0; n < BUF_LEN; n++)
			data_re[n] -= avg;

		// Filter
		float cutoffLow = 45.0; // hertz
		float cutoffHigh = 600.0; // hertz
		HighPass(data_re, cutoffLow, fs, BUF_LEN); // only need to filter the original BUF_LEN number of samples
		LowPass(data_re, cutoffHigh, fs, BUF_LEN); // same reason for BUF_LEN as HighPass
		LowPass(data_re, cutoffHigh, fs, BUF_LEN); // same reason for BUF_LEN as HighPass
		// Center Data in Frequency

		// compute the autocorrelation
		Autocorr(data_re, data_im, 2 * BUF_LEN); // result of autocorrelation stored in data_re[]

		// print the result
		bool print_mag = false; // set to true for printing magnitude
		bool inverse = true; // set to false if printing frequency data, otherwise set to true
		bool corr = true; // set to true for printing autocorrelation
		//PrintData(data_re, data_im, 2 * BUF_LEN, fs, center, print_mag, inverse, corr);

		// estimate the input frequency
		float fmax = 0.0;
		AutocorrFreq(data_re, BUF_LEN, fs, &fmax);
		//printf("Estimated Frequency: %.6f\n", fmax);
		float freq = 100.0;
		LCD_DrawFmax(3, 0, 1, &freq, &fmax);
		int angle = (notefreq[currentPeg] - fmax) / (AveDiff[currentPeg]/180.0);
		char text[6];
		sprintf(text, "%d", angle);
		LCD_DrawString(60,180,YELLOW, BLUE, "ANGLE", 16, 0);
		LCD_DrawString(120,180,YELLOW, BLUE, text, 16, 0);
		int dir = (angle < 0)? 1: 2;
		if(abs(angle) < 500 ){stepperMotor(dir, 7500, abs(angle), 2);}
			//
		return 0;

}
int dspmain()
{
	// Define Standard Mapping
	TuneMap standard;
	standard.E1 = 329.63;
	standard.B = 246.94;
	standard.G = 196.00;
	standard.D = 146.83;
	standard.A = 110.00;
	standard.E2 = 82.41;

	// Construct the Signal & Compute Average
	float data_re[BUF_LEN] = {0};
	float data_im[BUF_LEN] = {0};
	float sum =0;
	for(int i =0; i < BUF_LEN; i++)
	{
		data_re[i] = (float) adc_buf[i];
		sum += data_re[i];
	}
	float avg = sum/BUF_LEN;

	//Remove the DC Bias
	for(int i =0; i < BUF_LEN; i++)
	{
		data_re[i] -= avg;
	}

	// High-Pass Filter
	float cutoffLow = 45.0; // hertz
	HighPass(data_re, cutoffLow, fs, BUF_LEN);
	float cutoffHigh = 600.0;
	LowPass(data_re, cutoffHigh, fs, BUF_LEN); // same reason for BUF_LEN as HighPass
	LowPass(data_re, cutoffHigh, fs, BUF_LEN); // same reason for BUF_LEN as HighPass
	// Center Data in Frequency
	bool center = true;
	if (center)
	{
		for (int n = 0; n < BUF_LEN; n++)
		{
			data_re[n] = data_re[n] * pow(-1, n);
		}
	}

	// Apply the Danielson-Lanczos Algorithm
	RearrangeFFT(data_re, data_im, BUF_LEN);
	ComputeFFT(data_re, data_im, BUF_LEN, false);

	// Find the Fundamental Frequency
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
	if(abs(angle) < 500 ){stepperMotor(dir, 7500, abs(angle), 2);}
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

void ComputeFFT(float* data_re, float* data_im, const unsigned int N, bool inverse)
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
			float angle = -PI * ((float) group + 1) / step_d * (inverse ? -1 : 1);
			twiddle_re = cos(angle);
			twiddle_im = sin(angle);
		}
	}

	if (inverse)
	{
		for (int k = 0; k < N; k++)
		{
			data_re[k] /= N;
			data_im[k] /= N;
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
		float val = 0;
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

void HighPass(float* x, float cutoff, float samp_rate, const unsigned int N)
{
	float deltaT = 1 / samp_rate;
	float alpha = 1 / (2 * PI * deltaT * cutoff + 1);

	float x_prev = x[0];
	float y_prev = x[0];
	for (int k = 1; k < N; k++)
	{
		float x_curr = x[k];
		x[k] = alpha * (y_prev + x_curr - x_prev);
		x_prev = x_curr;
		y_prev = x[k];
	}
}
void LowPass(float* x, float cutoff, const float samp_rate, const unsigned int N)
{
	float deltaT = 1 / samp_rate;
	float alpha = 2 * PI * deltaT * cutoff / (2 * PI * deltaT * cutoff + 1);

	x[0] *= alpha;
	for (int n = 1; n < N; n++)
		x[n] = x[n - 1] + alpha * (x[n] - x[n - 1]);
}

void FFT(float* data_re, float* data_im, const unsigned int N, bool inverse)
{
	/* NOTE: N must be a power of 2 */

	RearrangeFFT(data_re, data_im, N);
	ComputeFFT(data_re, data_im, N, inverse);
}

void Autocorr(float* data_re, float* data_im, const unsigned int N)
{
	/* NOTE: N must be 2x the size of the original data vector */

	// compute the Fourier Transform
	bool inverse = false;
	FFT(data_re, data_im, N, inverse);

	// compute the power spectral density
	for (int k = 0; k < 2 * BUF_LEN; k++)
	{
		data_re[k] = pow(data_re[k], 2) + pow(data_im[k], 2);
		data_im[k] = 0.0;
	}

	// compute the autocorrelation (stored in data_re[])
	inverse = true;
	FFT(data_re, data_im, 2 * BUF_LEN, inverse);
}

void AutocorrFreq(float* r, const unsigned int N, const float samp_rate, float * result)
{
	/* NOTE: N only needs to be the size of the original data vector because
			 the autocorrelation is symmetric about the zero-lag index
	*/

	float vmax = 0.0;
	int nmax = 0.0;
	for (int n = 1; n < N - 1; n++)
	{
		float val_prev = r[n - 1];
		float val = r[n];
		float val_next = r[n + 1];
		if ((val_prev < val) && (val_next < val) && (val > vmax))
		{
			nmax = n;
			vmax = val;
		}
	}

	*result = samp_rate / nmax;
}
