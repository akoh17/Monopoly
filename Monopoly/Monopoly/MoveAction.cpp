//  MoveAction.cpp

#include "MoveAction.h"
#include <string>
#include "Player.h"

MoveAction::MoveAction()
{
    
}

MoveAction::~MoveAction()
{
    
}

void MoveAction::set_NumOfSpacesToMove(int i)
{
    numOfSpacesToMove=i;
}

int MoveAction::get_NumOfSpacesToMove()
{
    return numOfSpacesToMove;
}

void MoveAction::move_player(Player &p1)
{
    
}


void MoveAction::executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction)
{
    
}