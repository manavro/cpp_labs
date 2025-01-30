#ifndef INTEGRATOR_H
#define INTEGRATOR_H

double integrate(double (*func)(double), double a, double b, int numSteps);
double function(double x);
void calculateArea(double a, double b, int numSteps);

#endif