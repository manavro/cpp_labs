#include <string>
#include <iostream>
using namespace std;


class Human {

private:
		int Weiht{};
		int Height{};
		int Age;
		string Name;
public:
	void setWeight(int Weight = 0);
	void setHeight(int Height = 0);
	int getWeight();
	int getHeight();
	Human(string Name = "", int Age = 0);
	void Print();
};
