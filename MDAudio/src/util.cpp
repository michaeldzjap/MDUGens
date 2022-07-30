#include "registration.hpp"
#include "util.hpp"

SndBuf* md_ugens::get_buffer(SCUnit* unit, std::uint32_t bufnum) noexcept {
    SndBuf *buffer;
	auto world = unit->mWorld;

	if (bufnum >= world->mNumSndBufs) {
		auto local_bufnum = bufnum - world->mNumSndBufs;
		auto parent = unit->mParent;

		if (local_bufnum <= parent->localMaxBufNum)
			buffer = parent->mLocalSndBufs + local_bufnum;
		else {
			bufnum = 0;
            buffer = world->mSndBufs + bufnum;
		}
	} else
		buffer = world->mSndBufs + bufnum;

	return buffer;
}

bool md_ugens::check_buffer(
    SCUnit* unit,
    SndBuf* buffer,
    std::uint32_t expectedChannels,
    int inNumSamples
) noexcept {

    if (!buffer->data)
        goto fail;

    if (expectedChannels > buffer->channels) {
        if (unit->mWorld->mVerbosity > -1 && !unit->mDone)
            Print("Buffer UGen channel mismatch: expected %i, yet buffer has %i channels\n", expectedChannels, buffer->channels);

        goto fail;
    }

    return true;

fail:
    unit->mDone = true;
    ClearUnitOutputs(unit, inNumSamples);

    return false;
}
