#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int& a, int& b);

//Oppgave 2a):
struct Student {
    string name;
    string studyProgram;
    int age;
};

void printStudent(const Student& Student);

bool isInProgram(const Student& student, const std::string& program);
