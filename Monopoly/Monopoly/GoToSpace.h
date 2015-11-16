//  GoToSpace.h

#ifndef __Monopoly__GoToSpace__
#define __Monopoly__GoToSpace__

#include <iostream>
#include <string>
#include "Space.h"

class GoToSpace: public Space
{
private:
    string name;
    int index;
    int targetSpaceIndex;
    Action *spaceAction;
    
public:
    GoToSpace();
    GoToSpace(string, int, int);
    ~GoToSpace();
    
    // same as virtual function
    void set_name(string s);
    void set_spaceAction(Action *a);
    string get_spaceName();
    int get_spaceIndex();
     void doAction(Player &p);
    
};
#endif
