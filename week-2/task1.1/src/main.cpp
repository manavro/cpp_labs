#include "Human.hpp"
#include <iostream>

using namespace std;

int main (){

	Human First("Nikita", 16);
	First.Print();
	First.setWeight(67);
	First.setHeight(180);

	cout << "Height: " << First.getHeight() << endl;
	cout << "Weight: " << First.getWeight() << endl;


	Human Second("Ilya", 21);
	Second.Print();
	Second.setWeight(90);
	Second.setHeight(200);

	cout << "Height: " << Second.getHeight() << endl;
        cout << "Weight: " << Second.getWeight() << endl;

}
