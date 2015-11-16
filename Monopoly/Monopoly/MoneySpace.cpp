//  MoneySpace.cpp

#include "MoneySpace.h"
#include  <string>

MoneySpace::MoneySpace()
{
    
}

MoneySpace::MoneySpace(string s, int i, int money)
{
    //need to pass in intialized paramters into execute action even though this money space doens't use them
    spaceType=1;
    name=s;
    index=i;
    amount=money;
    
}

MoneySpace::~MoneySpace()
{
    
}

void MoneySpace::set_name(string s)
{
    
    name=s;
}


void MoneySpace::set_spaceAction(Action *a)
{
    spaceAction=a;
}

string MoneySpace::get_spaceName()
{
    return name;
}

int MoneySpace::get_spaceIndex()
{
    return index;
}


int MoneySpace::get_moneySpace_amount()
{
    return amount;
}

void MoneySpace::doAction(Player &p1)
{
    //create the bank player
    bank=new Player;
    bank->set_money(1000000000);
    
    cout<<"you landed on: " <<name<< " you owe"<<  amount<<endl;
    
    spaceAction->executeAction(index, 0, amount, 0, 0, 0, false, "", p1, *bank, false, false,0);
    
    
}
