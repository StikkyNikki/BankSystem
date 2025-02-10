#include "BankAccount.h"

BankAccount::BankAccount() {

};


BankAccount::BankAccount(int accountNumber) 
    {
        this->accountNumber = accountNumber;
    } 

//Sätter in pengar på kontot
void BankAccount::deposit(int amount) 
{       

        std::cout << "Client " << std::this_thread::get_id()
                  << " is depositing.\n";


        balance += amount;
        std::cout << amount << " has been deposited in account " << accountNumber << std::endl;

        std::cout << "Current balance: " << balance << "\n\n";
}


//Tar ut pengar från kontot, om mängden de vill ta ut är tillgänglig. 
void BankAccount::withdraw(int amount) 
{   

    std::cout << "Client " << std::this_thread::get_id()
              << " is attempting to withdraw.\n";


    if (balance - amount >= 0) {

        balance -= amount;
        std::cout << amount << " has been withdrawn from account " << accountNumber << std::endl;

        std::cout << "Current balance: " << balance << "\n\n";
    } else {

        std::cout << "Could not withdraw, not enough funds in account.\n\n";
    }   
}


void BankAccount::getAccountDetails() {

    std::cout << "Client " << std::this_thread::get_id() 
              << " is checking the balance of a account.\n";


    std::cout << "Account " << accountNumber << "\n"
              << "Current balance: " << balance << "\n\n";
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