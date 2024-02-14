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

//Oppgave 3b)
int randomWithLimits(int nedre, int ovre);

string randomizeString(int lengde, char nedre, char ovre);

//Oppgave 3c)
void testString();

//Oppgave 3d)
string readInputToString(int lengde, char nedre, char ovre);

int countChar(string tilfeldigstreng, char tegn);