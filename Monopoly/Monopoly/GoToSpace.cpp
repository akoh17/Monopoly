//
//  GoToSpace.cpp
//  Monopoly
//
//  Created by Alex Koh on 4/10/14.
//  Copyright (c) 2014 Alex Koh. All rights reserved.
//

#include "GoToSpace.h"
#include <string>

GoToSpace::GoToSpace()
{
    
}

GoToSpace::GoToSpace(string s, int i, int target)
{
    spaceType=4;
    name=s;
    index=i;
    targetSpaceIndex=target;
}

GoToSpace::~GoToSpace()
{
    
}

void GoToSpace::set_name(string s)
{
    name=s;
}


void GoToSpace::set_spaceAction(Action *a)
{
    spaceAction=a;
}

string GoToSpace::get_spaceName()
{
    return  name;
}

int GoToSpace::get_spaceIndex()
{
    return index;
}

void GoToSpace::doAction(Player &p1)
{
    //just to pass in as a parameter
    Player* p2=new Player;
    p1.set_inJail(true);
    spaceAction->executeAction(index, 0, 0, 0, 0, 10, false, "", p1, *p2 , false, false, 0);
}
