#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <mutex>

//Skyddar Bank mappen 
std::mutex BankM;

class BankAccount 

{
    //Start värde för konton. 
    int balance = 500;
    int accountNumber;

public:

    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
    int getAccountNumber();

    //Konstruerar en instans av BankAccount och tilldelar ett accountNumber. 
    BankAccount(int accountNumber) 
    {
        this->accountNumber = accountNumber;
    } 

};

#endif