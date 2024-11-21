#ifndef PASSENGER_HPP
#define PASSENGER_HPP
#include <string>
#include <iostream>
using namespace std;

class Passenger {

private:
    string name;

public: 
    void setName(string name);
    string getName();
};

#endif
