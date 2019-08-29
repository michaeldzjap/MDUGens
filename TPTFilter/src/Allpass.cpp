#include "Allpass.hpp"
#include "SC_PlugIn.hpp"
#include <cstdint>

using tpt_filter_ugens::Allpass;

Allpass::Allpass() {
    if (isAudioRateIn(1))
        set_calc_function<Allpass, &Allpass::next_a>();
    else
        set_calc_function<Allpass, &Allpass::next_k>();
}

void Allpass::next_a(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float* freq = in(1);
    float* outBuf = out(0);

    double s = mS;

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double g = computeG(freq[i]);
        const double xs = static_cast<double>(inBuf[i]) - s;
        s = s + xs * (2.0 * g / (1.0 + g));
        const double y = s - xs;

        outBuf[i] = y;
    }

    mS = zapgremlins(s);
}

void Allpass::next_k(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float freq = in0(1);
    float* outBuf = out(0);

    double s = mS;

    double g = computeG(freq);
    g = 2.0 * g / (1.0 + g);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double xs = static_cast<double>(inBuf[i]) - s;
        s = s + xs * g;
        const double y = s - xs;

        outBuf[i] = y;
    }

    mS = zapgremlins(s);
}
