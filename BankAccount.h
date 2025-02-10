#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <thread>

class BankAccount 

{
    //Start värde för konton. 
    int balance = 500;
    int accountNumber;

public:

    //en tom konstruktor för BankAccount
    BankAccount();

    //Konstruerar en instans av BankAccount och tilldelar ett accountNumber. 
    BankAccount(int accountNumber); 
    
    
    void deposit(int amount);
    void withdraw(int amount);
    void getAccountDetails();
    int getBalance();
    int getAccountNumber();
    

};

#endif