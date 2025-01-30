#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{       
        // Максимальное и минимальное значение зависит от количества занимаемо памяти
        // Все переменные Unsignet имеют минимальное значение 0 
        short n = 32767;  // Занимет в памяти 2 байта
        short min = -32768; // Занимет в памяти 2 байтт
        unsigned short  b = 65535; // Занимает в памяти 2 байта
        int long d = 2147483648; // Занимает в памяти 4 байта
        int long min2 = -2147483648; // Занимает в памяти 4 байта
        unsigned long a = 4294967295; // Занимает в памяти 4 байт
        long long int lon = 9223372036854775807; // Занимает в памяти 8 байт
        long long int minl = -9223372036854775807; // Занимает в памяти 8 байт
        unsigned long long int r  = 18446744073709551615; // Занимает в памяти 8 байт 
        cout << "Hello World" << endl;
        cout << "Short max: " << n << endl;
        cout << "Short min: " << min << endl;
        cout << "Unsignet short max: " << b << endl;
        cout << "Long max:  " << d << endl;
        cout << "Long min: " << min2 << endl;
        cout << "Unsignet long: " << a << endl;
        cout << "Long Long max: " << lon << endl;
        cout << "Long long min: " << minl << endl;
        cout << "Unsigned long long max: " << r << endl;
}
