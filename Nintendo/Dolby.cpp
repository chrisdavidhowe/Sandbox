//
// Created by Chris Howe on 8/28/20.
//

// 1 / sqrt(2)
// -3dB
#include "cmath"

static const float HALFPOWER { 1.f / sqrt(2.f) };

struct Stereo_t {
    float left { 0.f };
    float right { 0.f };
};

struct Dolby5_1_t {
    float lf  { 0.f };
    float rf  { 0.f };
    float lr  { 0.f };
    float rr  { 0.f };
    float c   { 0.f };
    float lfe { 0.f };
};

Stereo_t Dolby51toStereo(Dolby5_1_t input)
{
    Stereo_t output;
    output.left = input.lf + (HALFPOWER * input.c) + (HALFPOWER * input.lr);
    output.right = input.rf + (HALFPOWER * input.c) + (HALFPOWER * input.rr);
}

float hilbert(float in) { return in; }
float delay(float in, float ms) { return in; }
float lpf(float in, float fc) { return in; }

Dolby5_1_t StereoToDolby5_1(Stereo_t input)
{
    //12 and 48 milliseconds
    float ms_delay = 12;
    Dolby5_1_t dolby51;
    dolby51.lf = input.left;
    dolby51.rf = input.right;

    //The passive surround decoding (PSD) method
    dolby51.c =  (input.left + input.right) * HALFPOWER;
    float rear = (input.left - input.right) * HALFPOWER;

    //90 degree phase shift, low pass filter, delay for rear channels
    dolby51.lr = dolby51.rr = hilbert( lpf( delay(rear, ms_delay), 7400) );

    //lfe is just the center channel at around 200hz lpf
    dolby51.lfe = lpf(dolby51.c, 120);
    return dolby51;
}

