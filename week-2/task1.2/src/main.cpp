#define _USE_MATH_DEFINES
#include <iostream>
#include "Octagon.hpp"
using namespace std;

int main()
{
    Octagon O;
    O.setinneradius(100);
    cout << O.getinneradius() << endl;
    cout << O.calculatedArea() << endl;
    cout << O.calculatePerimeter() << endl;
    
}
