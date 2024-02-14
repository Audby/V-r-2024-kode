#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "spill.h"

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

    //Oppgave 3b) Den kan generere tilfeldige tall, men får opp alle mulige rare symboler, ikke bare bokstaver.
    cout << randomizeString(9,65,90) << endl;

    //Oppgave 3c)
    testString();

    //Oppgave 3d)
    //cout << readInputToString(5, 'A', 'G') << endl;

    //Oppgave 3e)
    //cout << "Oppgave 3e) " << countChar("AAAEEE", 'A') << endl;
    
    //Oppgave 4e)
    //cout << "Oppgave 4e) " << checkCharactersAndPosition("ABCD", "CDEE") << endl;

    //Oppgave 4f)
    //cout << "Oppgave 4f) " << checkCharacters("ABCD", "CDEE") << endl;

    playMastermind();

    return 0;
}


