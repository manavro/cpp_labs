#include <iostream>
#include <limits>

int main() {
	
	setlocale(LC_ALL, "RU");
	std::cout << "������������ �������� ��� signed short: " << SHRT_MAX << std::endl;
	std::cout << "����������� �������� ��� signed short: " << SHRT_MIN << std::endl;

	std::cout << "������������ �������� ��� unsigned short: " << USHRT_MAX << std::endl;
	std::cout << "����������� �������� ��� unsigned short: " << 0 << std::endl;

	std::cout << "������������ �������� ��� signed int: " << INT_MAX << std::endl;
	std::cout << "����������� �������� ��� signed int: " << INT_MIN << std::endl;

	std::cout << "������������ �������� ��� unsigned int: " << UINT_MAX << std::endl;
	std::cout << "����������� �������� ��� unsigned int: " << 0 << std::endl;

	std::cout << "������������ �������� ��� signed long: " << LONG_MAX << std::endl;
	std::cout << "����������� �������� ��� signed long: " << LONG_MIN << std::endl;

	std::cout << "������������ �������� ��� unsigned long: " << ULONG_MAX << std::endl;
	std::cout << "����������� �������� ��� unsigned long: " << 0 << std::endl;

	std::cout << "������������ �������� ��� signed long long: " << LLONG_MAX << std::endl;
	std::cout << "����������� �������� ��� signed long long: " << LLONG_MIN << std::endl;

	std::cout << "������������ �������� ��� unsigned long long: " << ULLONG_MAX << std::endl;
	std::cout << "����������� �������� ��� unsigned long long: " << 0 << std::endl;


	std::cout << "������������ �������� ��� float: " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "����������� �������� ��� float: " << std::numeric_limits<float>::lowest() << std::endl; // ���������� lowest() ��� float � double

	std::cout << "������������ �������� ��� double: " << std::numeric_limits<double>::max() << std::endl;
	std::cout << "����������� �������� ��� double: " << std::numeric_limits<double>::lowest() << std::endl;

	std::cout << "������������ �������� ��� long double: " << std::numeric_limits<long double>::max() << std::endl;
	std::cout << "����������� �������� ��� long double: " << std::numeric_limits<long double>::lowest() << std::endl;

	return 0;
}