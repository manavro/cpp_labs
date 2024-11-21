#include "Octagon.hpp"

using namespace std;

void Octagon::setinneradius(int inneradius){
	this->inneradius = inneradius;
}

int Octagon::getinneradius() {
        return inneradius;
}

int Octagon::calculatedArea() {
        return 8 * pow(inneradius, 2) * (sqrt(2) - 1);
}

double Octagon::calculatePerimeter() {
        return 2 * inneradius * tan(M_PI/8);
    }
