#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> array(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    // Используем std::set для удаления дубликатов
    std::set<int> uniqueElements(array.begin(), array.end());

    // Преобразуем set обратно в вектор (если нужно)
    std::vector<int> result(uniqueElements.begin(), uniqueElements.end());

    // Выводим результат
    std::cout << "Array after removing duplicates: ";
    for (const int& element : result) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}