//  Action.h
#ifndef __Monopoly__Action__
#define __Monopoly__Action__

#include <iostream>
#include <string>
#include "Player.h"
using namespace std;



class Action
{
private:
    int money;
   
    
public:
    
    Action();
    ~Action();

  
  virtual void executeAction(int index, int buyCost, int landCost, int upgradeCost, int numSpacesToMove, int indexOfSpaceToMoveTo, bool owned, string color, Player &p1, Player &p2, bool isBuying, bool isUpgrading, int typeOfAction)=0;
    
};



#endif 
