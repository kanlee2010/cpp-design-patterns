#include <iostream>
#include <vector>
#include "composite.h"


int Keyboard::getPrice(void) const
{
	return price;
}

int Keyboard::getPower(void) const
{
	return power;
}

int Monitor::getPrice(void) const
{
	return price;
}

int Monitor::getPower(void) const
{
	return power;
}

int Computer::getPrice(void) const
{
	int price = 0;
	for (ComputerDevice *dev : components) {
		price += dev->getPrice();
	}
	return price;
}

int Computer::getPower(void) const
{
	int power = 0;
	for (ComputerDevice *dev : components) {
		power += dev->getPower();
	}
	return power;
}

void composite_client(void)
{
	Keyboard *keyboard = new Keyboard(5, 2);
	Monitor *monitor = new Monitor(20, 30);

	Computer computer;
	computer.addComponent(keyboard);
	computer.addComponent(monitor);

	std::cout << "Price: " << computer.getPrice() << std::endl;
	std::cout << "Power: " << computer.getPower() << std::endl;
}
