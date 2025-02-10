#include "Utility.h"

// Skyddar bankens resurser
std::mutex BankM;

// Skapar en lokal generator för varje tråd.
thread_local std::mt19937 gen(std::random_device{}());


void client(Bank &bank) // test. Behöver kopplas till
{

    // Slumpmässig distribution för kontonummer (1–5)
    //std::uniform_int_distribution<> accountDist(1, 5);

    // Slumpmässig distribution för belopp (1 till 75)
    //std::uniform_int_distribution<> amountDist(1, 75);

    // Slumpar fram en handling mellan tre val för klienten. 
    //std::uniform_int_distribution<> optionDist(1, 3);

    // Simulera en klient som gör några insättningar och uttag
    for (int i = 0; i < 5; ++i)
    {

        // Slumpa ett kontonummer
        int accountID = determineAccount();


        //// Slumpa ett belopp
        int amount = determineAmount();


        // Slumpar fram ett val av clienten.
        int action = determineClientAction();


        //Avgör vad klienten ska göra utifrån slumpgeneratorn. 
        switch (action)
        {
        
        
        //Klienten försöker ta ut pengar ur ett konto.
        case 1:
        {

            auto it = bank.getMap().find(accountID);
            std::lock_guard<std::mutex> lock(BankM);

            if (it != bank.getMap().end())
            {
                //std::cout << "Account ID: " << accountID << " ";
                it->second.withdraw(amount);
            }
            
            else
            {
                std::cout << "Account not found!" << std::endl;
            }
            // bank.withdraw(accountNumber, amount);
            break;
        }


        //Klienten sätter in pengar på ett konto.
        case 2:
        {
            auto it = bank.getMap().find(accountID);
            std::lock_guard<std::mutex> lock(BankM);

            if (it != bank.getMap().end())
            {
                //std::cout << "Account ID: " << accountID << " ";
                it->second.deposit(amount);
            }

            else
            {
                std::cout << "Account not found!" << std::endl;
            }
            break;
        }


        //Klienten stämmer av saldot hos ett konto.
        case 3:
        {
            auto it = bank.getMap().find(accountID);
            std::lock_guard<std::mutex> lock(BankM);

            if (it != bank.getMap().end())
            {
                it->second.getAccountDetails();
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


int determineAccount() {

    // Slumpmässig distribution för kontonummer (1–5)
    std::uniform_int_distribution<> accountDist(1, 5);

    return accountDist(gen); 
}


int determineAmount() {

    // Slumpmässig distribution för belopp (1 till 75)
    std::uniform_int_distribution<> amountDist(1, 75);

    return amountDist(gen);
}


int determineClientAction() {

    // Slumpar fram en handling mellan tre val för klienten. 
    std::uniform_int_distribution<> optionDist(1, 3);

    return optionDist(gen);
}