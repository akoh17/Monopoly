//  GameBoard.cpp

#include "GameBoard.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std;


GameBoard::GameBoard()
{
    
}

GameBoard::~GameBoard()
{
    
}

void GameBoard::set_numOfPlayers(int num)
{
    numPlayers=num;
}

void GameBoard::set_playerArray(Player *players)
{
    playerArray=players;
}

void GameBoard::populateBoardAndCards()
{
    
    chanceCardArray[0]=Card("CHANCE", "Move 3 spaces forward", 0, 3, -1, -1, 1);
    chanceCardArray[1]=Card("CHANCE", "Collect $50 from the bank", 1, -1, 50, -1, 2);
    chanceCardArray[2]=Card("CHANCE", "Go to to Boardwalk",2,-1,-1,39, 3);
    
    chanceCardArray[3]=Card("CHANCE", "Move 5 spaces forward", 3,5,-1,-1, 1);
    chanceCardArray[4]=Card("CHANCE", "Collect $100 from the bank", 4, -1, 100, -1, 2);
    chanceCardArray[5]=Card("CHANCE", "Go to Indiana",5,-1,-1,23, 3);
    
    chanceCardArray[6]=Card("CHANCE", "Move 7 spaces forward", 6,7,-1,-1, 1);
    chanceCardArray[7]=Card("CHANCE", "Collect $150 from the bank", 7, -1, 150, -1, 2);
    chanceCardArray[8]=Card("CHANCE", "Go to ShortRR",8,-1,-1,35, 3);
    
    chanceCardArray[9]=Card("CHANCE", "Move 9 spaces forward", 9,9,-1,-1, 1);
    chanceCardArray[10]=Card("CHANCE", "Collect $200 from the bank", 10, -1, 200, -1, 2);
    chanceCardArray[11]=Card("CHANCE", "Go to Go",11,-1,-1,0, 3);
    
    chanceCardArray[12]=Card("CHANCE", "Move 11 spaces forward", 12,11,-1,-1, 1);
    chanceCardArray[13]=Card("CHANCE", "Collect $400 from the bank", 13, -1, 400, -1, 2);
    chanceCardArray[14]=Card("CHANCE", "Go to Jail",14,-1,-1,10, 3);
    
    
    communityChestCardArray[0]=Card("COMMUNITY CHEST", "Move 4 spaces forward", 0, 4, -1, -1, 1);
    communityChestCardArray[1]=Card("COMMUNITY CHEST", "Collect $25 from the bank", 1, -1, 25, -1, 2);
    communityChestCardArray[2]=Card("COMMUNITY CHEST", "Go to to ReadingRR",2,-1,-1,5, 3);
    
    communityChestCardArray[3]=Card("COMMUNITY CHEST", "Move 6 spaces forward", 3,6,-1,-1, 1);
    communityChestCardArray[4]=Card("COMMUNITY CHEST", "Collect $75 from the bank", 4, -1, 75, -1, 2);
    communityChestCardArray[5]=Card("COMMUNITY CHEST", "Go to St. Charles",5,-1,-1,11, 3);
    
    communityChestCardArray[6]=Card("COMMUNITY CHEST", "Move 8 spaces forward", 6,8,-1,-1, 1);
    communityChestCardArray[7]=Card("COMMUNITY CHEST", "Collect $125 from the bank", 7, -1, 125, -1, 2);
    communityChestCardArray[8]=Card("COMMUNITY CHEST", "Go to Jail",8,-1,-1,10, 3);
    
    communityChestCardArray[9]=Card("COMMUNITY CHEST", "Move 10 spaces forward", 9,10,-1,-1, 1);
    communityChestCardArray[10]=Card("COMMUNITY CHEST", "Collect $175 from the bank", 10, -1, 175, -1, 2);
    communityChestCardArray[11]=Card("COMMUNITY CHEST", "Go to Go",11,-1,-1,0, 3);
    
    communityChestCardArray[12]=Card("COMMUNITY CHEST", "Move 12 spaces forward", 12,12,-1,-1, 1);
    communityChestCardArray[13]=Card("COMMUNITY CHEST", "Collect $325 from the bank", 13, -1, 325, -1, 2);
    communityChestCardArray[14]=Card("COMMUNITY CHEST", "Go to Vermont",14,-1,-1,8, 3);
    

    for(int ii=0; ii<15; ii++)
    {
        chanceDeque.push_back(chanceCardArray[ii]);
        communityDeque.push_back(communityChestCardArray[ii]);
    }
   
    /* DOESN'T WORK because it doesn't know that spaceArray[0] is actually a moneySpace even though you assigned it to be, so doesn't have the moneyspace methods
    spaceArray[0]= new MoneySpace("GO", 0, 200);
    spaceArray[0]->set_moneySpaceAction(new MoneyAction(100));
     
     //need to recast to tell that it is a moneyspace,  money space has a spacetype=1 so check the space type and then decide the appropriate cast
     ((MoneySpace*)spaceArray[0])->get_moneySpace_amount();
     
     // now its a property space
     if(spaceArray[0]->spaceType==0)
     {
     
     }
     */

//this works because set_spaceAction is a virtual funciton and can be accessed by all of the subclasses.  When I tried to make each setter uniqe like set_moneySpaceAction, this didn't work beacause that method was not in the space class and the compiler didn't know that spaceArray[0] was actually a money space.  So, if i made unique functions, I would have to cast them to the appropriate subclass type like ((MoneySpace*(spaceArray[0]) to access the methods that are only in the moneyspace subclass.

    
    //go is a free space because don't need to land on it to get $200
    spaceArray[0]= new FreeSpace("GO", 0);
    spaceArray[0]->set_spaceAction(new FreeAction(0));
    
    spaceArray[1]=new PropertySpace("Mediter", 1, 60, 2, false, 100, "Brown", false ,false);
    spaceArray[1]->set_spaceAction(new PropertyAction());

    spaceArray[2]=new CardSpace("Community", 2, communityDeque);
    spaceArray[2]->set_spaceAction(new CardAction());
    
    spaceArray[3]=new PropertySpace("Baltic", 3, 60, 4, false, 150, "Brown", false ,false);
    spaceArray[3]->set_spaceAction(new PropertyAction());
    
    spaceArray[4]=new MoneySpace("Income",4, -200);
    spaceArray[4]->set_spaceAction(new MoneyAction(200,0,0));
    
    spaceArray[5]=new PropertySpace("ReadingRR", 5, 200, 25, false, 500, "Black", false ,false);
    spaceArray[5]->set_spaceAction(new PropertyAction());
    
    spaceArray[6]=new PropertySpace("Oriental", 6, 100, 6, false, 200, "LtBlue", false ,false);
    spaceArray[6]->set_spaceAction(new PropertyAction());
    
    spaceArray[7]=new CardSpace("Chance",7, chanceDeque);
    spaceArray[7]->set_spaceAction(new CardAction());
    
    spaceArray[8]=new PropertySpace("Vermont", 8, 100, 6, false, 200, "LtBlue", false ,false);
    spaceArray[8]->set_spaceAction(new PropertyAction());
    
    spaceArray[9]=new PropertySpace("Conneticut", 9, 120, 8, false, 250, "LtBlue", false ,false);
    spaceArray[9]->set_spaceAction(new PropertyAction());
    
    spaceArray[10]=new FreeSpace("Pass/Jail", 10);
    spaceArray[10]->set_spaceAction(new FreeAction(0));
    
    spaceArray[11]=new PropertySpace("St.Charles", 11, 140, 10, false, 300, "DarkRed", false ,false);
    spaceArray[11]->set_spaceAction(new PropertyAction());
    
    spaceArray[12]=new PropertySpace("Electric", 12, 150, 15, false, 150, "White", false ,false);
    spaceArray[12]->set_spaceAction(new PropertyAction());
    
    spaceArray[13]=new PropertySpace("St. Avenue", 13, 140, 10, false, 300, "DarkRed", false ,false);
    spaceArray[13]->set_spaceAction(new PropertyAction());
    
    spaceArray[14]=new PropertySpace("Virginia", 14, 160, 12, false, 350, "DarkRed", false ,false);
    spaceArray[14]->set_spaceAction(new PropertyAction());
    
    spaceArray[15]=new PropertySpace("PennRR", 15, 200, 25, false, 500, "Black", false ,false);
    spaceArray[15]->set_spaceAction(new PropertyAction());
    
    spaceArray[16]=new PropertySpace("St. James", 16, 180, 14, false, 400, "Orange", false ,false);
    spaceArray[16]->set_spaceAction(new PropertyAction());
    
    spaceArray[17]=new CardSpace("Community", 17, communityDeque);
    spaceArray[17]->set_spaceAction(new CardAction());
    
    spaceArray[18]=new PropertySpace("Tennessee", 18, 180, 14, false, 400, "Orange", false ,false);
    spaceArray[18]->set_spaceAction(new PropertyAction());
    
    spaceArray[19]=new PropertySpace("NewYork", 19, 200, 16, false, 450, "Orange", false ,false);
    spaceArray[19]->set_spaceAction(new PropertyAction());
    
    spaceArray[20]=new FreeSpace("Free Park", 20);
    spaceArray[20]->set_spaceAction(new FreeAction(0));
    
    spaceArray[21]=new PropertySpace("Kentucky", 21, 220, 18, false, 500, "Red", false ,false);
    spaceArray[21]->set_spaceAction(new PropertyAction());
    
    spaceArray[22]=new CardSpace("Chance",22, chanceDeque);
    spaceArray[22]->set_spaceAction(new CardAction());
    
    spaceArray[23]=new PropertySpace("Indiana", 23, 220, 18, false, 500, "Red", false ,false);
    spaceArray[23]->set_spaceAction(new PropertyAction());
    
    spaceArray[24]=new PropertySpace("Illinois", 24, 240, 20, false, 550, "Red", false ,false);
    spaceArray[24]->set_spaceAction(new PropertyAction());
    
    spaceArray[25]=new PropertySpace("B&ORR", 25, 200, 25, false, 500, "Black", false ,false);
    spaceArray[25]->set_spaceAction(new PropertyAction());
    
    spaceArray[26]=new PropertySpace("Atlantic", 26, 260, 22, false, 600, "Yellow", false ,false);
    spaceArray[26]->set_spaceAction(new PropertyAction());
    
    spaceArray[27]=new PropertySpace("Ventor", 27, 260, 22, false, 600, "Yellow", false ,false);
    spaceArray[27]->set_spaceAction(new PropertyAction());
    
    spaceArray[28]=new PropertySpace("Water", 28, 150, 15, false, 0, "White", false ,false);
    spaceArray[28]->set_spaceAction(new PropertyAction());
    
    spaceArray[29]=new PropertySpace("Marvin", 29, 280, 24, false, 650, "Yellow", false ,false);
    spaceArray[29]->set_spaceAction(new PropertyAction());
    
    spaceArray[30]=new GoToSpace("Go to Jail", 30, 10);
    spaceArray[30]->set_spaceAction(new GoToAction());
    
    spaceArray[31]=new PropertySpace("Pacific", 31, 300, 26, false, 700, "Green", false ,false);
    spaceArray[31]->set_spaceAction(new PropertyAction());
    
    spaceArray[32]=new PropertySpace("N. Carolina", 32, 300, 26, false, 700, "Green", false ,false);
    spaceArray[32]->set_spaceAction(new PropertyAction());
    
    spaceArray[33]=new CardSpace("Community", 33,communityDeque);
    spaceArray[33]->set_spaceAction(new CardAction());
    
    spaceArray[34]=new PropertySpace("Penn", 34, 320, 28, false, 750, "Green", false ,false);
    spaceArray[34]->set_spaceAction(new PropertyAction());
    
    spaceArray[35]=new PropertySpace("ShortRR", 35, 200, 25, false, 500, "Black", false ,false);
    spaceArray[35]->set_spaceAction(new PropertyAction());
    
    spaceArray[36]=new CardSpace("Chance",36,chanceDeque);
    spaceArray[36]->set_spaceAction(new CardAction());
    
    spaceArray[37]=new PropertySpace("Park Place", 37, 350, 35, false, 800, "DarkBlue", false ,false);
    spaceArray[37]->set_spaceAction(new PropertyAction());
    
    spaceArray[38]=new MoneySpace("Luxury Tax",38, -75);
    spaceArray[38]->set_spaceAction(new MoneyAction(75,0,0));
    
    spaceArray[39]=new PropertySpace("Boardwalk", 39, 400, 50, false, 850, "DarkBlue", false ,false);
    spaceArray[39]->set_spaceAction(new PropertyAction());

}



