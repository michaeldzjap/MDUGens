#include "SCTapDelay.hpp"
#include "util.hpp"
#include "InterpolationType.hpp"

using md_ugens::TapDelay;

TapDelay::TapDelay() :
    m_pool(mWorld),
    m_delay(
        (md_audio::TapDelay::set_sample_rate(sampleRate()), m_pool),
        in0(2),
        mNumOutputs,
        static_cast<md_audio::InterpolationType>(in0(3))
    )
{
    try {
        m_delay_times = static_cast<float*>(m_pool.allocate(sizeof(float) * mNumOutputs));
        m_delay_slopes = static_cast<float*>(m_pool.allocate(sizeof(float) * mNumOutputs));
    } catch (const std::bad_alloc&) {
        Print("Could not allocate real-time memory for TapDelay\n");
        set_calc_function<TapDelay, &TapDelay::clear>();

        mDone = true;

        return;
    }

    md_audio::TapDelay::set_sample_rate(sampleRate());

    set_calc_function<TapDelay, &TapDelay::next>();
}

void TapDelay::next(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto bufnum = static_cast<std::uint32_t>(in0(1));

    auto buffer = get_buffer(this, bufnum);

    if (!check_buffer(this, buffer, 1, inNumSamples)) return;

    const auto data = buffer->data;

    for (auto i = 0; i < mNumOutputs; ++i)
        m_delay_slopes[i] = calcSlope(data[i], m_delay_times[i]);

    for (auto j = 0; j < inNumSamples; ++j) {
        auto in = inBuf[j];

        for (auto i = 0; i < mNumOutputs; ++i) {
            m_delay_times[i] += m_delay_slopes[i];

            m_delay.set_delay(i, m_delay_times[i]);

            out(i)[j] =  m_delay.read(i);
        }

        m_delay.write(in);
    }
}

void TapDelay::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}

TapDelay::~TapDelay() {
    if (m_delay_times) m_pool.deallocate(m_delay_times);
    if (m_delay_slopes) m_pool.deallocate(m_delay_slopes);
}
