
//  Space.h
#ifndef __Monopoly__Space__
#define __Monopoly__Space__

#include <string>
#include "Action.h"
#include "Player.h"
#include "Bank.h"


using namespace std;
class Space
{
protected:
    string name;
    Action * action;
    Player player;

public:
    
    //pass in to identify what space type the spaces are
    int spaceType;
    Space();
    ~Space();
    
    
    //makes Space and abstract class
    virtual void set_name(string s)=0;
    virtual string get_spaceName()=0;
    virtual int get_spaceIndex()=0;
    virtual void set_spaceAction(Action* a)=0;
    virtual void doAction(Player &p)=0;
    
};




#endif
