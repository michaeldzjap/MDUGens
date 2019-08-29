#include "Highpass.hpp"
#include "SC_PlugIn.hpp"
#include <cstdint>

using tpt_filter_ugens::Highpass;

Highpass::Highpass() {
    if (isAudioRateIn(1))
        set_calc_function<Highpass, &Highpass::next_a>();
    else
        set_calc_function<Highpass, &Highpass::next_k>();
}

void Highpass::next_a(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float* freq = in(1);
    float* outBuf = out(0);

    double s = mS;

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double g = computeG(freq[i]);
        const double y = (static_cast<double>(inBuf[i]) - s) / (1.0 + g);

        outBuf[i] = y;

        s = s + y * (g + g);
    }

    mS = zapgremlins(s);
}

void Highpass::next_k(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float freq = in0(1);
    float* outBuf = out(0);

    double s = mS;

    double g = computeG(freq);
    const double g2 = g + g;
    g = 1 / (1.0 + g);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double y = (static_cast<double>(inBuf[i]) - s) * g;

        outBuf[i] = y;

        s = s + y * g2;
    }

    mS = zapgremlins(s);
}
