#include "Player.h"

Player::Player(int stake)
{
    money = stake;
}
std::vector<int> Player::getHand() {
    return hand;
}
std::string Player::cardsInHand(int cards) {
    std::string popis = "";
    for(int i = 0; i < cards; i++) {
        if(hand[i] >= 2 && hand[i] <= 9)
            popis += std::to_string(hand[i]);
        else if(hand[i] == 10)
            popis += "Decko";
        else if(hand[i] == 11)
            popis += "Dama";
        else if(hand[i] == 12)
            popis += "Kralj";
        else if(hand[i] == 13)
            popis +="As";
        popis += " ";
    }
    return popis;
}

int Player::points () {
    int bodovi = 0;
    bool as = false;
    for(int i = 0 ; i < hand.size(); i++) {
        if(hand[i] >= 2 && hand[i] <= 9)
            bodovi += hand[i];
        if(hand[i] >= 10 && hand[i] != 13)
            bodovi +=10;
        if(hand[i] == 13) {
            if(bodovi <= 10 & as == false) {
                bodovi +=11;
                as = true;
            }
            if(bodovi >= 11 || as == true)
                bodovi +=1;
        }
    }
    return bodovi;
}


void Player::hit(Cards& deckofCards) {
    hand.push_back(deckofCards.deal());
}

int Player::win() {
    if(points() == 21)
        return 1;
    if(points() > 21)
        return 2;
    else
        return 0;
}

int Player::getMoney(){
    return money;
}

void Player::setMoney(int br) {
    money += br;
}

void Player::clearHand() {
    hand.erase(hand.begin(), hand.end());
}

Player::~Player()
{

}
