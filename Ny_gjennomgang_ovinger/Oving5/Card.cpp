#include "std_lib_facilities.h"
#include "Card.h"
#include <map>

string suitToString(Suit suit) {
    map<Suit, string> suitMap;
    suitMap[Suit::clubs] = "Clubs";
    suitMap[Suit::spades] = "Spades";
    suitMap[Suit::hearts] = "Hearts";
    suitMap[Suit::diamonds] = "Diamonds";
    return suitMap[suit];
}

string rankToString(Rank rank) {
    map<Rank, string> rankMap;
    rankMap[Rank::two] = "Two";
    rankMap[Rank::three] = "Three";
    rankMap[Rank::four] = "Four";
    rankMap[Rank::five] = "Five";
    rankMap[Rank::six] = "Six";
    rankMap[Rank::seven] = "Seven";
    rankMap[Rank::eight] = "Eight";
    rankMap[Rank::nine] = "Nine";
    rankMap[Rank::ten] = "Ten";
    rankMap[Rank::jack] = "Jack";
    rankMap[Rank::queen] = "Queen";
    rankMap[Rank::king] = "King";
    rankMap[Rank::ace] = "Ace";
    return rankMap[rank];
}

//Oppgave 1e): Én fordel er at det er vanskelig å få error ved skrivefeil av for eksempel strenger.
//             En annen fordel er at det er mye mer intuitivt å behandle rank som verdier. Det er da
//             også vanskelig å omdefinere enums siden de er en forhåndsdefinert klasse.

Card::Card(Suit suit, Rank rank) : s(suit), r(rank) {}

Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
}

string Card::toString() {
    return rankToString(r) + " of " + suitToString(s); 
}