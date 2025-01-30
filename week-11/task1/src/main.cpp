#include <iostream>
#include <thread>
#include "../include/integrator.h"

int main() {
    double a, b;
    int numSteps;

    std::cout << "Enter lower limit (a): ";
    std::cin >> a;
    std::cout << "Enter upper limit (b): ";
    std::cin >> b;
    std::cout << "Enter number of steps: ";
    std::cin >> numSteps;

    std::thread t(calculateArea, a, b, numSteps);
    t.join();

    return 0;
}
