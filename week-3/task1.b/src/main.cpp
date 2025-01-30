#include <iostream>
using namespace std;

int main() {
    int month, year;
    cout << "Enter month (from 1 to 12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        switch (month) {
        case 1:
            cout << 31 << endl;
            break;
        case 2:
            cout << 29 << endl;
            break;
        default:
            if (month > 2) {
                cout << month * 30 + (month % 2 ? 1 : 0) << endl;
            }
            else {
                cout << (month - 1) * 31 + 28 << endl;
            }
        }
    }
    else {
        switch (month) {
        case 1:
            cout << 31 << endl;
            break;
        case 2:
            cout << 28 << endl;
            break;
        default:
            if (month > 2) {
                cout << month * 30 + (month % 2 ? 1 : 0) << endl;
            }
            else {
                cout << (month - 1) * 31 << endl;
            }
        }
    }

    return 0;
}
