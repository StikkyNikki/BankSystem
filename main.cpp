#include <map>
#include <vector>
#include <iostream>
#include <functional>
//#include "Bank.h"
#include "Utility.h"

//std::mutex& determineMutex(int accountID);

int main()
{
    std::vector<std::thread> Clients;
    Bank bank;

    // srand(time(NULL));

    // slumpgenerator
    /*std::random_device rd;
    std::mt19937 gen(rd());*/

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
        Clients.emplace_back(std::thread(client, std::ref(bank)));
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


//Determine which account to lock by returning the associated mutex.
/*std::mutex& determineMutex(int accountID) {
    switch (accountID) {

        case 1:
        return a1;
        break;

        case 2: 
        return a2;
        break;

        case 3:
        return a3;
        break;

        case 4:
        return a4;
        break;

        case 5:
        return a5;
        break;

        default: 
        std::cout << "Something went wrong when determining mutex.\n";
        break;
    }

}*/

// Hantera flera konton
// std::map<int, BankAccount>

// Skapa en funktion Client som simulerar en kund som utför transaktioner på ett slumpmässigt konto.
// Använd std::thread för att skapa flera kunder som körs samtidig
// KRAV
// Implementera minst 5 konton och 10 kunder som körs parallellt.
// Varje kund ska utföra slumpmässiga transaktioner (insättningar eller uttag).
// Skriv ut kontosaldon efter att alla kunder har slutfört sina transaktioner.