#include "pch.h"
#include <iostream>

class Animal {
protected:
	char _hairColor[10];
	int _hairLength, _tail, _weight, _height, _age;
	int _intelligence, _stubborness, _agressiveness;
public:
	virtual Animal *clone() = 0;
	void setHairLength(int length) {
		_hairLength = length;
	}
	void setHairColor(const char *color) {
		strcpy_s(_hairColor, color);
	}
	void setTail(int length) {
		_tail = length;
	}
	void setWeight(int kg) {
		_weight = kg;
	}
	void setHeight(int m) {
		_height = m;
	}
	void setAge(int age) {
		_age = age;
	}
};

class Sheep : public Animal {
public:
	Sheep() {
		_hairLength = 5;
		_stubborness = 3;
		_agressiveness = 2;
		_intelligence = 7;
	}
	Sheep *clone() {
		return new Sheep(*this);
	}
	void shearing() {
		_hairLength -= 2;
	}
};

class Cow : public Animal {
public:
	Cow() {
		_stubborness = 6;
		_agressiveness = 5;
		_intelligence = 8;
	}
	Cow *clone() {
		return new Cow(*this);
	}
};


int main()
{
	Sheep *sheep0 = new Sheep;
	sheep0->setHairColor("White");
	sheep0->setTail(5);
	sheep0->setWeight(90);
	sheep0->setHeight(1);
	sheep0->setAge(5);

	Cow *cow0 = new Cow;
	cow0->setHairColor("Brown");
	cow0->setTail(20);
	cow0->setWeight(790);
	cow0->setHeight(2);
	cow0->setAge(8);

	Animal *farm[3];

	farm[0] = sheep0->clone();
	farm[1] = cow0->clone();

	farm[0]->setWeight(1000);
	sheep0->shearing();

	farm[2] = sheep0->clone();

	return 0;
}