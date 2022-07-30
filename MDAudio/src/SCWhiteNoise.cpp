#include "SCWhiteNoise.hpp"

using md_ugens::WhiteNoise;

WhiteNoise::WhiteNoise() {
    set_calc_function<WhiteNoise, &WhiteNoise::next>();
}

void WhiteNoise::next(int inNumSamples) noexcept {
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_noise.perform();
}
