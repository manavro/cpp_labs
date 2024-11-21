#include "Human.hpp"

using namespace std;

	void Human::setWeight(int Weight) {
		this->Weiht = Weight;
	}

	void Human::setHeight(int Height) {
		this->Height = Height;
	}

	int Human::getWeight() {

		return this->Weiht;
	}

	int Human::getHeight() {

		return this->Height;
	}

	Human::Human(string Name, int Age)
	{	
		this->Name = Name;
		this->Age = Age;
		std::cout << "Person has been created" << std::endl;
	}

	void Human::Print() {
		cout << "Name: " << Name << "\tAge: " << Age << endl;
	}
