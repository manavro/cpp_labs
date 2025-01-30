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

    // ���������� std::set ��� �������� ����������
    std::set<int> uniqueElements(array.begin(), array.end());

    // ����������� set ������� � ������ (���� �����)
    std::vector<int> result(uniqueElements.begin(), uniqueElements.end());

    // ������� ���������
    std::cout << "Array after removing duplicates: ";
    for (const int& element : result) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}