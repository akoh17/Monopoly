//  Card.cpp

#include "Card.h"
using namespace std;

Card::Card()
{
    
}

Card::Card(string t, string s, int i, int move, int money, int transferSpace, int actionType)
{
    type=t;
    name=s;
    index=i;
    numSpaceToMove=move;
    amountOfMoneyToExchange=money;
    indexOfSpaceToMoveTo=transferSpace;
    typeOfAction=actionType;
    
}

Card::~Card()
{
    
}



string Card::get_cardName()
{
    return name;
}

string Card::get_cardType()
{
    return type;
}

int Card::get_cardIndex()
{
    return index;
}

int Card::get_cardNumSpaceToMove()
{
    return numSpaceToMove;
}

int Card::get_cardAmountOfMoneyToExchange()
{
    return amountOfMoneyToExchange;
}

int Card::get_cardIndexOfSpaceToMoveTo()
{
    return indexOfSpaceToMoveTo;
}

int Card::get_cardTypeOfAction()
{
    return typeOfAction;
}
