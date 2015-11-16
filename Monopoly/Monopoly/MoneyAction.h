//  MoneyAction.h


#ifndef __Monopoly__MoneyAction__
#define __Monopoly__MoneyAction__

#include <iostream>
#include <string>
#include "Action.h"
#include "Player.h"

class MoneyAction: public Action
{
    
private:
    Player *player1;
    Player *player2;
    
public:
    MoneyAction();
    
    MoneyAction(int,int,int);
    ~MoneyAction();
    
    void player_passes_go(Player &p1);
    void players_exchange_money(Player &p1, Player &p2, int amount);
    void player_loses_money(Player &p, int amount);
    void player_gains_money(Player &p, int amount);
    
    
    void executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction);

};



#endif 
