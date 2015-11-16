//  GoToAction.cpp

#include "GoToAction.h"
#include <string>
#include "Player.h"

GoToAction::GoToAction()
{

}

GoToAction::~GoToAction()
{
    
}

void GoToAction::executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction)
{
    p1.set_location(indexOfSpaceToMoveTo);
}