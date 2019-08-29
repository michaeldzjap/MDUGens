#include "Tilt.hpp"
#include "SC_PlugIn.hpp"
#include <cstdint>
#include <cmath>

using tpt_filter_ugens::Tilt;

Tilt::Tilt() {
    if (isAudioRateIn(1))
        set_calc_function<Tilt, &Tilt::next_a>();
    else
        set_calc_function<Tilt, &Tilt::next_k>();
}

void Tilt::next_a(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float* freq = in(1);
    const float gain = in0(2);
    float* outBuf = out(0);

    double s = mS;

    const double m = std::sqrt(computeM2(gain));
    const double mi = 1. / m;

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const float x = static_cast<double>(inBuf[i]);
        const double g = computeG(freq[i]);
        const double v = (x - s) * g / (1.0 + g);
        const double y = v + s;

        outBuf[i] = mi * y + m * (x - y);

        s = y + v;
    }

    mS = zapgremlins(s);
}

void Tilt::next_k(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float freq = in0(1);
    const float gain = in0(2);
    float* outBuf = out(0);

    double s = mS;

    const double m = std::sqrt(computeM2(gain));
    const double mi = 1. / m;
    double g = computeG(freq);
    g = g / (1.0 + g);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double x = static_cast<double>(inBuf[i]);
        const double v = (x - s) * g;
        const double y = v + s;

        outBuf[i] = mi * y + m * (x - y);

        s = y + v;
    }

    mS = zapgremlins(s);
}
