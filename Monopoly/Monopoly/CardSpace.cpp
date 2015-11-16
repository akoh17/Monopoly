//
//  CardSpace.cpp
//  Monopoly
//
//  Created by Alex Koh on 4/10/14.
//  Copyright (c) 2014 Alex Koh. All rights reserved.
//

#include "CardSpace.h"
#include <string>

CardSpace::CardSpace()
{
    
}

CardSpace::CardSpace(string s, int i, deque<Card>cards)
{
    spaceType=2;
    name=s;
    index=i;
    cardDeque=cards;
    
    //arrayOfCards=cards;
}

CardSpace::~CardSpace()
{
    
}

void CardSpace::set_name(string s)
{
    name=s;
}

void CardSpace::set_spaceAction(Action *a)
{
    spaceAction=a;
}

string CardSpace::get_spaceName()
{
    return name;
}

int CardSpace::get_spaceIndex()
{
    return index;
}


void CardSpace::set_cardTypeOfAction(int t)
{
    typeOfAction=t;
}

void CardSpace::set_cardMove(int m)
{
    move=m;
}

void CardSpace::set_cardMoney(int mon)
{
    exchange=mon;
}

void CardSpace::set_cardGoTo(int g)
{
    goTo=g;
}

int CardSpace::get_cardMove()
{
    return move;
}

int CardSpace::get_cardMoney()
{
    return exchange;
}

int CardSpace::get_cardGoTo()
{
    return goTo;
}

int CardSpace::get_cardTypeOfAction()
{
    return typeOfAction;
}

void CardSpace::doAction(Player &p1)
{
    move=-1;
    exchange=-1;
    goTo=-1;
    // 1=move, 2=collect, 3=goTo
    cout<<"You landed on a "<< cardDeque[0].get_cardType() << " space" <<endl;
    cout<<cardDeque[0].get_cardName()<<endl;
    
    typeOfAction=cardDeque[0].get_cardTypeOfAction();
    
    if(typeOfAction==1)
    {
        //move=cardDeque[0].get_cardMoveSpaces();
        move=cardDeque[0].get_cardNumSpaceToMove();
       
      
    }
    
    if(typeOfAction==2)
    {
        exchange=cardDeque[0].get_cardAmountOfMoneyToExchange();
        
    }
    
    if (typeOfAction==3)
    {
        goTo=cardDeque[0].get_cardIndexOfSpaceToMoveTo();
        
    }
    this->set_cardTypeOfAction(typeOfAction);
    this->set_cardMove(move);
    this->set_cardMoney(exchange);
    this->set_cardGoTo(goTo);
    
    //reorganizing the cards
    Card firstCard=cardDeque[0];
    cardDeque.pop_front();
    cardDeque.push_back(firstCard);
    
}



