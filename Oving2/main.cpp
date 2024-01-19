#include "std_lib_facilities.h"
#include <iomanip>

//Oppgave 1b
int inputAndPrintInteger() {
    int tall = 0;
    cout << "Skriv inn et tall:" << endl;
    cin >> tall;
    return tall;
}

//Oppgave 1c
int inputInteger() {
    int heltall = 0;
    cout << "Skriv inn et heltall: " << endl;
    cin >> heltall;
    return heltall;
}

//Oppgave 1d
int inputIntegersAndPrintSum() {
    cout << "Velg to tall" << endl;
    int a = 0;
    int b = 0;
    cin >> a >> b;
    cout << "Legger til to tall:" << endl;
    int resultat_1 = a + b;
    return a + b;
}

//Oppgave 1e: Brukte ingen av dem, det sto ikke i oppgaven at jeg skulle det.

//Oppgave 1f:
bool isOdd(int c) {
    if (c % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

//Oppgave 2a:
int sumInputNumbers() {
    cout << "Hvor mange heltall ønsker du? " << endl;
    int antall_heltall = 0;
    cin >> antall_heltall;
    int sum = 0;



    for (int i = 0; i<antall_heltall; i++) {
        int tall_i = 0;
        cout << "Skriv inn et tall: " << endl;
        cin >> tall_i;
        sum += tall_i;
    }
    return sum;
}

//Oppgave 2b:
int heltall_2b() {
    int tall_2b;
    int sum_2b = 0;
    cout << "Gi tall: " << endl;
    cin >> tall_2b;
    while (tall_2b != 0) {
        sum_2b += tall_2b;
        cout << "Gi tall: " << endl;
        cin >> tall_2b;
    }
    return sum_2b;

}

//Oppgave 2c: De bruker hhv. for- og while-løkker avhengig av om man vet hvor mange løkker det er snakk om eller ikke.

//Oppgave 2d:
float inputDouble() {
    float desimal_2d = 0;
    cout << "Gi desimal" << endl;
    cin >> desimal_2d;
    return desimal_2d;
}

//Oppgave 2e:
double valuta() {
    double euro = 0;
    cout << "Gi euro: " << endl;
    cin >> euro;
    while (euro < 0) {
        cout << "Gi euro: " << endl;
        cin >> euro;
    }
    double kroner = euro * 9.75;
    return kroner;
}

//Oppgave 2f: Bruker inputDouble fordi det gir bedre presisjon. Når man gjør om valuta, så er det ofte mange desimaltall som kan påvirke presisjonen i beregningene mye,
//og da trenger man gjerne mange desimaltall med.

//Oppgave 2g:
int g_tab() {
    int hoyde = 0;
    int bredde = 0;
    cout << "Oppgi hhv. høyde og bredde: " << endl;
    cin >> hoyde >> bredde;
    return hoyde, bredde;
}

{int main() {
    cout << "Hvilken funksjon ønsker du å kjøre (0-4)?" << endl;
    int funk;
    cin >> funk;

    if (funk == 0) {
        cout << "Gå videre" << endl;
    }

    if (funk == 1) {
        cout << inputIntegersAndPrintSum() << endl;
    }

    if (funk == 2) {
        cout << "Du skrev " << endl;
        cout << inputAndPrintInteger() << endl;
    }

    if (funk == 3) {
        int heltall_ut = inputInteger(); 
        cout << "Du skrev: " << heltall_ut << endl;
    }

    cout << isOdd(2) << endl;

    if (funk == 4) {
        int resultat_4 = sumInputNumbers();
        cout << "Summen av tallene er: " << resultat_4 << endl;
        return 0;
    }

    if (funk == 5) {
        int resultat_5 = heltall_2b();
        cout << resultat_5 << endl;
    }
    if (funk == 6) {
        float resultat_6 = inputDouble();
        cout << "Desimal: " << resultat_6 << endl;
    }

    if (funk == 7) {
        double resultat_7 = valuta();
        cout <<  fixed << setprecision(2);
        cout << "I kroner: " << resultat_7 << endl;
    }

    if (funk == 8) {
        int h, b;
        tie(h, b) = g_tab();
        for (int i = 1; i<=h; i++) {
            for (int j = 1; j <= h; j++) {
                cout << setw(10) << i*j << " ";
            }
        cout << endl;
        }
    }
    return 0;}
}


