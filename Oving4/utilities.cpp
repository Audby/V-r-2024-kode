#include "std_lib_facilities.h"
#include "utilities.h"

//Oppgave 1b):
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

//Oppgave 1c):
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i=0; i<numTimes; i++) {
        startValue += increment;
    }
}

//Oppgave 1e):
void swapNumbers(int& a, int& b) {
    int c = 0;
    c=a;
    a = b;
    b = c;
}

//Oppgave 2b)
void printStudent(const Student& Student) {
    cout << "Navn: " << Student.name << ", studieprogram: " << Student.studyProgram << ", Alder: " << Student.age << endl;
}

//Oppgave 2c)
bool isInProgram(const Student& Student, const std::string& program) {
    return Student.studyProgram == program;
    }

//Oppgave 3b):
string randomizeString() {
    
}