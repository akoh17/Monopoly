
//  Player.cpp
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    
}


Player::~Player()
{
    
}

//setter and getter methods for the player class
void Player::set_name(string s)
{
    playerName=s;
}

void Player::set_number(int i)
{
    playerNum=i;
}

void Player::set_location(int j)
{
    location=j;
}

void Player::set_money(int m)
{
    money=m;
}

void Player::set_number_of_spaces_owned(int n)
{
    number_of_spaces_owned=n;
}

// this is used to check if the player has all of the properties of a single color and can then upgrade them.
void Player::set_colorArray(int array[10])
{
    for(int ii=0; ii<10; ii++)
    {
        colorarray[ii]=array[ii];
    }
}

void Player::set_inJail(bool b)
{
    inJail=b;
}



string Player::get_name()
{
    return playerName;
}

int Player::get_number()
{
    return playerNum;
}

int Player::get_location()
{
    return location;
}

int Player::get_money()
{
    return money;
}

int Player::get_number_of_spaces_owned()
{
    return number_of_spaces_owned;
}





int* Player::get_colorArray()
{
    return colorarray;
}



bool Player::get_inJail()
{
    return inJail;
}

