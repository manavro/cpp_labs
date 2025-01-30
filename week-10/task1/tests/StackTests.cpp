#include <cassert>
#include "StackInterface.h"
#include "../src/Stack.cpp"  // Подключаем реализацию

void testStack() {
    Stack<int> intStack;
    assert(intStack.isEmpty());

    intStack.push(10);
    assert(!intStack.isEmpty());
    assert(intStack.top() == 10);

    intStack.push(20);
    assert(intStack.top() == 20);

    assert(intStack.pop() == 20);
    assert(intStack.top() == 10);

    assert(intStack.pop() == 10);
    assert(intStack.isEmpty());

    try {
        intStack.pop();
    } catch (const std::runtime_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
}

int main() {
    testStack();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
