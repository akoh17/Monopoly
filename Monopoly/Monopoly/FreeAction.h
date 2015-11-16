//  FreeAction.h

#ifndef __Monopoly__FreeAction__
#define __Monopoly__FreeAction__

#include <iostream>
#include <string>
#include "Action.h"

//nothing happens so just set a free sapce to this action
class FreeAction: public Action
{
public:
    FreeAction();
    FreeAction(int);
    ~FreeAction();
  
    void executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction);
};

#endif 
