//main.cpp
//PA5
#include <iostream>
#include <cmath>
#include <string>
#include "GameBoard.h"
#include "Space.h"
#include "Player.h"
#include "Action.h"

using namespace std;


Player *playerArray;


/* checks for the number of players that the users want*/
int askForPlayers()
{
    int num;;
    do
    {
       cout<< "Please enter the number of players (2-4): ";
        cin>> num;
        
        
        if( cin.fail() || num<2 || num>4)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<< "Error: you must have 2-4 players play";
            continue;
        }
        break;    
    } while (true);
    
    return num;
}

void createPlayers(int numPlayers)
{
    
    
     // creates the player objects
    playerArray = new Player[numPlayers];
    
    //initialize color array to all 0s because players initially have no properties and so no colors associated with those properties
    int color_array[10];
    for(int ii=0; ii<10; ii++)
    {
        color_array[ii]=0;
    }
    
    
    //sets the name and player number of the first player
    do
    {
        string name;
        cout<< "Please choose a name (Character from A to J): ";
        cin>> name;
        if(!(name =="A" || name== "B" || name =="C" || name== "D" || name =="E" || name== "F" || name =="G" || name== "H" || name =="I" || name== "J"))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<< "Error"<<endl;
            continue;
        }
        
        playerArray[0].set_name(name);
        playerArray[0].set_number(0);
        playerArray[0].set_location(0);
        //players start off with 2000 dollars
        playerArray[0].set_money(2000);
        playerArray[0].set_colorArray(color_array);
        playerArray[0].set_inJail(false);
        break;
    }while(true);
    
        

    //sets the name and player number of the other players
    for(int ii=1; ii<numPlayers; ii++)
    {
        do
        {
            string name;
            cout<< "Please choose a name (Character from A to J): ";
            cin>> name;
            if(!(name =="A" || name== "B" || name =="C" || name== "D" || name =="E" || name== "F" || name =="G" || name== "H" || name =="I" || name== "J"))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout<< "Error "<<endl;
                continue;
            }
            
            //check if 2nd player name doesn't match the first person's name
            if(ii==1)
            {
                if(name== playerArray[0].get_name())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<< "Name already taken, please try again "<<endl;
                    continue;
                }
            }
            
            //if there are 3 players, occurs after 2nd player is built, check if 3rd player name doesn't match the other 2 players
            if(ii==2)
            {
                if(name== playerArray[0].get_name() || name== playerArray[1].get_name())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<< "Name already taken, please try again "<<endl;
                    continue;
                }
            }
            
            
            //if there are 4 players, occurs after 3rd player is built, check if 4rd player name doesn't match the other 3 players
            if(ii==3)
            {
                if(name== playerArray[0].get_name() || name== playerArray[1].get_name() || name== playerArray[2].get_name() )
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<< "Name already taken, please try again "<<endl;
                    continue;
                }
            }
            
            playerArray[ii].set_name(name);
            playerArray[ii].set_number(ii);
            playerArray[ii].set_location(0);
            playerArray[ii].set_money(2000);
            //playerArray[ii].set_number_of_spaces_owned(0);
            playerArray[ii].set_colorArray(color_array);
            playerArray[ii].set_inJail(false);
            
            break;
        }while(true);
    }
    
    
}

int main(int argc, const char * argv[])
{
    int numPlayers;
    
    numPlayers= askForPlayers();
    createPlayers(numPlayers);
    
    GameBoard *gameboard= new GameBoard;
    gameboard->set_numOfPlayers(numPlayers);
    gameboard->set_playerArray(playerArray);
    
    gameboard->runGame();
    
   
    
    cout<<"Done with the Game"<<endl;

}

