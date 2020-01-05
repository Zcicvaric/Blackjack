#include "Cards.h"


Cards::Cards(int decks)
{
    srand(time(NULL));
    int layout[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 , 13};//2-8 brojke, 10 decko, 11 dama, 12 kralj, 13 as
    int checkbox[12];
    for(int i = 0; i < 12; i++) {
        checkbox[i] = decks;
    }
    int brKarata = decks*12;
    while(brKarata != 0) {
        int br = std::rand() % 12;
        if(checkbox[br] > 0) {
            deck.push_back(layout[br]);
            checkbox[br]--;
            brKarata--;
        }
    }

}

int Cards::deal() {
    int karta = 0;
    if(deck.back() != NULL) {
        karta =  deck.back();
        deck.pop_back();
        return karta;
    }
    else
        return 0;
}
Cards::~Cards()
{

}
