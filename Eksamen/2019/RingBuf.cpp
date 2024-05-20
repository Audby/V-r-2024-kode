#include "RingBuf.h"

RingBuf::RingBuf(int capacity) : 
buf{new char[capacity]}, capacity{capacity}, start{0}, size{0} {}

RingBuf::RingBuf(const RingBuf &other) : buf{new char[other.capacity]}, 
capacity{other.capacity}, start{other.start}, size{other.size} {
    for (int i = 0; i < capacity; i++) {
        buf[i] = other.buf[i];
    }
}

RingBuf::~RingBuf() {
    delete[] buf;
}

RingBuf::RingBuf(RingBuf &&other) : 
buf{other.buf}, capacity{other.capacity}, start{other.start}, size{other.size} {
    other.buf = nullptr;
    other.capacity = 0;
    other.start = 0;
    other.size = 0;
}

RingBuf& RingBuf::operator=(RingBuf rhs) {
    char* b = new char[rhs.capacity];
    for (int i = 0; i < rhs.capacity; i++) {
        b[i] = rhs.buf[i];
    }
    delete[] buf;
    capacity = rhs.capacity;
    start = rhs.start;
    size = rhs.size;
    buf = b;
    return *this;
}