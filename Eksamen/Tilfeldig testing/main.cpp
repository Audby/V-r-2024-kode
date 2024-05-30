//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

vector<int> obj1 = {1,2,3};
vector<int> obj2 = {4,5,6};

void print_elementvise_sum(vector<int> obj1, vector<int> obj2) {
    if (obj1.size() != obj2.size()) {
        cout << "Dimensions don't add";
    }
    while (obj1.size() > 0) {
        cout << obj1.back() + obj2.back() << endl;
        obj1.pop_back();
        obj2.pop_back();
    }
    return;
}

void print_elementvise_sum2(vector<int> obj1, vector<int> obj2) {
    if (obj1.size() != obj2.size()) {
        cout << "Dimensions don't add";
    }
    else if (obj1.size() > 0) {
        cout << obj1.back() + obj2.back() << endl;
        obj1.pop_back();
        obj2.pop_back();
        return print_elementvise_sum2(obj1, obj2);
    }
    return;
}

int main() {

    print_elementvise_sum(obj1, obj2);
    cout << "Neste";
    print_elementvise_sum2(obj1, obj2);

    return 0;
}

//------------------------------------------------------------------------------
