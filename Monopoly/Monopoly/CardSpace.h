//  CardSpace.h
#ifndef __Monopoly__CardSpace__
#define __Monopoly__CardSpace__

#include <iostream>
#include <string>
#include "Card.h"
#include "Space.h"
#include <deque>

class CardSpace: public Space
{
private:
    string name;
    int index;
    Action *spaceAction;
    //Card *arrayOfCards;
    //Player player;
    
    deque<Card> cardDeque;
    
    int typeOfAction;

    int move;
    int exchange;
    int goTo;
    
    
public:
    
    
    CardSpace();
    CardSpace(string, int, deque<Card> );
    ~CardSpace();
    
    // same as virtual function
    void set_name(string s);
    string get_spaceName();
    int get_spaceIndex();
    void set_spaceAction(Action *a);
    void doAction(Player &p1);
    
    void set_cardTypeOfAction(int t);
    int get_cardTypeOfAction();
    
    void set_cardMove(int m);
    int get_cardMove();
    
    void set_cardMoney(int mon);
    int get_cardMoney();
    
    void set_cardGoTo(int g);
    int get_cardGoTo();
};

#endif /* defined(__Monopoly__CardSpace__) */
