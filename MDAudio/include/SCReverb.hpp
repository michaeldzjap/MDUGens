#ifndef MD_UGENS_REVERB_HPP
#define MD_UGENS_REVERB_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "Reverb.hpp"
#include "ReverbConfig.hpp"

namespace md_ugens {

    class Reverb : public SCUnit {
    public:
        explicit Reverb();

    private:
        memory::SCPool m_pool;
        md_audio::Reverb m_reverb;

        void next(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_REVERB_HPP */
