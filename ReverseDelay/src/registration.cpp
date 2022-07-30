#include "registration.hpp"
// #include "SCReverseDelay.hpp"
// #include "SCReversibleDelay.hpp"

// using md_ugens::ReverseDelay;
// using md_ugens::ReversibleDelay;

InterfaceTable *ft;

PluginLoad(ReverseDelay) {
    ft = inTable;
    // registerUnit<ReverseDelay>(ft, "ReverseDelay");
    // registerUnit<ReversibleDelay>(ft, "ReversibleDelay");
}
