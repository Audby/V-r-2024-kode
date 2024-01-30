#include "std_lib_facilities.h"
#include <iomanip>
#include "AnimationWindow.h"

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

//Oppgave 2g: Her får jeg uendelig tabell, men vet ikke hvorfor.
void g_tab() {
    int hoyde = 0;
    int bredde = 0;
    cout << "Oppgi hhv. høyde og bredde: " << endl;
    cin >> hoyde;
    cin >> bredde;

    for (int i = 1; i<=hoyde; i++) {
            for (int j = 1; j <= bredde; j++) {
                cout << setw(10) << i*j << " ";
            }
        cout << endl;
        }
    return;
}

//Oppgave 3a)
double discriminant(double a, double b, double c) {
    double prod = 0;
    prod = pow(b,2) - 4*a*c;
    return prod;
}

//Oppgave 3b)
void printRealRoots(double a, double b, double c) {
    double x_1, x_2;
    x_1 = (-b + sqrt(discriminant(a,b,c)))/(2*a);
    x_2 = (-b - sqrt(discriminant(a,b,c)))/(2*a);
    cout << x_1 << " " << x_2 << endl;
    return;
}

//Oppgave 3c) Gjort i oppgave 3b)

//Oppgave 4a)
int pyt(int a, int b) {
    int c;
    c = sqrt(pow(a,2) + pow(b,2));
    AnimationWindow win{100,100,150,150,"Pythagoras"};
    Point point1{25,25}, point2{75,75}, point3{25,75};
    win.draw_triangle(point1, point2, point3, Color::red);
    win.draw_quad(Point{5,25}, Point{25,25}, Point{25,75}, Point{5,75});

    win.wait_for_close();
    return 0;
}

//Oppgave 5a) Får ikke 5304.00 i stedet for 5304.00 ved år=2, men vet ikke hvorfor.
int calculateBalance(int innskudd, int rente, int aar) {
    //vector<int> t(10);
    double årsrente = 1+(rente/100.0);
    double saldo = innskudd * pow(årsrente, aar);
    return saldo;


}

//Oppgave 5b)
void printBalance(vector<int>& saldovektor) {
    cout << setw(10) << "Aar" << setw(15) << "Saldo" << endl;

    for (size_t i=0; i<saldovektor.size(); ++i) {
        cout << setw(10) << i << setw(15) << saldovektor[i] << endl;
    }
    return;
}

//Oppgave 5c) Jeg vil gjette at det handler om at man prøver ut å skrive ut en vektor uten at man vet hvilken verdi i vektoren man ønsker å skrive ut.

//Oppgave 5d) Ser ut som koden stopper opp siden det brukes i <= v.size i stedet for i<v.size. Den prøver altså å skrive ut verdier utenfor rekkevidden av det vektoren inneholder.

int main() {
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
        g_tab();
        //int b=0;
        //tie(h, b) = g_tab();
        
    }

    if (funk == 9) {
        printRealRoots(8,4,-1);
    }

    if (funk == 10) {
        pyt(3,4);
    }

    if (funk == 11) {
        double saldo = calculateBalance(5000,3,2);
        cout << fixed << setprecision(2) << saldo <<endl;
    }

    if (funk == 12) {
        vector<int> saldovektor = {5000, 5150, 5304};
        printBalance(saldovektor);
    }

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= v.size(); i++) {
        cout << v.at(i) << endl;
}

    return 0;
    }



