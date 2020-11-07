#include <iostream>
#include "factory_method.h"

using namespace std;

IProduct* Factory::create(ProductType prodtype)
{
	IProduct *iproduct = nullptr;
	switch (prodtype) {
	case TYPEA:
		iproduct = new ProductA;
		break;
	case TYPEB:
		iproduct = new ProductB;
		break;
	}
	return iproduct;
}

void ProductA::Display(void)
{
	std::cout << "ProductA::Display\n";
}

void ProductB::Display(void)
{
	std::cout << "ProductB::Display\n";
}

void factory_method_client(void)
{
	IProduct *iproduct;
	Factory fac;
	iproduct = fac.create(ProductType::TYPEA);
	iproduct->Display();
	delete iproduct;
	iproduct = fac.create(ProductType::TYPEB);
	iproduct->Display();
	delete iproduct;
}