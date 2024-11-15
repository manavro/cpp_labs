#include <iostream>
#include <limits>

int main() {
	
	setlocale(LC_ALL, "RU");
	std::cout << "Максимальное значение для signed short: " << SHRT_MAX << std::endl;
	std::cout << "Минимальное значение для signed short: " << SHRT_MIN << std::endl;

	std::cout << "Максимальное значение для unsigned short: " << USHRT_MAX << std::endl;
	std::cout << "Минимальное значение для unsigned short: " << 0 << std::endl;

	std::cout << "Максимальное значение для signed int: " << INT_MAX << std::endl;
	std::cout << "Минимальное значение для signed int: " << INT_MIN << std::endl;

	std::cout << "Максимальное значение для unsigned int: " << UINT_MAX << std::endl;
	std::cout << "Минимальное значение для unsigned int: " << 0 << std::endl;

	std::cout << "Максимальное значение для signed long: " << LONG_MAX << std::endl;
	std::cout << "Минимальное значение для signed long: " << LONG_MIN << std::endl;

	std::cout << "Максимальное значение для unsigned long: " << ULONG_MAX << std::endl;
	std::cout << "Минимальное значение для unsigned long: " << 0 << std::endl;

	std::cout << "Максимальное значение для signed long long: " << LLONG_MAX << std::endl;
	std::cout << "Минимальное значение для signed long long: " << LLONG_MIN << std::endl;

	std::cout << "Максимальное значение для unsigned long long: " << ULLONG_MAX << std::endl;
	std::cout << "Минимальное значение для unsigned long long: " << 0 << std::endl;


	std::cout << "Максимальное значение для float: " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "Минимальное значение для float: " << std::numeric_limits<float>::lowest() << std::endl; // Используем lowest() для float и double

	std::cout << "Максимальное значение для double: " << std::numeric_limits<double>::max() << std::endl;
	std::cout << "Минимальное значение для double: " << std::numeric_limits<double>::lowest() << std::endl;

	std::cout << "Максимальное значение для long double: " << std::numeric_limits<long double>::max() << std::endl;
	std::cout << "Минимальное значение для long double: " << std::numeric_limits<long double>::lowest() << std::endl;

	return 0;
}
