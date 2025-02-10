#ifndef BANK_H
#define BANK_H

#include <map>
#include "BankAccount.h"

class Bank
{
    std::map<int, BankAccount> Accounts;
    

public:

    void addAccount(BankAccount account);
    //void getAccountDetails(int key);
    std::map<int, BankAccount> &getMap();
};

#endif