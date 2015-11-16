//
//  MoneyAction.cpp
//  Monopoly
//
//  Created by Alex Koh on 4/9/14.
//  Copyright (c) 2014 Alex Koh. All rights reserved.
//

#include "MoneyAction.h"
#include <string>
#include "Player.h"

MoneyAction::MoneyAction()
{
   // cout<<"In MONEY ACTION";
}

MoneyAction::MoneyAction(int landedOnCost, int buyCost, int upgradeCost)
{
   // costIfIandedOn=landedOnCost;
    //costToBuy=buyCost;
    //costToUpgrade=upgradeCost;
}

MoneyAction::~MoneyAction()
{
    
}

void MoneyAction::player_passes_go(Player &p1)
{
    
}

void MoneyAction::players_exchange_money(Player &p1, Player &p2, int amount)
{
    
}

void MoneyAction::player_gains_money(Player &p1, int amount)
{
    
}

void MoneyAction::player_loses_money(Player &p2, int amount)
{
    
}

void MoneyAction::executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction)
{
    player1=&p1;
    int currentMoney=player1->get_money();
    player1->set_money(currentMoney+landCost);
    
}




