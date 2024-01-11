//Oppgave 1:

/*
Oppgave 1a) Kode til python:

def isFibonacciNumber(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b += a
        a = temp
    
    return b

*/

//Oppgave 2:

//2a)

#include "std_lib_facilities.h"
#include <SDL.h>


int maxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
        return a;
    } else {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

int main(int argc, char* argv[]) {

    int resultat = maxOfTwo(5, 6);
    cout << "Oppgave a)" << endl;
    cout << resultat << endl;

    return 0;
}