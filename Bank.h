#ifndef BANK_H
#define BANK_H

#include <map>
#include "BankAccount.h"

class Bank {
    std::map<int, BankAccount> Accounts;
};

#endif