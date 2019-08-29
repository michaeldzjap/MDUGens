#include "Lowshelf.hpp"
#include "SC_PlugIn.hpp"
#include <cstdint>

using tpt_filter_ugens::Lowshelf;

Lowshelf::Lowshelf() {
    if (isAudioRateIn(1))
        set_calc_function<Lowshelf, &Lowshelf::next_a>();
    else
        set_calc_function<Lowshelf, &Lowshelf::next_k>();
}

void Lowshelf::next_a(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float* freq = in(1);
    const float gain = in0(2);
    float* outBuf = out(0);

    double s = mS;

    const double m2i = 1. / computeM2(-gain);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const float x = static_cast<double>(inBuf[i]);
        const double g = computeG(freq[i]);
        const double v = (x - s) * g / (1.0 + g);
        const double y = v + s;

        outBuf[i] = m2i * y + x - y;

        s = y + v;
    }

    mS = zapgremlins(s);
}

void Lowshelf::next_k(int inNumSamples) noexcept {
    const float* inBuf = in(0);
    const float freq = in0(1);
    const float gain = in0(2);
    float* outBuf = out(0);

    double s = mS;

    const double m2i = 1. / computeM2(-gain);
    double g = computeG(freq);
    g = g / (1.0 + g);

    for (std::size_t i = 0; i < inNumSamples; i++) {
        const double x = static_cast<double>(inBuf[i]);
        const double v = (x - s) * g;
        const double y = v + s;

        outBuf[i] = m2i * y + x - y;

        s = y + v;
    }

    mS = zapgremlins(s);
}
