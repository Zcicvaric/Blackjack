#ifndef PLAYER_H
#define PLAYER_H
#include "Cards.h"


class Player
{

    public:
        Player(int stake);
        ~Player();
        std::vector<int> getHand();
        std::string cardsInHand(int cards);
        int points();
        void hit(Cards& deckofCards);
        int win();
        int getMoney();
        void setMoney(int br);
        void clearHand();

    private:
        int money;
        std::vector<int> hand;
};

#endif // PLAYER_H
