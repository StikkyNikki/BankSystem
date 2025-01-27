#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>


class BankAccount 

{
    int balance = 500;
    int accountNumber;

public:
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
    int getAccountNumber();


    BankAccount(int accountNumber) 
    {
        this->accountNumber = accountNumber;
    } 

};

#endif