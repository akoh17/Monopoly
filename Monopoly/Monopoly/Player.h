
//Player.h
#ifndef __Monopoly__Player__
#define __Monopoly__Player__
#include <iostream>
#include <string>

using namespace std;


class Player
{
private:
    int playerNum;
    string playerName;
    int location;
    int money;
    int number_of_spaces_owned;
    int colorarray[10];
    bool inJail;
    
 public:
    Player();
    ~Player();
    
    void set_name(string s);
    void set_number(int i);
    void set_location(int j);
    void set_money(int m);
    void set_number_of_spaces_owned(int n);
    void set_inJail(bool b);
    void set_colorArray(int array[10]);
    
    string get_name();
    int get_number();
    int get_location();
    int get_money();
    int get_number_of_spaces_owned();
    int* get_colorArray();
    bool get_inJail();
    
};

#endif
