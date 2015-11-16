//  Card.h

#ifndef __Monopoly__Card__
#define __Monopoly__Card__

#include <iostream>
using namespace std;

class Card
{
private:
    string type;
    string name;
    int index;
    int numSpaceToMove;
    int amountOfMoneyToExchange;
    int indexOfSpaceToMoveTo;
    int typeOfAction;
    
public:
    Card();
    Card(string, string, int, int, int, int, int);
    ~Card();
    
    string get_cardName();
    string get_cardType();
    int get_cardIndex();
    int get_cardNumSpaceToMove();
    int get_cardAmountOfMoneyToExchange();
    int get_cardIndexOfSpaceToMoveTo();
    int get_cardTypeOfAction();

};


#endif 