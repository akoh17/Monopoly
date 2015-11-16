//  GameBoard.h

#ifndef __Monopoly__GameBoard__
#define __Monopoly__GameBoard__

#include <iostream>
#include "Space.h"
#include "Player.h"
#include "Card.h"
#include "PropertySpace.h"
#include "MoneySpace.h"
#include "CardSpace.h"
#include "FreeSpace.h"
#include "GoToSpace.h"


#include "Card.h"
#include "Action.h"
#include "FreeSpace.h"
#include "MoneyAction.h"
#include "MoveAction.h"
#include "GoToAction.h"
#include "CardAction.h"
#include "FreeAction.h"
#include "PropertyAction.h"
#include <deque>
using namespace std;

class GameBoard
{
private:
    
    Space *spaceArray[40];
    Card chanceCardArray[15];
    Card communityChestCardArray[15];
    
    deque<Card> chanceDeque;
    deque<Card> communityDeque;
    
    
    
    // need to know how many players there are
    int numPlayers;
    Player* playerArray;
    MoneyAction moneyAct;
    MoveAction moveAct;
    GoToAction goToAct;
    
    Player bankPlayer;

public:
    GameBoard();
    ~GameBoard();
    void set_numOfPlayers(int num);
    void set_playerArray(Player * playerArray);
    
    void runGame();
    
    
   void populateBoardAndCards();
      void printBoard();
    void printCompleteRow(int start, int topOrBottom);
    void printIncompleteRow(int leftSpace, int rightSpace);

};


#endif 
