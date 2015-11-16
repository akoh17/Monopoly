//  FreeSpace.h

#ifndef __Monopoly__FreeSpace__
#define __Monopoly__FreeSpace__

#include <iostream>
#include "Space.h"


class FreeSpace: public Space
{
private:
    string name;
    int index;
    Action *spaceAction;
    Player player;
    
public:
    FreeSpace();
    FreeSpace(string, int);
    ~FreeSpace();
    
    // same as virtual function
    void set_name(string s);
    void set_spaceAction(Action *a);
    string get_spaceName();
    int get_spaceIndex();
     void doAction(Player &p);
};

#endif
