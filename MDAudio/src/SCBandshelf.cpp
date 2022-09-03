#include "SCBandshelf.hpp"

using md_ugens::Bandshelf;

Bandshelf::Bandshelf() :
    m_filter(
        (md_audio::Bandshelf::set_sample_rate(sampleRate()), 440.)
    )
{
    if (isAudioRateIn(1) && isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<Bandshelf, &Bandshelf::next_aaa>();
    else if (isAudioRateIn(1) && !isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<Bandshelf, &Bandshelf::next_aka>();
    else if (isAudioRateIn(1) && isAudioRateIn(2) && !isAudioRateIn(3))
        set_calc_function<Bandshelf, &Bandshelf::next_aak>();
    else if (!isAudioRateIn(1) && isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<Bandshelf, &Bandshelf::next_kaa>();
    else if (isAudioRateIn(1) && !isAudioRateIn(2) && !isAudioRateIn(3))
        set_calc_function<Bandshelf, &Bandshelf::next_akk>();
    else if (!isAudioRateIn(1) && isAudioRateIn(2) && !isAudioRateIn(3))
        set_calc_function<Bandshelf, &Bandshelf::next_kak>();
    else if (!isAudioRateIn(1) && !isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<Bandshelf, &Bandshelf::next_kka>();
    else
        set_calc_function<Bandshelf, &Bandshelf::next_kkk>();
}

void Bandshelf::next_aaa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto r = in(2);
    const auto gain = in(3);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);
        m_filter.set_r(r[i]);
        m_filter.set_gain(gain[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void Bandshelf::next_aka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto r = in0(2);
    const auto gain = in(3);
    auto outBuf = out(0);

    m_filter.set_r(r);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);
        m_filter.set_gain(gain[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void Bandshelf::next_aak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto r = in(2);
    const auto gain = in0(3);
    auto outBuf = out(0);

    m_filter.set_gain(gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);
        m_filter.set_r(r[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void Bandshelf::next_kaa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto r = in(2);
    const auto gain = in(3);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_r(r[i]);
        m_filter.set_gain(gain[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void Bandshelf::next_akk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto r = in0(2);
    const auto gain = in0(3);
    auto outBuf = out(0);

    m_filter.set_r(r);
    m_filter.set_gain(gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void Bandshelf::next_kak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto r = in(2);
    const auto gain = in0(3);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);
    m_filter.set_gain(gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_r(r[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void Bandshelf::next_kka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto r = in0(2);
    const auto gain = in(3);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);
    m_filter.set_r(r);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_gain(gain[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void Bandshelf::next_kkk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto r = in0(2);
    const auto gain = in0(3);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);
    m_filter.set_r(r);
    m_filter.set_gain(gain);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_filter.process(inBuf[i]);
}