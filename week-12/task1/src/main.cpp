#include "../include/number.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <random>
#include <mutex>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <numbers...>" << endl;
        return 1;
    }

    vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        numbers.push_back(stoi(argv[i]));
    }

    plog::init(plog::debug, new plog::ColorConsoleAppender<plog::TxtFormatter>());
    
    vector<int> primesWS;  
    vector<int> primesED;  
    mutex mtx;
    int numThreads = thread::hardware_concurrency();
    vector<thread> threads;

   
    auto startTimeWS = chrono::high_resolution_clock::now();

    int range = numbers.size() / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        int threadStart = i * range;
        int threadEnd = (i == numThreads - 1) ? numbers.size() : threadStart + range;
        threads.emplace_back(findPrimesWorkStealing, threadStart, threadEnd, ref(numbers), ref(primesWS), ref(mtx));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    auto endTimeWS = chrono::high_resolution_clock::now();
    chrono::duration<double> durationWS = endTimeWS - startTimeWS;
    PLOGD << "Work Stealing duration: " << durationWS.count() << " seconds";

    
    cout << "Простые числа (Work Stealing): ";
    for (int prime : primesWS) {
        cout << prime << " ";
    }
    cout << endl;

    
    vector<int> shuffledNumbers = numbers;
    shuffle(shuffledNumbers.begin(), shuffledNumbers.end(), default_random_engine());

    auto startTimeED = chrono::high_resolution_clock::now();
    findPrimesEvenDistribution(0, shuffledNumbers.size(), shuffledNumbers, primesED);
    auto endTimeED = chrono::high_resolution_clock::now();
    chrono::duration<double> durationED = endTimeED - startTimeED;
    PLOGD << "Shuffle: " << durationED.count() << " seconds";

   
    sort(primesED.begin(), primesED.end());

    
    cout << "Простые числа (Shuffle): ";
    for (int prime : primesED) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}




