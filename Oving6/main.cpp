#include "std_lib_facilities.h"
#include <fstream>
#include <map>
#include "bouncingBall.h"

//Oppgave 1a)
void writeWord() {
    filesystem::path fileName{"myFile.txt"};
    ofstream outputStream(fileName);
    string userInput;
    while (userInput != "quit") {
        cout << "Skriv et ord du vil ha i fila eller skriv 'quit' for å avslutte: " << endl;
        cin >> userInput;
        outputStream << userInput << endl;
    }
}

//Oppgave 1b)
void readWord() {
    ifstream inputStream{"myFile.txt"};
    if (!inputStream) {
        cout << "Could not open file" << endl;
    }

    string nextWord;
    int i = 0;
    filesystem::path nyFil{"myFileKopi.txt"};
    ofstream nyOutputStream(nyFil);


    while(inputStream >> nextWord) {
        i += 1;
        cout << i << ". " << nextWord << endl;
        nyOutputStream << i << ". " << nextWord << endl;
    }
}

//Oppgave 1c):
const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
};

string getCapital(const string& country) {
    return capitalsMap.at(country);
    //Endret "captialsMap[country]" til det som står over.
}

//Oppgave 3
class CourseCatalog {
    private:
        map<string, string> courses;
    public:
        void addCourse(string courseName, string courseCode);
        void removeCourse(string courseCode);
        string getCourse(string courseCode);
        void writeToFile(CourseCatalog catalog);
    friend ostream& operator<<(ostream& os, const CourseCatalog& catalog);
};

void CourseCatalog::addCourse(string courseName, string courseCode) {
    //courses.insert({courseName, courseCode});
    courses[courseName] = courseCode;
}

void CourseCatalog::removeCourse(string courseCode) {
    courses.erase(courseCode); 
}

string CourseCatalog::getCourse(string courseCode) {
    //auto it = courses.find(courseCode);
    //return it->second;
    return courses.at(courseCode);
}

void CourseCatalog::writeToFile(CourseCatalog catalog) {
    filesystem::path fileName{"courseCatalog.txt"};
    ofstream outputStream(fileName);
    outputStream << catalog;
}


ostream& operator<<(ostream& os, const CourseCatalog& catalog) {
    for (const auto& course : catalog.courses) {
        os << "Kurskode: " << course.first << ", Kursnavn: " << course.second << '\n';
    }
    return os;
}

//Oppgave 3e) Virker som 'operator[]' klarer å skrive over, men ikke insert.

int main() {

    cout << "Hello, World!" << endl;

    //writeWord();

    //readWord();

    cout << "Capitals:" << endl;
    for (pair<const string, const string> elem : capitalsMap) {
        cout << getCapital(elem.first) << endl;
    }

    CourseCatalog catalog;
    catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    catalog.addCourse("TMA4100", "Matematikk 1");
    catalog.addCourse("TDT4102", "C++");
    cout << catalog;
    catalog.writeToFile(catalog);

    bouncingBall();

    return 0;
}



//------------------------------------------------------------------------------
