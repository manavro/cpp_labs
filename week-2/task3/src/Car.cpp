#include "Car.hpp"
using namespace std;

Car::Car(const string& model, Engine engine) {
         this->model = model;
         this->engine = engine;
    }

void Car::addPassenger(Passenger* passenger) {
        if (passenger1 == NULL) {

            this->passenger1 = passenger; 
        }
        else {
            this->passenger2 = passenger;

        }
    
    }
void Car::removePassenger(Passenger passenger) {
        if (passenger1->getName() == passenger.getName()) {
            passenger1 = NULL; 
        }
    
        if (passenger2->getName() == passenger.getName()) {
            passenger2 = NULL;
        }
    }

string Car::displayInfo() {
        string d;
        d.append("Car Model: ");
        d.append(model);
        d.append("\n");
        d.append("Engine power: ");
        d.append(to_string(engine.getPower()));
        d.append("\n");
        d.append("Passenger 1: ");
        d.append(passenger1->getName());
        d.append("\n");
        d.append("Passenger 2: ");
        d.append(passenger2->getName());
        d.append("\n");
        return d;
    }


