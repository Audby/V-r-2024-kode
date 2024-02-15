#include "std_lib_facilities.h"
#include "card.h"
#include <random>
#include <vector>


class CardDeck {
    private:
        vector<Card> cards;
    public:
        CardDeck();
        void print();
        void swap(int i, int j);
        void shuffle();
        Card drawCard();
};

