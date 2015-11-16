//  GoToAction.h
#ifndef __Monopoly__GoToAction__
#define __Monopoly__GoToAction__

#include <iostream>
#include <string>
#include "Action.h"
#include "Player.h"
#include "Space.h"

class GoToAction: public Action
{
private:
    int move;
    
public:
    GoToAction();
    ~GoToAction();


    void executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction);
    
};

#endif 
