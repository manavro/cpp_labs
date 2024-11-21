#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int age;
    cout << "Введите возраст: ";
    cin >> age;

    if (age % 100 >= 11 && age % 100 <= 14) {
        cout << age << " лет";
    }
    else if (age % 10 == 1) {
        cout << age << " год";
    }
    else {
        switch (age % 10) {
        case 2:
            cout << age << " года";
            break;
        case 3:
            cout << age << " года";
            break;
        case 4:
            cout << age << " года";
            break;
        default:
            cout << age << " лет";
        }
    }

    return 0;
}
