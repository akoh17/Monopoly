//  PropertySpace.h

#ifndef __Monopoly__PropertySpace__
#define __Monopoly__PropertySpace__

#include <iostream>
#include <string>
#include "Space.h"
//#include "Action.h"

class PropertySpace: public Space
{
private:
    string name;
    int index;
    int costToBuy;
    int costIfLandedOn;
    bool isOwned;
    int costToUpgrade;
    string color;
    
    Action * spaceAction;
    Player *ownerOfSpacePlayer;
    //create a bank player
    Player *bank;
    
    bool isUpgrading;
    bool alreadyUpgraded;
    
public:
    PropertySpace();
    PropertySpace(string, int, int, int, bool, int, string, bool, bool);
    ~PropertySpace();
    
    // same as virtual function
    void set_name(string s);
    string get_spaceName();
    int get_spaceIndex();
    void set_spaceAction(Action *a);
    void doAction(Player &p);
    
    
    
    void set_propertySpace_costToBuy(int buyCost);
    void set_propertySpace_costIfLandedOn(int landCost);
    void set_propertySpace_isOwned(bool owned);
    void set_propertySpace_costToUpgrade(int upgradeCost);
    void set_propertySpace_owner(Player &p);
    void set_propertySpace_isUpgrading(bool upgrade);
    void set_propertySpace_isAlreadyUpgraded(bool alreadyUp);

    int get_propertySpace_costToBuy();
    int get_propertySpace_costIfLandedOn();
    bool get_propertySpace_isOwned();
    int get_propertySpace_costToUpgrade();
    string get_propertySpace_color();
    Player *get_propertySpace_owner();
    bool get_propertySpace_isUpgrading();
    bool get_propertySpace_isAlreadyUpgraded;
    
    
};


#endif
