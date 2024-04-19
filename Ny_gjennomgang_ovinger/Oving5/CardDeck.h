#include "std_lib_facilities.h"
#include "Card.h"
#include <vector>

class CardDeck {
private:
    vector<Card> cards;
public:
    CardDeck();
    void swap(int i, int j);
    void print();
    void shuffle();
    Card drawCard();
};