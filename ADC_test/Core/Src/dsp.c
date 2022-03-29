#include "dsp.h"
#include "stdbool.h"
#include "fftw3.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double DSPMain(void)
{
	TuneMap standard;
	standard.E1 = 329.63;
	standard.B = 246.94;
	standard.G = 196.00;
	standard.D = 146.83;
	standard.A = 110.00;
	standard.E2 = 82.41;

	// construct the time array
	float t[BUF_LEN];
	BuildTime(t);

	// declare / define the FFT components
	fftw_complex *in, *out;
	fftw_plan p;

	in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * BUF_LEN);
	out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * BUF_LEN);

	// construct the signal
	float freq = 100.0; // hertz
	float snr_db = -10; // dB
	bool center = true;
	bool addNoise = true;
	BuildInput(in, t, freq, center, addNoise, snr_db);

	// execute the FFT
	p = fftw_plan_dft_1d(BUF_LEN, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p);

	// find the maximum frequency component
	float fmax = argmax(out, center);

	// free all of the memory from the FFT components
	fftw_destroy_plan(p);
	fftw_free(in); fftw_free(out);

	return (double)fmax;
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

void AWGN(float* noise, float Pn)
{
	float avgNoise = 0.0;
	for (int i = 0; i < BUF_LEN; i++)
	{
		float n = randn();
		avgNoise += n;
		noise[i] = n;
	}
	avgNoise /= BUF_LEN;

	// ensure noise is zero-mean
	for (int i = 0; i < BUF_LEN; i++)
	{
		noise[i] -= avgNoise;
	}

	// compute zero-mean noise power
	float Pw = 0.0;
	for (int i = 0; i < BUF_LEN; i++)
	{
		Pw += pow(noise[i], 2);
	}
	Pw /= BUF_LEN;

	// scale noise to desired power level
	for (int i = 0; i < BUF_LEN; i++)
	{
		noise[i] *= sqrt(Pn / Pw);
	}

	return;
}

void BuildInput(fftw_complex* in, float* t, float freq, bool center, bool addNoise, float snr_db)
{
	// build clean input
	for (int i = 0; i < BUF_LEN; i++)
	{
		in[i][0] = center ? (sin(2 * PI * freq * t[i]) * pow(-1, i)) : sin(2 * PI * freq * t[i]);
		in[i][1] = center ? (0.0 * pow(-1, i)) : 0.0;
	}

	// return if noiseless signal desired
	if (!addNoise)
		return;

	// average signal power (real)
	float Ps = 0.0;
	for (int i = 0; i < BUF_LEN; i++)
	{
		Ps += (pow(in[i][0], 2) - pow(in[i][1], 2));
	}
	Ps /= BUF_LEN;

	// generate noise
	float snr = pow(10, snr_db / 10); // convert snr in decibels to regular scale
	float Pn = Ps / snr; // desired noise power
	float noise[BUF_LEN] = {0.0};
	AWGN(noise, Pn);

	// add noise to real signal
	for (int i = 0; i < BUF_LEN; i++)
	{
		in[i][0] += noise[i];
	}

	return;
}

float argmax(fftw_complex* arr, bool center)
{
	float vmax = 0.0;
	int idx = 0;
	for (int i = 0; i < BUF_LEN; i++)
	{
		float val = sqrt(pow(arr[i][0], 2) + pow(arr[i][1], 2));
		if (val > vmax)
		{
			vmax = val;
			idx = i;
		}
	}

	float fmax = 0.0;
	float df = fs / BUF_LEN;
	if (center)
		fmax = (-fs / 2 + idx * df) + (df / 2) * (BUF_LEN % 2);
	else
		fmax = idx * df;

	return fmax;
}
