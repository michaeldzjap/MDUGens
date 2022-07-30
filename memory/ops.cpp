void* operator new(decltype(sizeof(0)) n) noexcept(false) {
    //
}

void operator delete(void* p) throw() {
    //
}
