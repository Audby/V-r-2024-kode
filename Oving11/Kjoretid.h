#pragma once
#include <iostream>
#include "Stopwatch.h"
#include <functional>

double runTime(const std::function<void()>& funksjon);

void mangeOperasjoner();

void uniquePtrInit();

void sharedPtrInit();

void stackAllocation();

void heapAllocation();

void opprettVector();