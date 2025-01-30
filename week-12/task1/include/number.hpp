#ifndef NUMBER_HPP
#define NUMBER_HPP

#include <vector>
#include <mutex>


void findPrimesWorkStealing(int start, int end, const std::vector<int>& numbers, std::vector<int>& primes, std::mutex& mtx);
void findPrimesEvenDistribution(int start, int end, const std::vector<int>& numbers, std::vector<int>& primes);

#endif 





