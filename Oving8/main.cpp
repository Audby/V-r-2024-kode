#include <iostream>
#include "Matrix.h"
#include "dummy.h"

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
    std::cout << std::endl;
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

//Oppgave 3a) a,b,c: a: 4, b:4, c:4, a:4, b:3, c:5, dette fordi pekere endrer verdier, men ikke for a.

//Oppgave 3b) Nei det stemte ikke. Sannsynligvis på grunn av forvirring mellom pekere og adresser.

//Oppgave 3c) Ja, fikk b=3 i stedet for b=5...

//Oppgave 3d) Ja.

int main() {

    //Oppgave 1b)
    printArray(new int[10], 10);

    //Oppgave 1c)
    //createFibonacci();

    //Oppgave 2) test
    Matrix matrix1(2, 3);
    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;

    Matrix matrix2(3);
    std::cout << "Matrix 2 (Identity matrix):" << std::endl;
    std::cout << matrix2 << std::endl;

    matrix1.set(0, 0, 1.0);
    matrix1.set(0, 1, 2.0);
    matrix1.set(1, 0, 3.0);
    matrix1.set(1, 2, 4.0);
    std::cout << "Matrix 1 (updated):" << std::endl;
    std::cout << matrix1 << std::endl;

    double value = matrix1.get(0, 1);
    std::cout << "Value at position (0, 1): " << value << std::endl;

    int rows = matrix1.getRows();
    int columns = matrix1.getColumns();
    std::cout << "Matrix 1 dimensions: " << rows << " x " << columns << std::endl;

    dummyTest();

    Matrix matrix6(3, 3);
    matrix6.set(0, 0, 1.0);
    matrix6.set(1, 1, 2.0);
    matrix6.set(2, 2, 3.0);
    std::cout << "Matrix 6:\n" << matrix6 << std::endl;

    Matrix matrix5(matrix6);
    std::cout << "Matrix 5 (kopi av Matrix 6):\n" << matrix5 << std::endl;

    // Test tilordningsoperatoren med en ikke-kvadratisk matrise
    Matrix matrix3(2, 3);
    matrix3.set(0, 0, 4.0);
    matrix3.set(0, 1, 5.0);
    matrix3.set(1, 2, 6.0);
    std::cout << "Matrix 3:\n" << matrix3 << std::endl;

    Matrix matrix4(3, 2);
    matrix4 = matrix3;
    std::cout << "Matrix 4 (assigned from Matrix 3):\n" << matrix4 << std::endl;

    // Test selvtilordning
    matrix4 = matrix4;
    std::cout << "Matrix 4 (self-assigned):\n" << matrix4 << std::endl;

    Matrix matrix7(2, 2);
    matrix7.set(0, 0, 1.0);
    matrix7.set(0, 1, 2.0);
    matrix7.set(1, 0, 3.0);
    matrix7.set(1, 1, 4.0);
    std::cout << "Matrix 7:\n" << matrix7 << std::endl;

    Matrix matrix8(2, 2);
    matrix8.set(0, 0, 5.0);
    matrix8.set(0, 1, 6.0);
    matrix8.set(1, 0, 7.0);
    matrix8.set(1, 1, 8.0);
    std::cout << "Matrix 8:\n" << matrix8 << std::endl;

    matrix5 += matrix6;
    std::cout << "Matrix 7 after adding Matrix 8:\n" << matrix5 << std::endl;

    return 0;
}

//------------------------------------------------------------------------------
