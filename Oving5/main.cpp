#include "std_lib_facilities.h"
#include "card.h"

int main() {

    //Oppgave 1f)
    Rank r = Rank::king;
    Suit s = Suit::hearts;
    string rank = rankToString(r);
    string suit = suitToString(s);
    cout << "Rank: " << rank << " Suit: " << suit << endl;

    //Oppgave 2f)
    Card Card{Suit::spades, Rank::ace};
    cout << Card.toString() << '\n';


    return 0;
}
