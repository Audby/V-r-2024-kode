#include "std_lib_facilities.h"

enum class Suit{clubs, diamonds, hearts, spades};

enum class Rank{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string suitToString(Suit suit);

string rankToString(Rank rank);

class Card {
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    string toString();
};