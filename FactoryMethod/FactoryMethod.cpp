#include "pch.h"
#include <iostream>


class Coffee {
protected:
	char _type[15];
public:
	char * getType() {
		return _type;
	}
};

class Espresso : public Coffee {
public:
	Espresso() : Coffee() {
		strcpy_s(_type, "Espresso");
		std::cout << "Making a cup of Espresso" << std::endl;
	}
};

class Cappuccino : public Coffee {
public:
	Cappuccino() : Coffee() {
		strcpy_s(_type, "Cappuccino");
		std::cout << "Making a cup of Cappuccino" << std::endl;
	}
};

class CoffeeMakerFactory {
private:
	Coffee *_coffee;
public:
	Coffee * GetCoffee() {
		int choice;
		std::cout << "Select type of coffee to make: " << std::endl;
		std::cout << "1: Espresso" << std::endl;
		std::cout << "2: Cappuccino" << std::endl;
		std::cout << "Selection:" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			return new Espresso;
		case 2:
			return new Cappuccino;
		default:
			std::cout << "Invalid Selection" << std::endl;
			return NULL;
		}
	}
};

int main()
{
	CoffeeMakerFactory coffeeMachine;
	Coffee *cup;
	cup = coffeeMachine.GetCoffee();
	if (cup != nullptr) {
		std::cout << std::endl << "You had asked for a(n) " << cup->getType() << std::endl;
	}

	return 0;
}