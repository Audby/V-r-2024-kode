#include "std_lib_facilities.h"
#include <map>
#include <random>
#include <vector>
#include "card.h"

/*Definer funksjonen suitTostring(), smo tar inn en Suit og returnerer 
en string som respresenterer suit-en som tekst. F.eks Suit::spades
skal bli strengen "Spades." Lag det som en map.*/

//Oppgave 1c)
string suitToString(Suit suit) {
    map<Suit, string> suitMap;
    suitMap[Suit::clubs] = "Clubs";
    suitMap[Suit::diamonds] = "Diamonds";
    suitMap[Suit::hearts] = "Hearts";
    suitMap[Suit::spades] = "Spades";
    return suitMap[suit];
}

//Oppgave 1d)
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

//Oppgave 1e) 
/*To fordeler ved å bruke symboler (enums) framfor f.eks heltall
og strenger i koden: 
 1. Enums er mer leselig og forståelig enn heltall og strenger.
    Slipper dermed å bekymre oss så mye for navngivning.
 2. Enums er mer effektive enn strenger og heltall, fordi de er
    konstante og dermed ikke kan endres. Mindre sjanse for feil
    ved å omdefinere en enum vs en streng eller et heltall.*/


//Oppgave 2b)
Card::Card(Suit suit, Rank rank) : s{suit}, r{rank} 
{}

//Oppgave 2c)
string Card::getSuit() {
    if (s == Suit::clubs || s == Suit::spades) {
        return "Black";
    } else {
        return "Red";
    }
}

//Oppgave 2d)
string Card::getRank() {
    return rankToString(r);
}

//Oppgave 2e)
string Card::toString() const {
    return rankToString(r) + " of " + suitToString(s);
}

