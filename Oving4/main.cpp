#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

//Oppgave 1a): v0 = 5 + 2*10 = 25.

//Oppgave 1e): Ønsker å bruke referanser for å bytte heltall for å
//sikre at ikke lokale variabler brukes, men de vi faktisk ønsker å ta inn.

//void swapNumbers(int&a, int&b);

int main() {
    
    //Oppgave 1e):
    int x = 5;
    int y = 10;
    cout << "x: " << x << " y: " << y << endl;
    swapNumbers(x,y);
    cout << "Swap: x = " << x << " y = " << y << endl;

    //Oppgave 2b):
    Student Student("Ola", "Kyb", 21);
    printStudent(Student);

    //Oppgave 2c):
    if (isInProgram(Student, "Data")) {
        cout << Student.name << " er påmeldt studieprogrammet Data" << endl;
    } else {
        cout << Student.name << " er ikke påmeldt studieprogrammet Data" << endl;
    }

    return 0;
}
