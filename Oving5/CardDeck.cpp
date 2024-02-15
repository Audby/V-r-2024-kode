#include "std_lib_facilities.h"
#include "CardDeck.h"
#include <random>
#include <vector>



//Oppgave 3b)
CardDeck::CardDeck() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card{static_cast<Suit>(i), static_cast<Rank>(j)};
            cards.push_back(card);
        }
    }
}

//Oppgave 3c)
void CardDeck::swap(int i, int j) {
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

//Oppgave 3d)
void CardDeck::print() {
    for (Card card : cards) {
        cout << card.toString() << endl;
    }
}

//Oppgave 3e)
void CardDeck::shuffle() {
    random_device rd;
    mt19937 g(rd());
    for (int i = 0; i < cards.size(); i++) {
        uniform_int_distribution<int> d(0, cards.size() - 1);
        swap(i, d(g));
    }
}

//Oppgave 3f)
Card CardDeck::drawCard() {
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

