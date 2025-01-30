#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include "Student.hpp"
#include "date_s.hpp"

int main()
{
	setlocale(LC_ALL, "RU");
	Student f;
	f.setbirthDate(date(2003, 4, 30));
	f.setAverageScore(5);
	f.setGroup("23Иб1б");
	f.setName("Ilya Ivannikov");
	f.setStudentId(1);
	cout << f.toString();
	cout << "Student Age: " << f.getAge() << endl;
	

	Student f2;
	f2.setbirthDate(date(2004, 2, 12));
	f2.setAverageScore(1);
	f2.setGroup("23Иб1б");
	f2.setName("Lesha Sotnikov");
	f2.setStudentId(1);
	cout << f2.toString();
	cout << "Student Age: " << f2.getAge() << endl;
	

	Student f3;
	f3.setbirthDate(date(2002, 6, 30));
	f3.setAverageScore(5);
	f3.setGroup("23Иб1б");
	f3.setName("Daniil Vikylov");
	f3.setStudentId(1);
	cout << f3.toString();
	cout << "Student Age: " << f3.getAge() << endl;



}
