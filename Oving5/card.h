#include "std_lib_facilities.h"

//Oppgave 1a)
enum class Suit {clubs, diamonds, hearts, spades};

enum class Rank {
    two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

//Oppgave 1b)
string suitToString(Suit suit);

//Oppgave 1c)
string rankToString(Rank rank);

//Oppgave 2a)
/*Deklarer klassen Card. Denne klassen skal inneholde følgende private medlemsvariabler:
• Suit s, en variabel av enum-typen Suit, som definert i oppgave 1.
• Rank r, en variabel av enum-typen Rank, som definert i oppgave 1.
*/
class Card {
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank); 
        string getSuit();
        string getRank();
        string toString() const;
        int getValue() const;

};

