#include "../include/integrator.h"
#include <iostream>
#include <thread>

double integrate(double (*func)(double), double a, double b, int numSteps) {
    double step = (b - a) / static_cast<double>(numSteps);
    double area = 0.0;

    for (int i = 0; i < numSteps; ++i) {
        double x = a + i * step;
        area += func(x) * step;
    }
    return area;
}

double function(double x) {
    return x * x;
}

void calculateArea(double a, double b, int numSteps) {
    double area = integrate(function, a, b, numSteps);
    std::cout << "Area of the curved trapezoid from " << a << " to " << b << " is: " << area << std::endl;
}
