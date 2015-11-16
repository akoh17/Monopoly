//  CardAction.h

#ifndef __Monopoly__CardAction__
#define __Monopoly__CardAction__

#include <iostream>
#include <string>
#include "Action.h"
#include "Card.h"


class CardAction: public Action
{
    
    
public:
    CardAction();
    ~CardAction();

    void executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction);
    
    
    
   
};

#endif 
