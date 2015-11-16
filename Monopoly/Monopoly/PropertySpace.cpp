//  PropertySpace.cpp

#include "PropertySpace.h"

PropertySpace::PropertySpace()
{
    
}

PropertySpace::PropertySpace(string s, int i, int buyCost, int landCost, bool owned, int upgradeCost, string c, bool upgrade, bool alreadyUp)
{
 
    spaceType=0;
    name=s;
    index=i;
    costToBuy=buyCost;
    costIfLandedOn=landCost;
    isOwned=owned;
    costToUpgrade=upgradeCost;
    color=c;
    isUpgrading=upgrade;
    alreadyUpgraded=alreadyUp;
    
}

PropertySpace::~PropertySpace()
{
    
}

//this is a virtual function so all spaces have set_spaceAction(Action *a). You don't have to say set_property_Action(Action *a) because then you would have to cast all of the spaces for each type of space.  By declaring set_spaceAction(Action *a) as a virtual function, all the subspaces have this function and so you can just call set_spaceActon(Action *a) on all of them.

void PropertySpace::set_spaceAction(Action *a)
{
    spaceAction=a;
}

void PropertySpace::set_name(string s)
{
    name=s;
}


void PropertySpace::set_propertySpace_costToBuy(int buyCost)
{
    costToBuy=buyCost;
}

void PropertySpace::set_propertySpace_costIfLandedOn(int landCost)
{
    costIfLandedOn=landCost;
}

void PropertySpace::set_propertySpace_isOwned(bool owned)
{
    isOwned=owned;
}

void PropertySpace::set_propertySpace_costToUpgrade(int upgradeCost)
{
    costToUpgrade=upgradeCost;
}

void PropertySpace::set_propertySpace_isUpgrading(bool upgrade)
{
    isUpgrading=upgrade;
}

void PropertySpace::set_propertySpace_isAlreadyUpgraded(bool alreadyUp)
{
    alreadyUpgraded=alreadyUp;
}


string PropertySpace::get_spaceName()
{
    return name;
}

int PropertySpace::get_spaceIndex()
{
    return index;
}

int PropertySpace::get_propertySpace_costToBuy()
{
    return costToBuy;
}

int PropertySpace::get_propertySpace_costIfLandedOn()
{
    return costIfLandedOn;
}

bool PropertySpace::get_propertySpace_isOwned()
{
    return isOwned;
}

int PropertySpace::get_propertySpace_costToUpgrade()
{
    return costToUpgrade;
}

string PropertySpace::get_propertySpace_color()
{
    return color;
}

Player* PropertySpace::get_propertySpace_owner()
{
    return ownerOfSpacePlayer;
}

void PropertySpace::doAction(Player &p1)
{
    string answer;
    bank=new Player;
    bank->set_money(1000000000);
    bool isBuying;
    bool isUpgrading;
    isUpgrading=false;
    
    if(isOwned)
    {
        isBuying=false;
        cout<<ownerOfSpacePlayer->get_name()<<" owns the space"<<endl;
        cout<<"you owe them $"<< costIfLandedOn <<endl;
        
        //execute this action only if the property is owned.
        spaceAction->executeAction(index, costToBuy, costIfLandedOn, costToUpgrade, 0, 0, isOwned, color, p1, *ownerOfSpacePlayer, isBuying, isUpgrading, 0);
      
    }
    
    //isOwned is false
    else
    {
        isBuying=true;
        //second player becomes the bank
        cout<<p1.get_name()<< " would you like to buy " <<this->get_spaceName()<<"? (enter yes if you want to buy it): ";
        cin>>answer;
        if(answer=="yes")
        {
            if(p1.get_money()>= costToBuy)
            {
                
                isBuying=true;
                
                //isOwned is false so execute the action to buy the property
                spaceAction->executeAction(index, costToBuy, costIfLandedOn, costToUpgrade, 0, 0, isOwned, color, p1, *bank, isBuying,isUpgrading,0);
                isOwned=true;
                ownerOfSpacePlayer=&p1;
                
                cout<< endl<<p1.get_name()<< " now owns "<<this->get_spaceName()<<endl;
                
                int *array;
                array=p1.get_colorArray();
            
                if(this->get_propertySpace_color()== "Brown")
                {
                    array[0]++;
                }
                
                if(this->get_propertySpace_color()== "LtBlue")
                {
                    array[1]++;
                }
                
                if(this->get_propertySpace_color()== "DarkRed")
                {
                    array[2]++;
                }
                
                if(this->get_propertySpace_color()== "Orange")
                {
                    array[3]++;
                }
                
                if(this->get_propertySpace_color()== "Red")
                {
                    array[4]++;
                }
                
                if(this->get_propertySpace_color()== "Yellow")
                {
                    array[5]++;
                }
                
                if(this->get_propertySpace_color()== "Green")
                {
                    array[6]++;
                }
                
                if(this->get_propertySpace_color()== "DarkBlue")
                {
                    array[7]++;
                }
                
                //railroads
                if(this->get_propertySpace_color()== "Black")
                {
                    array[8]++;
                }
                
                //utilities
                if(this->get_propertySpace_color()== "White")
                {
                    array[9]++;
                }
                
            }
            
            else
            {
                cout<<"You don't have enough money to buy this space";
            }
            
        }
    }
    
    //increases rent by 5 times
    if(isUpgrading)
    {
        cout<<"You have chosen to upgrade "<<name<<endl;
        spaceAction->executeAction(index, costToBuy, costIfLandedOn, costToUpgrade, 0, 0, isOwned, color, p1, *bank, isBuying,isUpgrading,0);
        costIfLandedOn= 5*costIfLandedOn;
    }
    
}