void GameBoard::printCompleteRow(int start, int topOrBottom)
{
    
    string nameline1[11];
    //string nameline2[10];
    for(int ii=0; ii<11; ii++)
    {
      
        
            int numberOfCharacters= spaceArray[(ii+start)%40]->get_spaceName().size();
            //add x number of spaces to the end of the word so the edges match up
            string blanksAfterWord="";
            // -4 for the first 4 spaces. Essentially have 11 spaces for each string name andif a string is less than 11 characters, the remainder of the string is filled up by spaces
            for(int jj=0; jj<15-numberOfCharacters-4; jj++)
            {
                blanksAfterWord=blanksAfterWord+ " ";
            }
        
        
            if(topOrBottom==11)
            {
                nameline1[ii]= spaceArray[ii+start]->get_spaceName() + blanksAfterWord;
            }
        
            else
            {
                nameline1[ii]= spaceArray[(ii+start)%40]->get_spaceName() + blanksAfterWord;
                
            }

    }

//---------------------------------------------------------------------------------------------------------------
    
    for(int aa=0; aa<11; aa++)
    {   cout<<"--------------- ";
    }
    cout<<endl;
//---------------------------------------------------------------------------------------------------------------

    if(topOrBottom==11)
    {
        for(int bb=0; bb<11; bb++)
        {   cout<<"|   "<< nameline1[bb]<< "|";
        }
        cout<<endl;
    }
    
    else
    {
        cout<<"|     GO       |";
        //for some reason, the name line is shifted by 1 total space to the right, so just modify the go square
        for(int bb=9; bb>=0; bb--)
        {   cout<<"|  "<< nameline1[bb]<< " |";
        }
        cout<<endl;
    }
//---------------------------------------------------------------------------------------------------------------

    for(int cc=0; cc<11; cc++)
    {   cout<<"--------------- ";
    }
    cout<<endl;
//---------------------------------------------------------------------------------------------------------------

    if(topOrBottom==11)
    {
        for(int dd=0; dd<11; dd++)
        {   cout<<"|      "<< spaceArray[dd+start]->get_spaceIndex() <<"      |";
        }
        cout<<endl;
    }
    
    else
    {
        for(int dd=10; dd>=0; dd--)
        {   cout<<"|      "<< spaceArray[(dd+start)%40]->get_spaceIndex();
            
            //for the go square
            if(spaceArray[(dd+start)%40]->get_spaceIndex()==0)
            {
                cout<<"       |";
            }

            else
            {   
                cout<<"      |";
            }
        }
        cout<<endl;
        
    }
//---------------------------------------------------------------------------------------------------------------

    for(int ee=0; ee<11; ee++)
    {   cout<<"|              |";
    }
    cout<<endl;
    
    
//---------------------------------------------------------------------------------------------------------------

    // accounting for 4 players, if less than 4 players, have to add extra spaces because originally subtracted 4 spaces to hold all four players on one space
    if(topOrBottom==11)
    {
        for(int ff=0; ff<11; ff++)
        {
            cout<<"|     ";
            for(int xx=0; xx<numPlayers; xx++)
            {
                
                if(spaceArray[ff+start]->get_spaceIndex()== ((playerArray[xx].get_location())%40))
                {
                    cout<<playerArray[xx].get_name();
                }
                
                else
                {
                    cout<<" ";
                }
            }
            if(numPlayers==2)
            {
                cout<<"  ";
            }
            if(numPlayers==3)
            {
                cout<<" ";
            }
            cout<< "     |";
        }
        cout<<endl;
    }
    
    else
    {
        for(int ff=10; ff>=0; ff--)
        {
            cout<<"|     ";
            for(int xx=0; xx<numPlayers; xx++)
            {
                
                if(spaceArray[(ff+start)%40]->get_spaceIndex()== ((playerArray[xx].get_location())%40))
                {
                    cout<<playerArray[xx].get_name();
                }
                
                else
                {
                    cout<<" ";
                }
            }
            if(numPlayers==2)
            {
                cout<<"  ";
            }
            if(numPlayers==3)
            {
                cout<<" ";
            }
            cout<< "     |";
        }
        cout<<endl;
    }
//---------------------------------------------------------------------------------------------------------------

    for(int gg=0; gg<11; gg++)
    {   cout<<"|              |";
    }
    cout<<endl;
//---------------------------------------------------------------------------------------------------------------
    
    if(topOrBottom==11)
    {
        for(int hh=0; hh<11; hh++)
        {
            cout<<"|  ";
                if(spaceArray[(hh+start)%40]->spaceType==0)
                {
                    if(((PropertySpace*)spaceArray[(hh+start)%40])->get_propertySpace_isOwned())
                    {
                        Player *p= ((PropertySpace*)spaceArray[(hh+start)%40])->get_propertySpace_owner();
                        cout<<"Owner: " <<p->get_name();
                    }
                    
                    //if it is a property space but is not owned
                    else
                    {
                        cout<<"        ";
                    }
                }
            
                //not a property space
                else
                {
                    cout<<"        ";
                }
     
            cout<< "    |";
        }
        cout<<endl;
    }
    
    else
    {
        for(int hh=10; hh>=0; hh--)
        {
            cout<<"|  ";
            if(spaceArray[(hh+start)%40]->spaceType==0)
            {
                if(((PropertySpace*)spaceArray[(hh+start)%40])->get_propertySpace_isOwned())
                {
                    Player *p= ((PropertySpace*)spaceArray[(hh+start)%40])->get_propertySpace_owner();
                    cout<<"Owner: " <<p->get_name();
                }
                
                //if it is a property space but is not owned
                else
                {
                    cout<<"        ";
                }
            }
            
            //not a property space
            else
            {
                cout<<"        ";
            }
            
            cout<< "    |";

        }
        cout<<endl;
    }

//---------------------------------------------------------------------------------------------------------------

    if(topOrBottom==11)
    {
        for(int ii=0; ii<11; ii++)
        {
            //it is a property space so you can cast the space as a property space in order to access the property space methods that are not virtual functions defined in the space class
            if(spaceArray[(ii+start)%40]->spaceType==0)
            {
                cout<<"|     "<<"$"<<  ((PropertySpace*)spaceArray[(ii+start)%40])->get_propertySpace_costToBuy()<<"     |";

            }
            
            
            else
            {
                cout<<"|              |";
            }
        }
        cout<<endl;
    }
   
    
    else
    {
        
        for(int ii=10; ii>=0; ii--)
        {
            if(spaceArray[(ii+start)%40]->spaceType==0)
            {
                cout<<"|     "<<"$"<< ((PropertySpace*)spaceArray[(ii+start)%40])->get_propertySpace_costToBuy()<<"     |";
            }
            
            //luxury tax
            else if(ii==8)
            {
                cout<<"|   pay $75    |";
            }

            
            else
            {
                cout<<"|              |";
            }
        }
        cout<<endl;
    }
    
//---------------------------------------------------------------------------------------------------------------

    for(int jj=0; jj<11; jj++)
    {   cout<<"--------------- ";
    }
    cout<<endl;
//---------------------------------------------------------------------------------------------------------------

    
    
  

}

