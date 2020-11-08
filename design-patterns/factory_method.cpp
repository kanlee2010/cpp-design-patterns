#include <iostream>
#include "factory_method.h"

using namespace std;

IProduct* IFactory::create(void)
{
	prepareProduct();
	IProduct *product = createProduct();
	saveProductInfo();
	return product;
}

void FactoryA::prepareProduct(void)
{
	std::cout << "FactoryA::prepareProduct\n";
}

void FactoryA::saveProductInfo(void)
{
	std::cout << "FactoryA::saveProductInfo\n";
}

IProduct* FactoryA::createProduct(void)
{
	return new ProductA;
}

void FactoryB::prepareProduct(void)
{
	std::cout << "FactoryB::prepareProduct\n";
}

void FactoryB::saveProductInfo(void)
{
	std::cout << "FactoryB::saveProductInfo\n";
}

IProduct* FactoryB::createProduct(void)
{
	return new ProductB;
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
	IProduct *product;
	FactoryA facA;
	product = facA.create();
	product->Display();
	delete product;

	FactoryB facB;
	product = facB.create();
	product->Display();
	delete product;
}