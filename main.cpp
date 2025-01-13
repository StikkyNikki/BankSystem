#include <map>
#include <iostream>
#include <mutex>

void client();

int main()
{

}

void client() {

}


//Hantera flera konton
//std::map<int, BankAccount> 

//Skapa en funktion Client som simulerar en kund som utför transaktioner på ett slumpmässigt konto.
//Använd std::thread för att skapa flera kunder som körs samtidig
//KRAV
//Implementera minst 5 konton och 10 kunder som körs parallellt.
//Varje kund ska utföra slumpmässiga transaktioner (insättningar eller uttag).
//Skriv ut kontosaldon efter att alla kunder har slutfört sina transaktioner.