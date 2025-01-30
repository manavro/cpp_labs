#include <iostream>
#include "StackInterface.h"
#include "Stack.cpp"

int main() {
    Stack<int> stackInt;
    stackInt.push(1);
    stackInt.push(2);
    std::cout << "Top element (int): " << stackInt.top() << std::endl;
    stackInt.pop();

    Stack<std::string> stackString;
    stackString.push("Hello");
    stackString.push("World");
    std::cout << "Top element (string): " << stackString.top() << std::endl;
    stackString.pop();

    return 0;
}