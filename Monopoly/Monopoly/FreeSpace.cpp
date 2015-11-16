//  FreeSpace.cpp

#include "FreeSpace.h"
#include <string>

FreeSpace::FreeSpace()
{
    
}

FreeSpace::FreeSpace(string s, int i)
{
    spaceType=3;
    name=s;
    index=i;
}

FreeSpace::~FreeSpace()
{
    
}

void FreeSpace::set_name(string s)
{
    name=s;
}

/*
void FreeSpace::set_freeSpaceAction(Action *a)
{
    spaceAction=a;
}
*/

void FreeSpace::set_spaceAction(Action *a)
{
    spaceAction=a;
}

string FreeSpace::get_spaceName()
{
    return name;
}

int FreeSpace::get_spaceIndex()
{
    return index;
}

void FreeSpace::doAction(Player &p1)
{
    Player *p2=new Player;
    spaceAction->executeAction(index, 0, 0, 0, 0, 0, false, "", p1, *p2, false, false, 0);
}

