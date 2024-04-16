#include "Kjoretid.h"
#include <cmath>
#include <memory>
#include <functional>
#include <vector>

//Oppgave 1a)
void mangeOperasjoner() {
    double op;
    for (int i = 0; i < 1000000; i++) {
        op += 12*12 - 13 + 14/2;
    }
}

double runTime(const std::function<void()>& funksjon) {
    Stopwatch myTimer;
    myTimer.start();
    funksjon();
    double amountSeconds = myTimer.stop();
    return amountSeconds;
}

//Oppgave 1b)
void uniquePtrInit() {
    std::unique_ptr<double> s1 = std::make_unique<double>(13.5);
}

void sharedPtrInit() {
    std::shared_ptr<double> s2 = std::make_unique<double>(14.5);
}

constexpr int size = 10000;

void stackAllocation() {
    std::array<int, size> arr1;
}

void heapAllocation() {
    std::array<int, size>* arr2 = new std::array<int, size>;
    delete arr2;
}

//Oppgave 2:
void opprettVector() {
    std::vector<int> v;
    std::cout << "Storrelse i utgangspunktet: " << v.size() << " og kapasitet: " << v.capacity() << std::endl;    
    v.reserve(1000000);
    for (int i = 0; i < 1000000; i++) {
        v.push_back(i);
        //std::cout << "Etter aa ha lagt til " << i << " er storrelse lik " << v.size() << " og kapasitet "
        //<< v.capacity() << std::endl;
    }
}