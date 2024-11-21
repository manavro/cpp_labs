#include <string>
#include <iostream>
#include "Engine.hpp"
#include "Passenger.hpp"
#include "Car.hpp"

using namespace std;

int main()
{
    Engine v12;
    v12.setPower(2);
    Passenger b1;
    b1.setName("Lesha");
    Passenger b2;
    b2.setName("Anton");
    Car Lada("Lada", v12);
    Lada.addPassenger(&b1);
    Lada.addPassenger(&b2);
    cout << Lada.displayInfo() << endl;

}
