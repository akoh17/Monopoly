//
//  Bank.cpp
//  Monopoly
//
//  Created by Alex Koh on 4/18/14.
//  Copyright (c) 2014 Alex Koh. All rights reserved.
//

#include "Bank.h"
#include <string>

using namespace std;

Bank::Bank()
{
    
}

Bank::~Bank()
{
    
}

void Bank::set_bankMoneyAmount(int money)
{
    amount=money;
}

int Bank::get_bankMoneyAmount()
{
    return amount;
}