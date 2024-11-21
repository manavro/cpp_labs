#include <iostream>

void printPyramid(int height) {
    for (int i = 1; i <= height; ++i) {
        
        for (int j = i; j < height; ++j) {
            std::cout << " ";
        }
        
        for (int k = 1; k <= (2 * i - 1); ++k) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
}
