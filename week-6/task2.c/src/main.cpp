#include <iostream>
#include <chrono>
#include <vector>

unsigned long long fibonacciClassic(int n) {
    if (n <= 1) return n;
    return fibonacciClassic(n - 1) + fibonacciClassic(n - 2);
}


unsigned long long fibonacciOptimized(int n, std::vector<unsigned long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    memo[n] = fibonacciOptimized(n - 1, memo) + fibonacciOptimized(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the Fibonacci number: ";
    std::cin >> n;

    auto startClassic = std::chrono::high_resolution_clock::now();
    unsigned long long resultClassic = fibonacciClassic(n);
    auto endClassic = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationClassic = endClassic - startClassic;

    std::cout << "Classic Fibonacci number (" << n << "): " << resultClassic << std::endl;
    std::cout << "Execution time (classic): " << durationClassic.count() << " seconds" << std::endl;

    std::vector<unsigned long long> memo(n + 1, 0);
    auto startOptimized = std::chrono::high_resolution_clock::now();
    unsigned long long resultOptimized = fibonacciOptimized(n, memo);
    auto endOptimized = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationOptimized = endOptimized - startOptimized;

    std::cout << "Optimized Fibonacci number (" << n << "): " << resultOptimized << std::endl;
    std::cout << "Execution time (optimized): " << durationOptimized.count() << " seconds" << std::endl;

    return 0;
}
