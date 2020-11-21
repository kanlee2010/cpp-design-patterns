#include <iostream>
#include "bridge.h"

void RedColor::applyColor(void)
{
	std::cout << "red\n";
}

void GreenColor::applyColor(void)
{
	std::cout << "greeen\n";
}

void Triangle::applyColor(void)
{
	std::cout << "Triangle filled with color ";
	color->applyColor();
}

void Pentagon::applyColor(void)
{
	std::cout << "Pentagon filled with color ";
	color->applyColor();
}

void bridge_client(void)
{
	Shape *tri = new Triangle(new RedColor);
	tri->applyColor();
	delete tri;

	Shape *pent = new Pentagon(new GreenColor);
	pent->applyColor();
	delete pent;
}