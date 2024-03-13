#include <iostream>


//Oppgave 1a)
void fillInFibonacciNumbers(int* result, int length) {
    result[0] = 0;
    result[1] = 1;
    result[2] = 1;
    for (int i = 3; i < length; i++){
        result[i] = result[i-1] + result[i-2];
    }
}

//Oppgave 1b)
void printArray(int* arr, int length) {
    fillInFibonacciNumbers(arr, length);
    for (int i = 0; i<length; i++) {
        std::cout << arr[i] << " ";
    }
}

//Oppgave 1c)
void createFibonacci() {
    int size;
    // 1. Spør brukeren hvor mange tall som skal genereres
    std::cout << "Hvor mange tall onsker du aa generere? " << std::endl;
    std::cin >> size;
    // 2. Alloker minne til en tabell som er stor nok til tallrekka
    int* fibSequence = new int[size];
    // 3. Fylle tabellen med fillInFibonacciNumbers()
    fillInFibonacciNumbers(fibSequence, size);
    // 4. Skriv ut resultatet til skjerm med printArray()
    printArray(fibSequence, size);
    // 5. Frigjør minnet du har reservert
    delete[] fibSequence;

}

int main() {

    //Oppgave 1b)
    printArray(new int[10], 10);

    //Oppgave 1c)
    createFibonacci();




    return 0;
}

//------------------------------------------------------------------------------