/*prints out the spaces that are separated by the open area of the board*/
void GameBoard::printIncompleteRow(int leftSpace, int rightSpace)
{
    string leftNameLine;
    //can just do get_spaceName() because it is a virtual function in space and all of the subspaces have get_spaceName, so by calling get_spaceName it gets the name of the space for each of the subspaces
    int numberOfCharacters1=spaceArray[leftSpace]->get_spaceName().size();
    string blanksAfterWord1= "";
    for(int ii=0; ii<15-numberOfCharacters1-4; ii++)
    {
        blanksAfterWord1=blanksAfterWord1+ " ";
    }
    
    leftNameLine=spaceArray[leftSpace]->get_spaceName()+blanksAfterWord1;
    
    
    string rightNameLine;
    int numberOfCharacters2=spaceArray[rightSpace]->get_spaceName().size();
    string blanksAfterWord2= "";
    for(int jj=0; jj<15-numberOfCharacters2-4; jj++)
    {
        blanksAfterWord2=blanksAfterWord2+ " ";
    }
    
    rightNameLine=spaceArray[rightSpace]->get_spaceName()+blanksAfterWord2;
 
    
//---------------------------------------------------------------------------------------------------------------
    cout<<"|   "<<leftNameLine<<"|";
    for(int bb=0; bb<144; bb++)
    {
        cout<<" ";
    }
    cout<<"|   "<<rightNameLine<<"|";
    cout<<endl;
    
//---------------------------------------------------------------------------------------------------------------

    cout<<"--------------- ";
    for(int cc=0; cc<144; cc++)
    {
        cout<<" ";
    }
    cout<<"--------------- ";
    cout<<endl;
//---------------------------------------------------------------------------------------------------------------

    
    cout<<"|       "<< spaceArray[leftSpace]->get_spaceIndex() <<"      |";
    for(int dd=0; dd<144; dd++)
    {
        cout<<" ";
    }
    cout<<"|       "<< spaceArray[rightSpace]->get_spaceIndex() <<"     |";
    cout<<endl;
//---------------------------------------------------------------------------------------------------------------

    cout<<"|              |";
    for(int ee=0; ee<144; ee++)
    {
        cout<<" ";
    }
    cout<<"|              |";
    cout<<endl;
    
    
//---------------------------------------------------------------------------------------------------------------
    cout<<"|     ";
    for(int xx=0; xx<numPlayers; xx++)
    {
        if(spaceArray[leftSpace]->get_spaceIndex()== ((playerArray[xx].get_location())%40))
        {
            cout<<playerArray[xx].get_name();
        }
        else
        {
            cout<<" ";
        }
    }
    if(numPlayers==2)
    {
        cout<<"  ";
    }
    if(numPlayers==3)
    {
        cout<<" ";
    }
    cout<< "     |";
    
    for(int ff=0; ff<144; ff++)
    {
        cout<<" ";
    }
    
    cout<<"|     ";
    for(int yy=0; yy<numPlayers; yy++)
    {
        if(spaceArray[rightSpace]->get_spaceIndex()== ((playerArray[yy].get_location())%40))
        {
            cout<<playerArray[yy].get_name();
        }
        else
        {
            cout<<" ";
        }
    }
    if(numPlayers==2)
    {
        cout<<"  ";
    }
    if(numPlayers==3)
    {
        cout<<" ";
    }
    cout<< "     |";
    cout<<endl;

//---------------------------------------------------------------------------------------------------------------

    cout<<"|              |";
    for(int gg=0; gg<144; gg++)
    {
        cout<<" ";
    }
    cout<<"|              |";
    cout<<endl;
    
//---------------------------------------------------------------------------------------------------------------

    cout<<"|  ";
        if(spaceArray[leftSpace]->spaceType==0)
        {
            if(((PropertySpace*)spaceArray[(leftSpace)%40])->get_propertySpace_isOwned())
            {
                Player *p= ((PropertySpace*)spaceArray[(leftSpace)%40])->get_propertySpace_owner();
                cout<<"Owner: " <<p->get_name();
            }
            
            //if it is a property space but is not owned
            else
            {
                cout<<"        ";
            }
        }
        
        //not a property space
        else
        {
            cout<<"        ";
        }
    
    cout<< "    |";


    for(int hh=0; hh<144; hh++)
    {
        cout<<" ";
    }
    cout<<"|  ";
        if(spaceArray[rightSpace]->spaceType==0)
        {
            if(((PropertySpace*)spaceArray[(rightSpace)%40])->get_propertySpace_isOwned())
            {
                Player *p= ((PropertySpace*)spaceArray[(rightSpace)%40])->get_propertySpace_owner();
                cout<<"Owner: " <<p->get_name();
            }
            
            //if it is a property space but is not owned
            else
            {
                cout<<"        ";
            }
        }
        
        //not a property space
        else
        {
            cout<<"        ";
        }
        
        cout<< "    |";
        

    cout<<endl;
    
//---------------------------------------------------------------------------------------------------------------

        
    if(spaceArray[leftSpace]->spaceType==0)
    {
             cout<<"|     ";
        
        if(((PropertySpace*)spaceArray[leftSpace])->get_propertySpace_costToBuy()<100)
            
        {
            cout<< " ";
        }
        
         cout<<"$"<<((PropertySpace*)spaceArray[leftSpace])->get_propertySpace_costToBuy()<<"     |";

    }
    
    else if (leftSpace== 4)
    {
        cout<<"|   pay $200   |";
    }
    
   
    
    else
    {
        cout<<"|              |";
    }

    
    //only 2 digit amounts are on the left side of the board, so add extra space
    
    for(int ii=0; ii<144; ii++)
    {
        cout<<" ";
    }
    
    if( spaceArray[rightSpace]->spaceType==0)
    {
        cout<<"|     "<<"$"<<((PropertySpace*)spaceArray[rightSpace])->get_propertySpace_costToBuy()<<"     |";
        

    }
    
    
    else
    {
        cout<<"|              |";
    }
    cout<<endl;

//---------------------------------------------------------------------------------------------------------------

    cout<<"--------------- ";
    for(int jj=0; jj<144; jj++)
    {
        cout<< " ";
    }
    cout<<"--------------- ";
    cout<<endl;

//---------------------------------------------------------------------------------------------------------------
    
    if(leftSpace!=1)
    {   cout<<"--------------- ";
        for(int kk=0; kk<144; kk++)
        {
            cout<< " ";
        }
        cout<<"--------------- ";
        cout<<endl;
    }
}

