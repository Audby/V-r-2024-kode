#pragma once
#include <iostream>
#include <utility>
class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    Dummy(const Dummy& other) {
        num = new int{*other.num};
    }
    ~Dummy() {
    delete num;
    }
    Dummy& operator=(const Dummy& other) {
        if (this != &other) {
            delete num;
            num = new int{*other.num};
        }
        return *this;
    }
};



void dummyTest();