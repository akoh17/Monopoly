//  PropertyAction.cpp

#include "PropertyAction.h"

PropertyAction::PropertyAction()
{
    
}

PropertyAction::~PropertyAction()
{
    
}

void PropertyAction::executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction)
{
        player1=&p1;
        player2=&p2;
     int currentMoney1=player1->get_money();
    int currentMoney2=player2->get_money();
    
    
        if(owned)
        {
            player1->set_money(currentMoney1-landCost);
            player2->set_money(currentMoney2+landCost);
        }
        // isOwned is false and player wants to buy the property
        if(isBuying)
        {
            int currentMoney=player1->get_money();
            player1->set_money(currentMoney-buyCost);
            
        }
    
    if(isUpgrading)
    {
        int currentMoney=player1->get_money();
        player1->set_money(currentMoney-upgradeCost);
    }

}
