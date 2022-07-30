#ifndef MD_UGENS_UTIL_HPP
#define MD_UGENS_UTIL_HPP

#include "SC_PlugIn.hpp"

namespace md_ugens {

    SndBuf* get_buffer(SCUnit* unit, std::uint32_t bufnum) noexcept;

    bool check_buffer(SCUnit* unit, SndBuf* buffer, std::uint32_t expected_channels, int inNumSamples) noexcept;

}

#endif /* MD_UGENS_UTIL_HPP */
