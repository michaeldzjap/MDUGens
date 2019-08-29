#include "SC_PlugIn.h"

static InterfaceTable *ft;

struct SOSBank : public Unit
{
    int m_numSecs;
    int m_size_a0;
    int m_size_a1;
    int m_size_a2;
    int m_size_b1;
    int m_size_b2;
    
    float *m_a0;
    float *m_a1;
    float *m_a2;
    float *m_b1;
    float *m_b2;
    
    // state vectors
    float *m_v1, *m_v2;
};

extern "C"
{
    static void SOSBank_next(SOSBank *unit, int inNumSamples);
    static void SOSBank_Ctor(SOSBank *unit);
    static void SOSBank_Dtor(SOSBank *unit);
}

inline float32 kill_denormals(float32 x)
{
    static const float anti_denormal = 1e-18;
    x += anti_denormal;
    x -= anti_denormal;
    return x;
}

SndBuf *getBuffer(Unit *unit, uint32 bufnum) {
    SndBuf *buf;
    World *world = unit->mWorld;
    if (bufnum >= world->mNumSndBufs) {
        int localBufNum = bufnum - world->mNumSndBufs;
        Graph *parent = unit->mParent;
        if (localBufNum <= parent->localMaxBufNum)
            buf = parent->mLocalSndBufs + localBufNum;
        else {
            if (unit->mWorld->mVerbosity > -1) {
                Print("SOSBank buffer number error: invalid buffer number: %i\n", bufnum);
                SETCALC(*ClearUnitOutputs);
                unit->mDone = true;
                return NULL;
            }
        }
    } else
        buf = world->mSndBufs + bufnum;
    
    return buf;
}

void SOSBank_Ctor(SOSBank* unit)
{
    int numSecs = 0;
    int numOutputs = unit->mNumOutputs;
    int size_a0, size_a1, size_a2, size_b1, size_b2;
    size_a0 = size_a1 = size_a2 = size_b1 = size_b2 = 0;
    
    int bufnum = (int)ZIN0(1);
    SndBuf *buf;
    if (bufnum >= 0) {
        buf = getBuffer(unit, (uint32)bufnum);
        size_a0 = buf->samples;
        numSecs = size_a0/numOutputs;
        unit->m_a0 = buf->data;
    }
    bufnum = (uint32)ZIN0(2);
    if (bufnum >= 0) {
        buf = getBuffer(unit, (uint32)bufnum);
        size_a1 = buf->samples;
        if (numSecs == 0) { numSecs = size_a1/numOutputs; }
        unit->m_a1 = buf->data;
    }
    bufnum = (uint32)ZIN0(3);
    if (bufnum >= 0) {
        buf = getBuffer(unit, (uint32)bufnum);
        size_a2 = buf->samples;
        if (numSecs == 0) { numSecs = size_a2/numOutputs; }
        unit->m_a2 = buf->data;
    }
    bufnum = (uint32)ZIN0(4);
    if (bufnum >= 0) {
        buf = getBuffer(unit, (uint32)bufnum);
        size_b1 = buf->samples;
        if (numSecs == 0) { numSecs = size_b1; }
        unit->m_b1 = buf->data;
    }
    bufnum = (uint32)ZIN0(5);
    if (bufnum >= 0) {
        buf = getBuffer(unit, (uint32)bufnum);
        size_b2 = buf->samples;
        if (numSecs == 0) { numSecs = size_b2; }
        unit->m_b2 = buf->data;
    }
    unit->m_numSecs = numSecs;
    
    unit->m_v1 = (float*)RTAlloc(unit->mWorld, numSecs*sizeof(float));
    unit->m_v2 = (float*)RTAlloc(unit->mWorld, numSecs*sizeof(float));
    memset((float*)unit->m_v1, 0, numSecs*sizeof(float));
    memset((float*)unit->m_v2, 0, numSecs*sizeof(float));
    
    // in case no coefficients are specified
    int n = numSecs*numOutputs;
    if (size_a0 == 0) {
        unit->m_a0 = (float*)RTAlloc(unit->mWorld, n*sizeof(float));
        memset((float*)unit->m_a0, 0, n*sizeof(float));
    }
    if (size_a1 == 0) {
        unit->m_a1 = (float*)RTAlloc(unit->mWorld, n*sizeof(float));
        memset((float*)unit->m_a1, 0, n*sizeof(float));
    }
    if (size_a2 == 0) {
        unit->m_a2 = (float*)RTAlloc(unit->mWorld, n*sizeof(float));
        memset((float*)unit->m_a2, 0, n*sizeof(float));
    }
    if (size_b1 == 0) {
        unit->m_b1 = (float*)RTAlloc(unit->mWorld, numSecs*sizeof(float));
        memset((float*)unit->m_b1, 0, numSecs*sizeof(float));
    }
    if (size_b2 == 0) {
        unit->m_b2 = (float*)RTAlloc(unit->mWorld, numSecs*sizeof(float));
        memset((float*)unit->m_b2, 0, numSecs*sizeof(float));
    }
    unit->m_size_a0 = size_a0;
    unit->m_size_a1 = size_a1;
    unit->m_size_a2 = size_a2;
    unit->m_size_b1 = size_b1;
    unit->m_size_b2 = size_b2;
    
    SETCALC(SOSBank_next);
    
    SOSBank_next(unit, 1);
}

void SOSBank_next(SOSBank *unit, int inNumSamples)
{
    float *in = ZIN(0);
    int numOutputs = unit->mNumOutputs;
    int numSecs = unit->m_numSecs;
    
    float *v1 = unit->m_v1, *v2 = unit->m_v2;
    float *b1 = unit->m_b1, *b2 = unit->m_b2;
    float *a0 = unit->m_a0, *a1 = unit->m_a1, *a2 = unit->m_a2;
    for (int i=0; i<inNumSamples; ++i) {
        float input = ZXP(in);
        for (int j=0; j<numOutputs; ++j) { OUT(j)[i] = 0.0; }
        
        for (int n=0; n<numSecs; ++n) {
            float v = input - b1[n]*v1[n] - b2[n]*v2[n];
            for (int channel=0; channel<numOutputs; ++channel) {
                int ind = n + channel*numSecs;
                OUT(channel)[i] += a0[ind]*v + a1[ind]*v1[n] + a2[ind]*v2[n];
            }
            //v2[n] = kill_denormals(v1[n]); v1[n] = kill_denormals(v);
            v2[n] = v1[n]; v1[n] = v;
        }
        
    }
}

void SOSBank_Dtor(SOSBank *unit)
{
    RTFree(unit->mWorld, unit->m_v1);
    RTFree(unit->mWorld, unit->m_v2);
    if (unit->m_size_a0 == 0)
        RTFree(unit->mWorld, unit->m_a0);
    if (unit->m_size_a1 == 0)
        RTFree(unit->mWorld, unit->m_a1);
    if (unit->m_size_a2 == 0)
        RTFree(unit->mWorld, unit->m_a2);
    if (unit->m_size_b1 == 0)
        RTFree(unit->mWorld, unit->m_b1);
    if (unit->m_size_b2 == 0)
        RTFree(unit->mWorld, unit->m_b2);
}

PluginLoad(SOSBank)
{
    ft = inTable;
    DefineDtorUnit(SOSBank);
}


