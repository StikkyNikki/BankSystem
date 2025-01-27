#include <map>
#include <vector>
#include <iostream>
#include <mutex>
#include <thread>
#include <random>
#include <functional>
#include "Bank.h"

std::mutex bankMutex; // ska revideras

void client(Bank &bank, std::mt19937 &gen);

int main()
{
    std::vector<std::thread> Clients;
    Bank bank;
    // srand(time(NULL));

    // slumpgenerator
    std::random_device rd;
    std::mt19937 gen(rd());

    // skapar bankid
    BankAccount account_1(1);
    BankAccount account_2(2);
    BankAccount account_3(3);
    BankAccount account_4(4);
    BankAccount account_5(5);

    // Kanske fungerar?
    bank.addAccount(std::move(account_1));
    bank.addAccount(std::move(account_2));
    bank.addAccount(std::move(account_3));
    bank.addAccount(std::move(account_4));
    bank.addAccount(std::move(account_5));

    // Skapar kunderna
    for (int i = 0; i < 10; i++)
    {
        Clients.emplace_back(std::thread(client, std::ref(bank)), std::ref(gen));
    }

    // Ser till att main väntar på tråderna om de finns.
    for (auto &t : Clients)
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    return 0;
}

void client(Bank &bank, std::mt19937 &gen) // test. Behöver kopplas till
{
    //// Slumpmässig distribution för kontonummer (1–5)
    std::uniform_int_distribution<> accountDist(1, 5);
    // Slumpmässig distribution för belopp (1 till 75)
    std::uniform_int_distribution<> amountDist(1, 75);

    std::uniform_int_distribution<> optionDist(1, 3);

    // Simulera en klient som gör några insättningar och uttag
    for (int i = 0; i < 5; ++i)
    {
        // Slumpa ett kontonummer
        int accountID = accountDist(gen);
        //// Slumpa ett belopp
        int amount = amountDist(gen);

        // Slumpar fram ett val av clienten.
        int option = optionDist(gen);
        switch (option)
        {

        case 1:
        {

            auto it = bank.getMap().find(accountID);

            if (it != bank.getMap().end())
            {
                std::cout << "Client ID: " << accountID << " ";
                it->second.withdraw(amount);
            }
            else
            {
                std::cout << "Account not found!" << std::endl;
            }
            // bank.withdraw(accountNumber, amount);
            break;
        }

        case 2:
        {
            auto it = bank.getMap().find(accountID);

            if (it != bank.getMap().end())
            {
                std::cout << "Client ID: " << accountID << " ";
                it->second.deposit(amount);
            }
            else
            {
                std::cout << "Account not found!" << std::endl;
            }
            break;
        }

        case 3:

        {
            auto it = bank.getMap().find(accountID);

            if (it != bank.getMap().end())
            {
                std::cout << "Client ID: " << accountID << " ";
                std::cout << "Balance: " << it->second.getBalance() << std::endl;
            }
            else
            {
                std::cout << "Account not found!" << std::endl;
            }
            break;
        }

        default:
            std::cout << "Something went wrong when choosing a option.\n";
            break;
        }
    }
}

// Hantera flera konton
// std::map<int, BankAccount>

// Skapa en funktion Client som simulerar en kund som utför transaktioner på ett slumpmässigt konto.
// Använd std::thread för att skapa flera kunder som körs samtidig
// KRAV
// Implementera minst 5 konton och 10 kunder som körs parallellt.
// Varje kund ska utföra slumpmässiga transaktioner (insättningar eller uttag).
// Skriv ut kontosaldon efter att alla kunder har slutfört sina transaktioner.