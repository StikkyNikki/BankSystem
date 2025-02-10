#include "Bank.h"


void Bank::addAccount(BankAccount account /*, int accountNumber, int balance*/)
{

    Accounts[account.getAccountNumber()] = account;

    std::cout << "Account added.\n";

    // Accounts[accountNumber] = BankAccount(account.getAccountNumber(), balance);
}

/*void Bank::getAccountDetails(int key)
{

    // Finds the correct value through key and print out the account ID and Balance.
    auto it = Accounts.find(key);

    if (it != Accounts.end())
    {

        std::cout << "Account ID: " << it->second.getAccountNumber() << " Balance: " 
                  << it->second.getBalance() << std::endl;
    }

    else
    {
        std::cout << "Account not found!" << std::endl;
    }
}*/


//Returnerar Map från Bank klassen. 
std::map<int, BankAccount> &Bank::getMap()
{
    return Accounts;
}

// Hantera flera konton i en std::map<int, BankAccount> .
// Implementera metoder för att lägga till konton och hämta kontouppgifter

