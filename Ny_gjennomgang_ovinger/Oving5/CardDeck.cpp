#include "std_lib_facilities.h"
#include "CardDeck.h"
#include <vector>
#include <random>

CardDeck::CardDeck() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card(static_cast<Suit>(i), static_cast<Rank>(j));
            cards.push_back(card);
        }
    }
}

void CardDeck::swap(int i, int j) {
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

void CardDeck::print() {
    for (int i = 0; i<cards.size(); i++) {
        cout << cards[i].toString() << endl; 
    }
}

void CardDeck::shuffle() {
    random_device rd;
    default_random_engine generator(rd());
    for (int i = 0; i < cards.size(); i++) {
        uniform_int_distribution<int> d(0, cards.size()-1);
        swap(i, d(generator));
    }
}

Card CardDeck::drawCard() {
    Card topCard = cards[cards.size()-1];
    cards.pop_back();
    return topCard;
}

