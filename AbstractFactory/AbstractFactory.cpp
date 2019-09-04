#include "pch.h"
#include <iostream>

#pragma region CarFactories

class Door {
public:
	Door(){ }
	virtual void Open() = 0;
};

class GasCarDoor : public Door {
public:
	GasCarDoor() {
		std::cout << "Making a door for a gas car." << std::endl;
	}
	void Open() {
		std::cout << "click" << std::endl;
	}
};

class ElectricCarDoor : public Door {
public:
	ElectricCarDoor() {
		std::cout << "Making a door for an electric car." << std::endl;
	}
	void Open() {
		std::cout << "shhhhh" << std::endl;
	}
};

class Engine {
protected:
	char _sound[15];
public:
	Engine() {
		strcpy_s(_sound, "");
	}
	virtual void Run() = 0;
};

class GasEngine : public Engine {
public:
	GasEngine() {
		strcpy_s(_sound, "vroom");
		std::cout << "Making a gas engine." << std::endl;
	}
	void Run() {
		std::cout << _sound << std::endl;
	}
};

class ElectricEngine : public Engine {
public:
	ElectricEngine() {
		strcpy_s(_sound, "SHHHHH");
		std::cout << "Making an electric engine." << std::endl;
	}
	void Run() {
		std::cout << _sound << std::endl;
	}
};

class CarFactory {
public:
	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

class GasCarFactory : public CarFactory {
public:
	Door* BuildDoor() {
		return new GasCarDoor;
	}
	Engine* BuildEngine() {
		return new GasEngine;
	}
};

class ElectricCarFactory : public CarFactory {
public:
	Door* BuildDoor() {
		return new ElectricCarDoor;
	}
	Engine* BuildEngine() {
		return new ElectricEngine;
	}
};

#pragma endregion 

int main()
{
	CarFactory *carPlant;
	int choice;
	std::cout <<"Select a car type: " << std::endl;
	std::cout << "1: Gasoline" << std::endl;
	std::cout << "2: Electric" << std::endl;
	std::cout << "Selection: " << std::endl;
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 1:
		carPlant = new GasCarFactory;
		break;
	case 2:
		carPlant = new ElectricCarFactory;
		break;
	default:
		std::cout << "Invalid Selection" << std::endl;
		carPlant = NULL;
		break;
	}

	if (carPlant != nullptr) {
		Door *myDoor = carPlant->BuildDoor();
		Engine *myEngine = carPlant->BuildEngine();
		myDoor->Open();
		myEngine->Run();
	}

	return 0;
}