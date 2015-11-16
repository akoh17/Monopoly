//  PropertyAction.h

#ifndef __Monopoly__PropertyAction__
#define __Monopoly__PropertyAction__

#include <iostream>
#include <string>
#include "Action.h"
#include "Player.h"

class PropertyAction: public Action
{
    
private:
    int costToBuy;
    int costIfIandedOn;
    int costToUpgrade;
    Player *player1;
    Player *player2;
    
public:
    PropertyAction();
    ~PropertyAction();
     void executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction);

};

#endif 
