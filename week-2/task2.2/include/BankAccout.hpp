#include <string>
#include <iostream>
using namespace std;


class BankAccount {
private:
    string AccountNumber;
    float Balance{};
    

public:

    void setBalance(float Balance);
    float getBalance();
    void deposit(float amount);
    void withdraw(float amount);  
   
 };
