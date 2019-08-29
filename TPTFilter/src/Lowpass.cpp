#include "Lowpass.hpp"
#include "SC_PlugIn.hpp"
#include <cstdint>

using tpt_filter_ugens::Lowpass;

Lowpass::Lowpass() {
    if (isAudioRateIn(1))
        set_calc_function<Lowpass, &Lowpass::next_a>();
    else
        set_calc_function<Lowpass, &Lowpass::next_k>();
}

void Lowpass::next_a(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float* freq = in(1);
    float* outBuf = out(0);

    double s = mS;

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double g = computeG(freq[i]);
        const double v = (static_cast<double>(inBuf[i]) - s) * g / (1.0 + g);
        const double y = v + s;

        outBuf[i] = y;

        s = y + v;
    }

    mS = zapgremlins(s);
}

void Lowpass::next_k(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float freq = in0(1);
    float* outBuf = out(0);

    double s = mS;

    double g = computeG(freq);
    g = g / (1.0 + g);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double v = (static_cast<double>(inBuf[i]) - s) * g;
        const double y = v + s;

        outBuf[i] = y;

        s = y + v;
    }

    mS = zapgremlins(s);
}
