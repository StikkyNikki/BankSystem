#include "BankAccount.h"

//Sätter in pengar på kontot
void BankAccount::deposit(int amount) 
{
        balance += amount;
        std::cout << amount << " has been deposited in account " << accountNumber << std::endl;
}


//Tar ut pengar från kontot, om mängden de vill ta ut är tillgänglig. 
void BankAccount::withdraw(int amount) 
{

    if (balance - amount >= 0) {
        balance -= amount;
        std::cout << amount << " has been withdrawn from account " << accountNumber << std::endl;
    } else {
        std::cout << "Could not withdraw, not enough funds in account.\n";
    }   
}


//Returnerar saldo för kontot.
int BankAccount::getBalance() 

{
    return balance;
}


//Returnerar kontonummer för konto. 
int BankAccount::getAccountNumber() 

{
    return accountNumber;
}