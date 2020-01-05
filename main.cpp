#include <iostream>
#include <Cards.h>
#include <Player.h>


using namespace std;

int main()
{
    int br, money, bet;
        cout<<"Sa koliko spilova zelite igrati?"<<endl;
        cin>>br;
        cout<<"Koliko ste spremni izgubiti?"<<endl;
        cin>>money;

        Cards game1(br);
        Player dealer(999999);
        Player player(money);

    while(1) {
        if(player.getMoney() == 0) {
            cout<<"Vise srece drugi put!"<<endl;
            break;
        }

        cout<<"Igra pocinje!"<<endl;

        bool razlika = true;

        player.clearHand();
        dealer.clearHand();
        while(1) {
            cout<<"Postavite ulog: ("<<"preostalo novca: "<<player.getMoney()<<")"<<endl;
            cin>>bet;
            if(bet <= player.getMoney()) {
                player.setMoney(-bet);
                break;
            }
            else {
                cout<<"Nemate toliko novca"<<endl;
            }
        }

        player.hit(game1);
        dealer.hit(game1);
        player.hit(game1);
        dealer.hit(game1);

        while(1) {
            cout<<"Karte u ruci: "<<player.cardsInHand(2)<<", broj bodova "<<player.points()<<endl;
            cout<<"Djelitelj je izvukao: "<<dealer.cardsInHand(1)<<endl;
            if(player.win() == 1) {
                cout<<"Blackjack!"<<endl;
                player.setMoney(bet*2);
                break;
            }
            else if (dealer.win() == 2) {
                cout<<"Izgubili ste!"<<endl;
                cout<<"Djeljitelj je imao u ruci: "<<dealer.cardsInHand(2)<<endl;
                dealer.setMoney(bet*2);
                break;
            }

            int odluka;
            cout<<"1 za hit, 2 za stand"<<endl;
            cin>>odluka;

            if(odluka == 1) {
                player.hit(game1);
                cout<<"Karte u ruci: "<<player.cardsInHand(3)<<", broj bodova "<<player.points()<<endl;
                if(player.win() == 1) {
                    cout<<"Blackjack!"<<endl;
                    player.setMoney(bet*2);
                    break;
                }
                if(player.win() == 2) {
                    cout<<"Bust!"<<endl;
                    dealer.setMoney(bet*2);
                    break;
                }
                odluka = 2;
            }
            if (odluka = 2) {
                cout<<"Djelitelj okrece drugu kartu..."<<endl;
                cout<<"Djeljitelj ima: "<<dealer.cardsInHand(2)<<", broj bodova "<<dealer.points()<<endl;
                if(dealer.win() == 1) {
                    cout<<"Djeljitelj ima Blackjack!"<<endl;
                    dealer.setMoney(bet*2);
                    break;
                }
                if (dealer.win() == 2) {
                    cout<<"Djeljitelj Bust! Igrac pobjeduje!"<<endl;
                    player.setMoney(bet*2);
                    break;
                }
                while(dealer.points() < 17) {
                    cout<<"Djeljitelj izvlaci kartu..."<<endl;
                    dealer.hit(game1);
                    cout<<"Djeljitelj ima: "<<dealer.cardsInHand(dealer.getHand().size())<<", broj bodova "<<dealer.points()<<endl;
                    if(dealer.win() == 1) {
                        cout<<"Djeljitelj ima Blackjack!"<<endl;
                        dealer.setMoney(bet*2);
                        razlika = false;
                        break;
                    }
                    if (dealer.win() == 2) {
                        cout<<"Djeljitelj bust! Igrac pobjeduje!"<<endl;
                        player.setMoney(bet*2);
                        razlika = false;
                        break;
                    }
                }
                if(dealer.points() >= 17 && razlika == true) {
                    if(21 - player.points() < 21 - dealer.points()) {
                        cout<<"Pobjeda!"<<endl;
                        player.setMoney(bet*2);
                        break;
                    }
                    else {
                        cout<<"Izgubili ste!"<<endl;
                        dealer.setMoney(bet*2);
                        break;
                    }
                }

            }
            cout<<endl;
            break;
        }
    }
    return 0;
}
