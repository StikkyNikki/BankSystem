#ifndef BANK_H
#define BANK_H

#include <map>
#include "BankAccount.h"

class Bank
{
    std::map<int, BankAccount> Accounts;

public:
    void addAccount(BankAccount account);
    auto getAccountDetails(int key);
    std::map<int, BankAccount> &getMap();
    // auto getAccountDetails(int key);
};

#endif