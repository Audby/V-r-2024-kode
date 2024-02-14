#include "std_lib_facilities.h"
#include "utilities.h"
#include <random>
#include <cctype>
#include <vector>

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

int randomWithLimits(int nedre, int ovre) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(nedre,ovre);
    int tilf = distribution(generator);
    return tilf;
}

//Oppgave 3b):

string randomizeString(int lengde, char nedre, char ovre) {
    string tilfeldigstreng;
    for (int i=0; i<lengde; i++) {
        tilfeldigstreng += randomWithLimits(nedre, ovre);
    }
    return tilfeldigstreng;
}

//Oppgave 3c) og 3f)

void testString() {
    string grades = randomizeString(8, 'A', 'F');
    cout << "Tilfeldige karakterer: " << grades << endl;

    vector<int> gradeCount(6);
    for (char c : grades) {
        gradeCount[c-65] += 1;
    }
    int sum = 0;
    for (int i=0; i<6; i++) {
        sum += gradeCount[i]*(6-i);
    }
    cout << "Snittkarakter: " << sum/8.0 << endl;
    
        
}


//Oppgave 3d)

string readInputToString(int lengde, char nedre, char ovre) {
    string input;
    char tegn;
    for (int i=0; i<lengde; i++) {
        cout << "Skriv inn tegn " << i+1 << " av " << lengde << " (" << nedre << "-" << ovre << "): ";
        cin >> tegn;
        tegn = toupper(tegn);
        if (tegn >= nedre && tegn <= ovre) {
            input += tegn;
        } else {
            cout << "Ugyldig tegn, prøv igjen." << endl;
            i--;
        }
    }
    return input;
}



//Oppgave 3e)
int countChar(string tilfeldigstreng, char tegn) {
    int antall = 0;
    for (char c : tilfeldigstreng) {
        if (c == tegn) {
            antall += 1;
        }
    }
    return antall;
}

