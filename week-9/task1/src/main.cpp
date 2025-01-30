#include <iostream>
#include <chrono>
#include <vector>
#include <stdexcept>
#include "../include/fibonacci.hpp"

using namespace std;

int main() {
    vector<int> n_values;
    vector<double> classic_times;
    vector<double> optimized_times;

    string input; 
    cout << "Данные для построения графиков:\n"; 
    cout << "n\tClassic\tOptimized\n"; 

    while (true) {
        cout << "Введите число Фибоначчи (или . для выхода, c для очистки): ";
        cin >> input;

        if (input == ".") {
            break; 
        } else if (input == "c") {
            n_values.clear();
            classic_times.clear();
            optimized_times.clear();
            cout << "Данные очищены.\n";
            continue; 
        }

        try {
            int n = stoi(input); 
            n_values.push_back(n);

            
            auto start = chrono::high_resolution_clock::now();
            long long classic_result = fibonacci_classic(n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> classic_time = end - start;
            classic_times.push_back(classic_time.count());

          
            start = chrono::high_resolution_clock::now();
            long long optimized_result = fibonacci_optimized(n);
            end = chrono::high_resolution_clock::now();
            chrono::duration<double> optimized_time = end - start;
            optimized_times.push_back(optimized_time.count());

           
            cout << "Fibonacci(" << n << ") = " << classic_result << " (classic) in " 
                 << classic_times.back() << " seconds\n";
            cout << "Fibonacci(" << n << ") = " << optimized_result << " (optimized) in " 
                 << optimized_times.back() << " seconds\n";
        } catch (const invalid_argument& e) {
            cout << "Некорректный ввод. Пожалуйста, введите целое число.\n";
        } catch (const out_of_range& e) {
            cout << "Число слишком велико. Пожалуйста, введите меньшее значение.\n";
        }
    }

    return 0;
}








