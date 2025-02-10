#include "Utility.h"

// Skyddar bankens resurser
std::mutex BankM;

// Skapar en lokal generator för varje tråd.
thread_local std::mt19937 gen(std::random_device{}());

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