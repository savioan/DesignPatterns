#include "pch.h"
#include <iostream>


class Entree {
protected:
	char _entree[10];
public:
	const char *getEntree() {
		return _entree;
	}
};

class Burger : public Entree {
public:
	Burger() {
		std::cout << "Grid Burger" << std::endl;
		strcpy_s(_entree, "Burger");
	}
};

class HotDog : public Entree {
public:
	HotDog() {
		std::cout << "HotDog" << std::endl;
		strcpy_s(_entree, "HotDog");
	}
};

class Side {
protected:
	char _side[10];
public:
	char *getSide() {
		return _side;
	}
};

class Fries : public Side {
public:
	Fries() {
		std::cout << "Fries" << std::endl;
		strcpy_s(_side, "Fries");
	}
};

class Salad : public Side {
public:
	Salad() {
		std::cout << "Salad" << std::endl;
		strcpy_s(_side, "Salad");
	}
};

class Drink {
protected:
	char _drink[10];
public:
	Drink() {
		std::cout << "Soda" << std::endl;
		strcpy_s(_drink, "Soda");
	}
	char *getDrink() {
		return _drink;
	}
};

class MealCombo {
private:
	Entree *entree;
	Side *side;
	Drink *drink;
	char _bag[100];
public:
	MealCombo(const char *type) {
		sprintf_s(_bag, "\n %s meal combo:", type);
	}
	void setEntree(Entree *e) {
		entree = e;
	}
	void setSide(Side *s) {
		side = s;
	}
	void setDrink(Drink *d) {
		drink = d;
	}
	const char *openMealBag() {
		sprintf_s(_bag, "%s %s, %s, %s", _bag, entree->getEntree(), side->getSide(), drink->getDrink());
		return _bag;
	}
};

class MealBuilder {
protected:
	MealCombo* _meal;
public:
	virtual void cookEntree() {};
	virtual void cookSide() {};
	virtual void fillDrink() {};
	MealCombo* getMeal() {
		return _meal;
	}
};

class BurgerMeal : public MealBuilder {
public:
	BurgerMeal() {
		_meal = new MealCombo("Burger");
	}
	void cookEntree() {
		Burger *burger = new Burger;
		_meal->setEntree(burger);
	}
	void cookSide() {
		Fries *fries = new Fries;
		_meal->setSide(fries);
	}
	void fillDrink() {
		Drink *drink = new Drink;
		_meal->setDrink(drink);
	}
};

class HotDogMeal : public MealBuilder {
public:
	HotDogMeal() {
		_meal = new MealCombo("HotDog");
	}
	void cookEntree() {
		HotDog *hotDog = new HotDog;
		_meal->setEntree(hotDog);
	}
	void cookSide() {
		Salad *salad = new Salad;
		_meal->setSide(salad);
	}
	void fillDrink() {
		Drink *drink = new Drink;
		_meal->setDrink(drink);
	}
};

int main()
{
	MealBuilder *cook = new MealBuilder;
	MealCombo *meal;
	int choice;

	std::cout << "Select a meal: " << std::endl;
	std::cout << "1: Hamburger meal" << std::endl;
	std::cout << "2: Hotdog meal" << std::endl;
	std::cout << "Selection: " << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		cook = new BurgerMeal;
		break;
	case 2:
		cook = new HotDogMeal;
		break;
	default:
		std::cout << "Invalid selection" << std::endl;
		cook = NULL;
		break;
	}

	std::cout << "Making selected meal" << std::endl;
	cook->cookEntree();
	cook->cookSide();
	cook->fillDrink();
	meal = cook->getMeal();
	std::cout << meal->openMealBag() << std::endl;

	return 0;
}