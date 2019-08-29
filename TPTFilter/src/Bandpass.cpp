#include "Bandpass.hpp"
#include "SC_PlugIn.hpp"
#include <cstdint>

using tpt_filter_ugens::Bandpass;

Bandpass::Bandpass() {
    if (isAudioRateIn(1) && isAudioRateIn(2))
        set_calc_function<Bandpass, &Bandpass::next_aa>();
    else if (isAudioRateIn(1) && (isControlRateIn(2) || isScalarRateIn(2)))
        set_calc_function<Bandpass, &Bandpass::next_ak>();
    else if ((isControlRateIn(1) || isScalarRateIn(1)) && isAudioRateIn(2))
        set_calc_function<Bandpass, &Bandpass::next_ka>();
    else
        set_calc_function<Bandpass, &Bandpass::next_kk>();
}

void Bandpass::next_aa(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float* freq = in(1);
    const float* r = in(2);
    float* outBuf = out(0);

    double s1 = mS1;
    double s2 = mS2;

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double g = computeG(freq[i]);
        const double r2 = compute2r(r[i]);
        const double d = computeD(r2, g);

        const double bp = (g * (r2 * static_cast<double>(inBuf[i]) - s2) + s1) * d;

        // First integrator
        const double bp2 = bp + bp;
        s1 = bp2 - s1;

        // Second integrator
        const double v22 = g * bp2;
        s2 = s2 + v22;

        outBuf[i] = bp;
    }

    mS1 = zapgremlins(s1);
    mS2 = zapgremlins(s2);
}

void Bandpass::next_ak(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float* freq = in(1);
    const float r = in0(2);
    float* outBuf = out(0);

    double s1 = mS1;
    double s2 = mS2;

    const double r2 = compute2r(r);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double g = computeG(freq[i]);
        const double d = computeD(r2, g);

        const double bp = (g * (r2 * static_cast<double>(inBuf[i]) - s2) + s1) * d;

        // First integrator
        const double bp2 = bp + bp;
        s1 = bp2 - s1;

        // Second integrator
        const double v22 = g * bp2;
        s2 = s2 + v22;

        outBuf[i] = bp;
    }

    mS1 = zapgremlins(s1);
    mS2 = zapgremlins(s2);
}

void Bandpass::next_ka(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float freq = in0(1);
    const float* r = in(2);
    float* outBuf = out(0);

    double s1 = mS1;
    double s2 = mS2;

    const double g = computeG(freq);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double r2 = compute2r(r[i]);
        const double d = computeD(r2, g);

        const double bp = (g * (r2 * static_cast<double>(inBuf[i]) - s2) + s1) * d;

        // First integrator
        const double bp2 = bp + bp;
        s1 = bp2 - s1;

        // Second integrator
        const double v22 = g * bp2;
        s2 = s2 + v22;

        outBuf[i] = bp;
    }

    mS1 = zapgremlins(s1);
    mS2 = zapgremlins(s2);
}

void Bandpass::next_kk(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float freq = in0(1);
    const float r = in0(2);
    float* outBuf = out(0);

    double s1 = mS1;
    double s2 = mS2;

    const double g = computeG(freq);
    const double r2 = compute2r(r);
    const double d = computeD(r2, g);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double bp = (g * (r2 * static_cast<double>(inBuf[i]) - s2) + s1) * d;

        // First integrator
        const double bp2 = bp + bp;
        s1 = bp2 - s1;

        // Second integrator
        const double v22 = g * bp2;
        s2 = s2 + v22;

        outBuf[i] = bp;
    }

    mS1 = zapgremlins(s1);
    mS2 = zapgremlins(s2);
}
