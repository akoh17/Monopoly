//
//  Bank.h


#ifndef __Monopoly__Bank__
#define __Monopoly__Bank__

#include <iostream>
#include <string>
#include "Player.h"

class Bank: public Player
{
private:
    int amount;
    
public:
    Bank();
    ~Bank();
    
    void set_bankMoneyAmount(int money);
    int get_bankMoneyAmount();
};

#endif /* defined(__Monopoly__Bank__) */
