#include "std_lib_facilities.h"
#include "spill.h"
#include "utilities.h"

constexpr int wordsize = 4;
//constexpr int letters = 6;

//Oppgave 4a) Bruker "constexpr" siden verdien er kjent ved kompilseringstid. 

void playMastermind() {

    string code = randomizeString(wordsize, 'A', 'F');
    string guess = "";
    cout << code << endl;
    
    guess = readInputToString(wordsize, 'A', 'F');

/*Utvid koden din slik at spilleren har et begrenset antall forsøk på å gjette koden.*/

    int attempts = 0;
    while (attempts < 10) {
        int correct = checkCharactersAndPosition(code, guess);
        int correct2 = checkCharacters(code, guess);
        cout << "Antall riktige bokstaver på riktig plass: " << correct << endl;
        cout << "Antall riktige bokstaver: " << correct2 << endl;
        if (correct == wordsize) {
            cout << "Gratulerer, du klarte det!" << endl;
            break;
        }
        attempts += 1;
        guess = readInputToString(wordsize, 'A', 'F');
    }
    cout << "Du har brukt opp alle forsøkene dine." << endl;
    cout << "Riktig kode var: " << code << endl;


    char playAgain;
    cout << "Vil du spille igjen? (j/n): ";
    cin >> playAgain;
    if (playAgain == 'j') {
        playMastermind();
    } else {
        cout << "Takk for at du spilte!" << endl;
    }

}

int checkCharactersAndPosition(string code, string guess) {
    int correct = 0;
    for (int i=0; i<wordsize; i++) {
        if (code[i] == guess[i]) {
            correct += 1;
        }
    }
    return correct;
}



int checkCharacters(string code, string guess) {
    int correct = 0;
    for (int i=0; i<wordsize; i++) {
        for (int j=0; j<wordsize; j++) {
            if (code[i] == guess[j]) {
                correct += 1;
            }
        }
    }
    return correct;
}

