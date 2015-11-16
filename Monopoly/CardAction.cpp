//  CardAction.cpp


#include "CardAction.h"

CardAction::CardAction()
{
    
}

CardAction::~CardAction()
{
    
}

//don't need a card Action because the card leads to a different type of action.  So when a card is drawn, the gameboard object itself sees what card is drawn for that card space and then determines what other action to do.
void CardAction::executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction)
{
        
}
