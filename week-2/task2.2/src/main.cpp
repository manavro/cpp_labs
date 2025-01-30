#include "BankAccout.hpp"


int main()
{
    BankAccount One;
    One.setBalance(100);
    One.deposit(200);
    One.withdraw(250);
    cout << "Accout Balance: "  << One.getBalance() << endl;
}

