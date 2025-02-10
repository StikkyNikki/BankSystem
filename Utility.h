#ifndef UTILITY_H
#define UTILITY_H
#include <random>

//Skapar en lokal generator för varje tråd.
thread_local std::mt19937 gen(std::random_device{}()); 

int determineAccount();

int determineAmount();

int determineClientAction();

#endif