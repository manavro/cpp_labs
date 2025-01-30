#include <iostream>
#include <thread>
#include "../include/entropy_calculator.h"

int main() {
    std::string filePath = "largefile.txt";

    std::thread t(calculateEntropy, filePath);
    t.join();

    return 0;
}
