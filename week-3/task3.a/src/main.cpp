#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    int size;

    cout << "Enter the number of elements in the array (no more than " << MAX_SIZE << "): ";
    cin >> size;

    
    if (size > MAX_SIZE) {
        cout << "The number of elements exceeds the maximum array size." << endl;
        return 1;
    }

    cout << "Enter Array Elements: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
    }

    int maxNumber = numbers[0];
    for (int i = 1; i < size; ++i) {
        if (numbers[i] > maxNumber) {
            maxNumber = numbers[i];
        }
    }

    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (numbers[i] == maxNumber) {
            count++;
        }
    }

    cout << "Number of elements equal to maximum (" << maxNumber << "): " << count << endl;

    return 0;
}
