#include <iostream>
#include "decorator.h"

Decorator::Decorator(IBeverage * pBase)
{
	this->pBase = pBase;
}

int Decorator::getTotalPrice(void)
{
	return pBase->getTotalPrice();
}

int Espressor::espressoCount = 0;

Espressor::Espressor(IBeverage * pBase) : Decorator(pBase)
{
}

int Espressor::getTotalPrice(void)
{
	return Decorator::getTotalPrice() + getAddPrice();
}

int Espressor::getAddPrice(void)
{
	espressoCount += 1;
	int addPrice = 100;

	if (espressoCount > 1) {
		addPrice = 70;
	}
	return addPrice;
}

Milk::Milk(IBeverage * pBase) : Decorator(pBase)
{
}

int Milk::getTotalPrice(void)
{
	return Decorator::getTotalPrice() + 50;
}

void decorator_client(void)
{
	IBeverage *pBeverage = new Base();
	pBeverage = new Espressor(pBeverage);
	std::cout << "Espressor: " << pBeverage->getTotalPrice() << std::endl;
	pBeverage = new Milk(pBeverage);
	std::cout << "Milk: " << pBeverage->getTotalPrice() << std::endl;
}