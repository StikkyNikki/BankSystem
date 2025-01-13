#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount 
{
    int balance;
    int accountNumber;
public:
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
    
};

#endif