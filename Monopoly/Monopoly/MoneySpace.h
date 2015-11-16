//  MoneySpace.h

#ifndef __Monopoly__MoneySpace__
#define __Monopoly__MoneySpace__

#include <iostream>
#include <string>
#include "Space.h"

class MoneySpace: public Space
{
private:
    
    string name;
    int index;
    int amount;
    Action *spaceAction;
    Player *bank;
    
    int costToBuy;
    int costIfLandedOn;
    bool isOwned;
    bool isBuying;
    int costToUpgrade;
    string color;

public:
    
    
    MoneySpace();
    MoneySpace(string, int, int);
    ~MoneySpace();
    
    // same as virtual function
    void set_name(string s);
    string get_spaceName();
    int get_spaceIndex();
    void set_spaceAction(Action *a);
     void doAction(Player &p1);
    int get_moneySpace_amount();
};

#endif
