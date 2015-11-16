//  MoveAction.h
#ifndef __Monopoly__MoveAction__
#define __Monopoly__MoveAction__

#include <iostream>
#include <string>
#include "Action.h"
#include "Player.h"

class MoveAction: public Action
{
private:
    int numOfSpacesToMove;
    
public:
    MoveAction();
    ~MoveAction();
    
    void set_NumOfSpacesToMove(int i);
    int get_NumOfSpacesToMove();
    void move_player(Player &p1);
    

    void executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction);
};

#endif 
