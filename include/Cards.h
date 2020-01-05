#ifndef CARDS_H
#define CARDS_H
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>



class Cards
{
    public:
        Cards(int decks);
        ~Cards();
        int deal();
        int getDeck();


    private:
        std::vector<int> deck;

};

#endif // CARDS_H
