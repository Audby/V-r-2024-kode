#include "std_lib_facilities.h"
#include "CardDeck.h"
#include <vector>

class Blackjack {
    private:
        CardDeck deck;
        
    public:
        
        int getCardValue(Card card);
        int getHandScore(vector<Card> hand);
        bool askPlayerDrawCard();
        void drawPlayerCard();
        void drawDealerCard();
        vector<Card> playerHand;
        vector<Card> dealerHand;
        void playGame();
        int playerHandSum;
        int dealerHandSum;
        
};

bool isAce(Card card);