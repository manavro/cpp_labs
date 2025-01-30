#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;
double area(double a);
int main()
{	int f = 0;       
        cout << "Enter Length: " << endl;
        cin >> f;
        cout << "Volume of the Icosahedron: "<< area(f) << endl;
}

double area(double a) {

   return (5.0 / 12.0) * (3 + sqrt(5)) * pow(a, 3);
}
