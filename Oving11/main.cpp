#include <iostream>
#include "Kjoretid.h"
#include "optimizationTask.h"
#include <random>
#include <chrono>
#include <vector>
#include "MyArray.h"

/*
Svar oppgave 1: 
Totalt: 0.002725, per iterasjon: 2.725e-09
Unique_ptr: 9e-06 Shared_ptr: 1e-06
Stack: 2.7e-05 Heap: 2.2e-05

Oppgave 2a) Når vektoren overskrider kapasiteten, må minne allokeres på nytt, tydeligvis til det dobbelte.
   
Oppgave 2b) Når man bruker v.reserve(20), trenger ikke vektoren å utvide kapasiteten etterhvert
som den overskrider. Den har akkurat så mye plass den trenger fra starten av.

Oppgave 2c) Ved å bruke resize ble kapasiteten til vektoren kun større når det trengtes. Den tok opp
kun så mye minne som den trengte.

Oppgave 2d)
Storrelse i utgangspunktet: 0 og kapasitet: 0
Tid aa opprette en million elementer uten optimalisering: 0.005826
   
Oppgave 2e)
Tid aa opprette en million elementer med reserve: 0.005024 
Tid aa opprette en million elementer med resize: 0.007146
Ser at det tar minst tid med reserve, så uten noe allokeringsfunksjon, så med resize.
   
Oppgave 3a) Tid å kompilere: 6.24913 sekunder.

Oppgave 3b)

Byttet ut dobbel for-løkke med enkel opprettelse av dobbelvektor for å få 4.1092 sekunder.

Optimaliserte setDiagonalValue slik at tid ble 3.91773 sekunder ved å endre .at() til []
og fjernet indre løkka siden tall for rad og kolonne vil være de samme uansett.

Gikk ned til 3.3857 sekunder når jeg gjorde om .at() til [] i sumMatrix også.

Oppgave 3c) Med kompilatoroptimalisering: 3.03881 sekunder.

*/

//Oppgave 4a)
template<typename T>
T maximum(T a, T b) {
    return (a>b) ? a : b;
}

//Oppgave 4b)
template<typename T>
void shuffle(std::vector<T>& vec) {
    std::random_device rd;
    std::mt19937 g(rd());

    for (size_t i = 0; i< vec.size(); i++) {
        std::uniform_int_distribution<size_t> distribution(i, vec.size() -1);
        size_t j = distribution(g);
        std::swap(vec[i], vec[j]);
    }
}

//Oppgave 5a) og 5b)


int main() {
    /*
    Oppgave 1:
    double timeOneMill = runTime(mangeOperasjoner);
    double timePerIt = timeOneMill / 1000000;

    double timeUniquePtrInit = runTime(uniquePtrInit);
    double timeSharedPtrInit = runTime(sharedPtrInit);

    double timeStack = runTime(stackAllocation);
    double timeHeap = runTime(heapAllocation);

    std::cout << "Totalt: " << timeOneMill << ", per iterasjon: " << timePerIt << std::endl;
    std::cout << "Unique_ptr: " << timeUniquePtrInit << " Shared_ptr: " << timeSharedPtrInit << std::endl;
    std::cout << "Stack: " << timeStack << " Heap: " << timeHeap << std::endl;
    */

   /*
   Oppgave 2:

   double timeVector = runTime(opprettVector);
   std::cout << "Tid aa opprette en million elementer med resize: " << timeVector << std::endl;
   
   Oppgave 3:

   double timeOptimizationTask = runTime(optimizationTask);
   std::cout << timeOptimizationTask << std::endl;

   */
   
    //Oppgave 4a)

    int a = 1;
    int b = 2;
    int c = maximum<int>(a,b);

    double d = 2.4;
    double e = 3.2;
    double f = maximum<double>(d,e);

    //Oppgave 4b)
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    shuffle(vec);
    std::cout << "Stokket vektor: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << "\n";


    //Oppgave 5)
    try {
        MyArray<int, 5> intArray;
        intArray.fill(10);
        std::cout << "Int array elementer: ";
        for (int i = 0; i < intArray.getSize(); i++) {
            std::cout << intArray.at(i) << " ";
        }
        std::cout << std::endl;

        MyArray<double, 3> doubleArray;
        doubleArray.fill(3.14);
        std::cout << "Double array elementer: ";
        for (int i = 0; i < doubleArray.getSize(); i++) {
            std::cout << doubleArray.at(i) << " ";
        }
        std::cout << std::endl;

        // Accessing out of bounds
        std::cout << "Accessing out of bounds: " << intArray.at(5) << std::endl;

    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
