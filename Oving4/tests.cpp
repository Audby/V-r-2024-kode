#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
}