#include <cmath>
#include <vector>
#include <mutex>
#include "../include/number.hpp"

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void findPrimesWorkStealing(int start, int end, const vector<int>& numbers, vector<int>& primes, mutex& mtx) {
    for (int i = start; i < end; ++i) {
        if (isPrime(numbers[i])) {
            lock_guard<mutex> lock(mtx);
            primes.push_back(numbers[i]);
        }
    }
}

void findPrimesEvenDistribution(int start, int end, const vector<int>& numbers, vector<int>& primes) {
    for (int i = start; i < end; ++i) {
        if (isPrime(numbers[i])) {
            primes.push_back(numbers[i]);
        }
    }
}







