#include "std_lib_facilities.h"
#include <iostream>

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

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers:" << endl;
    for (int i = 1; i <=n; ++i) {
        cout << i << " " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 1; i <= n; ++i) {
        totalSum += i * i;
        cout << i * i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n) {
        cout << acc << " " << endl;
        acc += num;
        num += 1;
    }
    cout << endl;
}

bool isPrime(int n) {
    for (int j = 2; j < n; ++j) {
        if (n % j == 0) {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n) {
    for (int number = 2; number < n; ++number) {
        if (isPrime(number)) {
            cout << number << " is a prime" << endl;
        }
    }
}

void inputAndPrintNameAndAge() {
    string navn;
    int alder;

    cout << "Skriv inn et navn: " << endl;
    cin >> navn;

    cout << "Skriv inn alderen til " << navn << ": " << endl;
    cin >> alder;

    cout << navn << " er " << alder << " aar gammel." << endl;

}

int main() {

    cout << "Oppgave a)" << endl;
    int resultat_a = maxOfTwo(5, 6);
    cout << resultat_a << endl;

    cout << "Oppgave c)" << endl;
    int resultat_c = fibonacci(5);
    cout << resultat_c << endl;

    cout << "Oppgave d)" << endl;
    int resultat_d = squareNumberSum(5);
    cout << resultat_d << endl;

    cout << "Oppgave e)" << endl;
    triangleNumbersBelow(10);
    cout << endl;

    cout << "Oppgave f) og g)" << endl;
    naivePrimeNumberSearch(14);

    inputAndPrintNameAndAge();

    return 0;
}

//Spørsmål: Får ut alder ved input, kan man hindre at dette skjer?