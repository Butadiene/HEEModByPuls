#include <string>
#include <iostream>
#include "Account.hpp"

using namespace std;

Account::Account(string name, string num, long amnt){
    full_name = name;
    number = num;
    crnt_balance = amnt;
}

void Account::deposit(long amnt){
    crnt_balance += amnt;
}

void Account::withdraw(long amnt){
    crnt_balance -= amnt;
}