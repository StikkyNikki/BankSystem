#include "BankAccount.h"

void BankAccount::deposit(int amount) 
{
        balance += amount;
        std::cout << amount << " has been deposited in account " << accountNumber << std::endl;
}

void BankAccount::withdraw(int amount) 
{

    if (balance - amount >= 0) {
        balance -= amount;
        std::cout << amount << " has been withdrawn from account " << accountNumber << std::endl;
    } else {
        std::cout << "Could not withdraw, not enough funds in account.\n";
    }   
}

int BankAccount::getBalance() 
{
    return balance;
}

int BankAccount::getAccountNumber() 
{
    return accountNumber;
}