#include <string>
#include <iostream>
#include "Engine.hpp"
#include "Passenger.hpp"

using namespace std;

class Car {

private:
    Engine engine;
    string model;

public: 
   
    Passenger* passenger1 = nullptr;
    Passenger* passenger2 = nullptr;

Car(const string& model, Engine engine);
void addPassenger(Passenger* passenger);
void removePassenger(Passenger passenger);
string displayInfo();

};
