#ifndef UTILITY_H
#define UTILITY_H
#include <random>
#include <mutex>
#include "Bank.h"

// Skyddar Bank-mappen 
extern std::mutex BankM;

// Skapar en lokal generator för varje tråd.
extern thread_local std::mt19937 gen;

void client(Bank& bank);

int determineAccount();

int determineAmount();

int determineClientAction();

#endif