void GameBoard::printBoard()
{
    //11 squares for top row, 10 for bottom row, mannualy create the go space
    
    printCompleteRow(10, 11);
    cout<<"--------------- ";
    for(int kk=0; kk<144; kk++)
    {
        cout<< " ";
    }
    cout<<"--------------- ";
    cout<<endl;

    for(int ii=0; ii<9; ii++)
    {   printIncompleteRow(9-ii, 21+ii);
    }
    printCompleteRow(30, 10);
   
}

void GameBoard::runGame()
{
 
    
    populateBoardAndCards();
    
    
    printBoard();

    
    bool keepPlaying=true;
    
    //game loop
    while(keepPlaying)
    {
        string play;
        for(int ii=0; ii<numPlayers; ii++)
        {
            int roll;
            do
            {
                cout<<"Please enter a 1 to roll the 12 sided dice: ";
                cin>>roll;
                if(cin.fail() ||roll !=1)
                {
                    cout<<"error please enter a 1 ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                
                break;
                
            }while(true);
            
            srand(time(0));
            int num=rand()%12 +1;
            cout<<endl<<"Player " <<playerArray[ii].get_name()<< " rolled a "<<num<<endl;
            
            //if this is 1, then it means the player passed go.  For example if the player is on parkplace space #37, rolls a 5, then it moves to space #2 because of the mmodulus.  However, 37+5=42  and 42/40 =1 which means the player passed go
            int passedGo=(playerArray[ii].get_location()+num)/40;
            
            if(passedGo==1)
            {
                int money=playerArray[ii].get_money();
                playerArray[ii].set_money(money +200);
            }
            
            
            int place=(playerArray[ii].get_location()+num)%40;

            string spaceName= spaceArray[place]->get_spaceName();
            
            // reseting the location of the player
            playerArray[ii].set_location(place);
            printBoard();
            
            cout<<playerArray[ii].get_name()<< " landed on "<<spaceArray[place]->get_spaceName()<<endl;
            spaceArray[place]->doAction(playerArray[ii]);
            
//______________________________________________________________________________________________________________________
 
            
 
            //its a card space so then have to carry out another action if player moves to a different space
            if(spaceArray[place]->spaceType==2)
            {
                //its a card space, now determine what type of action it has to perform
                //move action
                if(((CardSpace*)spaceArray[place])->get_cardTypeOfAction()==1)
                {
                    int move=((CardSpace*)spaceArray[place])->get_cardMove();
                    int currentLoc=playerArray[ii].get_location();
                    int location=(currentLoc+move)%40;
                    
                    if(currentLoc+move>=40)
                    {
                        int currentMoney=playerArray[ii].get_money();
                        playerArray[ii].set_money(currentMoney+200);
                    }
                    
                    playerArray[ii].set_location(location);
                    printBoard();
                    spaceArray[location]->doAction(playerArray[ii]);
                }
                
                //money action
                if(((CardSpace*)spaceArray[place])->get_cardTypeOfAction()==2)
                {
                    int cash= ((CardSpace*)spaceArray[place])->get_cardMoney();
                    int currentMoney=playerArray[ii].get_money();
                    playerArray[ii].set_money(currentMoney+cash);
                }
                
                //go to action
                if(((CardSpace*)spaceArray[place])->get_cardTypeOfAction()==3)
                {
                    int goTo=((CardSpace*)spaceArray[place])->get_cardGoTo();
                    int currentLoc=playerArray[ii].get_location();
                    playerArray[ii].set_location(goTo);
                    
                    //meaning they passed go.  for example if the current location is space #35 and goto is #10, then that must meant that they passed go to get to space 10.  Also since Go is space 0, if the currentlocation is 2, and they go to GO, go is #0 which is <2 so they should get 200 dollars
                    if(goTo<currentLoc)
                    {
                        int currentMoney=playerArray[ii].get_money();
                        playerArray[ii].set_money(currentMoney+200);
                    }
                    printBoard();
                    spaceArray[goTo]->doAction(playerArray[ii]);
                    

                    
                }
            }
            
            //show the most updated version
            printBoard();
            
        }
        
        
        for(int jj=0; jj<numPlayers; jj++)
        {
            int *array= playerArray[jj].get_colorArray();
            cout<<"Player "<<playerArray[jj].get_name()<<": $"<<playerArray[jj].get_money()<< " Owns: ";
            string myArray[28];
            int counterArray[28];
            int counter=0;
            
            for(int kk=0; kk<40; kk++)
            {
                // only check if the space has an owner if it is a proeprty space
                if(spaceArray[kk]->spaceType==0)
                {
                    if(((PropertySpace*)spaceArray[kk])->get_propertySpace_isOwned())
                    {
                        Player *p= ((PropertySpace*)spaceArray[kk])->get_propertySpace_owner();
                        if (p->get_number()==jj)
                        {
                            myArray[counter]=spaceArray[kk]->get_spaceName();
                            counterArray[counter]=spaceArray[kk]->get_spaceIndex();
                            //cout<<spaceArray[kk]->get_spaceName() <<", ";
                            cout<<myArray[counter] << " ";
                            
                            counter++;
                        }

                    }
                }
                
            }//end of kk for loop
            cout<<endl;
            
      
            
                if(array[0]==2 || array[1]==3 || array[2]==3 || array[3]==3 || array[4]==3 || array[5]==3 || array[6]==3 || array[7]==2 || array[8]==4 || array[9]==2)
                {
                    string answer;
                    cout<< endl<<playerArray[jj].get_name() << " owns all of a particular space type.  press (y) if you want to upgrade any space.  you can only upgrade one space per turn " <<endl;
                    cin>>answer;
                    
                    if(answer=="y")
                    {
                        string s;
                        cout<<" which space would you like to upgrade?";
                        cin>>s;
                        for(int ww=0; ww<counter; ww++)
                        {
                            if(myArray[ww]==s)
                            {
                                //counterArray stores the indicies of the spaces that a particular player owns
                                if(((PropertySpace*)spaceArray[counterArray[ww]])->get_propertySpace_isAlreadyUpgraded ==false)
                                {
                                    ((PropertySpace*)spaceArray[counterArray[ww]])->set_propertySpace_isUpgrading(true);
                                    spaceArray[counterArray[ww]]->doAction(playerArray[jj]);
                                    ((PropertySpace*)spaceArray[counterArray[ww]])->set_propertySpace_isAlreadyUpgraded(true);
                                    //need to reset to false so don't upgrade continuously.
                                     ((PropertySpace*)spaceArray[counterArray[ww]])->set_propertySpace_isUpgrading(false);
                                }
                                
                                else
                                {
                                    cout<<"space is already upgraded";
                                }
                            }
                            
                            else
                            {
                                cout<<"you don't own this space";
                            }
                        }
                    }

                }

            if(playerArray[jj].get_money()<0)
            {
                keepPlaying=false;
            }
        }
    
        cout<<"If everyone has enough money, do you want to continue a new round: type (quit) to quit, other wise enter any other letter, number, or symbol to continue: ";
        cin>>play;
        
        if(play=="quit")
        {
            keepPlaying=false;
        }
        
    }
}

