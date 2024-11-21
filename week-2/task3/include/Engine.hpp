#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <string>
#include <iostream>
using namespace std;

class Engine {
private: 
    int power;
public:
    void setPower(int power);
    int getPower();
};
#endif 
