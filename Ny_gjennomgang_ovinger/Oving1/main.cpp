
#include "std_lib_facilities.h"
#include <vector>
#include <cmath>

void inputAndPrintInteger() {
    int heltall;
    cout << "Skriv et heltall" << endl;
    cin >> heltall;
    cout << "Du skrev: " << heltall << endl;
}

int inputInteger() {
    int tall;
    cout << "Skriv et heltall " << endl;
    cin >> tall;
    return tall;
}

bool isOdd(int number) {
    return number % 2 != 0;
}

vector<double> calculateBalance(double innskudd, double rente, int aar) {
    vector<double> saldoer;
    saldoer.push_back(innskudd);
    for (int i = 1; i<=aar; i++)
    {
        double saldo = innskudd * pow(1+rente/100,i);
        saldoer.push_back(saldo);
    }
    return saldoer;
 }

int main() {

    //inputAndPrintInteger();

    /*int number = inputInteger();
    cout << "Du skrev: " << number << "\n";
    cout << isOdd(number) << endl;*/
    
    double innskudd = 5000;
    double rente = 3;
    int ar = 5;

    vector<double> saldoer = calculateBalance(innskudd, rente, ar);
    for (int j = 0; j <= ar; ++j) {
        std::cout << "Saldo etter aarr " << j << ": " << saldoer[j] << " kroner" << std::endl;
    }


    return 0;
}

//------------------------------------------------------------------------------
