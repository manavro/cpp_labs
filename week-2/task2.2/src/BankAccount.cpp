#include "BankAccout.hpp"
using namespace std;


    void BankAccount::setBalance(float Balance) {
        
        this->Balance = Balance;

    }

    float BankAccount::getBalance() {
        return Balance;
}

    void BankAccount::deposit(float amount) {

        this->Balance += amount;

    }

    void BankAccount::withdraw(float amount) {

        if (amount > Balance) {
            cout << "Balance calculation amount" << endl;
        } else
        {
            Balance -= amount;
        }
}
