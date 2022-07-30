#include "SCTapDelayStatic.hpp"
#include "util.hpp"

using md_ugens::TapDelayStatic;

TapDelayStatic::TapDelayStatic() :
    m_pool(mWorld),
    m_delay(
        (md_audio::TapDelayStatic::set_sample_rate(sampleRate()), m_pool),
        in0(2),
        mNumOutputs
    )
{
    md_audio::TapDelayStatic::set_sample_rate(sampleRate());

    const auto bufnum = static_cast<std::uint32_t>(in0(1));
    auto buffer = get_buffer(this, bufnum);

    if (!check_buffer(this, buffer, 1, 1)) return;

    const auto data = buffer->data;

    for (auto i = 0; i < mNumOutputs; ++i)
        m_delay.set_delay(i, data[i]);

    set_calc_function<TapDelayStatic, &TapDelayStatic::next>();
}

void TapDelayStatic::next(int inNumSamples) noexcept {
    const auto inBuf = in(0);

    for (auto j = 0; j < inNumSamples; ++j) {
        auto in = inBuf[j];

        for (auto i = 0; i < mNumOutputs; ++i)
            out(i)[j] =  m_delay.read(i);

        m_delay.write(in);
    }
}

void TapDelayStatic::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
