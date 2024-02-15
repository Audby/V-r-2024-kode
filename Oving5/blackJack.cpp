#include "std_lib_facilities.h"
#include "blackJack.h"
#include <random>
#include <vector>


//Oppgave 4b)
bool isAce(Card card) {
    return card.getRank() == rankToString(Rank::ace);
}

//Oppgave 4c)
int Blackjack::getCardValue(Card card) {
    if (isAce(card)) {
        return 11;
    } else if (card.getRank() == rankToString(Rank::jack) || card.getRank() == rankToString(Rank::queen) || card.getRank() == rankToString(Rank::king)) {
        return 10;
    } else if (card.getRank() == rankToString(Rank::two)) {
        return 2;
    } else if (card.getRank() == rankToString(Rank::three)) {
        return 3;
    } else if (card.getRank() == rankToString(Rank::four)) {
        return 4;
    } else if (card.getRank() == rankToString(Rank::five)) {
        return 5;
    } else if (card.getRank() == rankToString(Rank::six)) {
        return 6;
    } else if (card.getRank() == rankToString(Rank::seven)) {
        return 7;
    } else if (card.getRank() == rankToString(Rank::eight)) {
        return 8;
    } else if (card.getRank() == rankToString(Rank::nine)) {
        return 9;
    } else if (card.getRank() == rankToString(Rank::ten)) {
        return 10;
    }
    return 0; 
}

//Oppgave 4d)
int Blackjack::getHandScore(vector<Card> hand) {
    int score = 0;
    for (Card card : hand) {
        score += getCardValue(card);
    }
    return score;
}

//Oppgave 4e)
bool Blackjack::askPlayerDrawCard() {
    string answer;
    cout << "Vil du ha et nytt kort? (yes/no)" << endl;
    cin >> answer;
    if (answer == "yes") {
        return true;
    } else {
        return false;
    }
}

//Oppgave 4f)
void Blackjack::drawPlayerCard() {
    playerHand.push_back(deck.drawCard());
    playerHandSum = getHandScore(playerHand);
    cout << "Du trakk: " << playerHand.back().toString() << endl;
    cout << "Din hånd: " << playerHandSum << endl;
}

void Blackjack::drawDealerCard() {
    dealerHand.push_back(deck.drawCard());
    dealerHandSum = getHandScore(dealerHand);
    cout << "Dealer trakk: " << dealerHand.back().toString() << endl;
    cout << "Dealer hånd: " << dealerHandSum << endl;
}

//Oppgave 4g)
void playGame() {
    Blackjack game;
    game.drawPlayerCard();
    game.drawPlayerCard();
    game.drawDealerCard();
    int playerHandSum = game.getHandScore(game.playerHand);
    game.drawDealerCard();
    while (game.askPlayerDrawCard()) {
        game.drawPlayerCard();
        if (playerHandSum > 21) {
            cout << "Du tapte!" << endl;
            return;
        }
    }
    while (game.dealerHandSum < 17) {
        game.drawDealerCard();
        
    }
    if (game.dealerHandSum > 21) {
        cout << "Du vant!" << endl;
    } else if (game.dealerHandSum > playerHandSum) {
        cout << "Du tapte!" << endl;
    } else if (game.dealerHandSum < playerHandSum) {
        cout << "Du vant!" << endl;
    } else {
        cout << "Uavgjort!" << endl;
    }
}