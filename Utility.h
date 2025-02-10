#ifndef UTILITY_H
#define UTILITY_H
#include <random>
#include <mutex>

// Skyddar Bank-mappen 
extern std::mutex BankM;

// Skapar en lokal generator för varje tråd.
extern thread_local std::mt19937 gen; 

int determineAccount();

int determineAmount();

int determineClientAction();

#endif