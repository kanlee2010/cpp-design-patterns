#pragma once

enum ProductType {TYPEA, TYPEB};

class IProduct
{
public:
	virtual void Display(void) = 0;
};

class ProductA : public IProduct {
public:
	void Display(void);
};

class ProductB : public IProduct {
public:
	void Display(void);
};

class Factory {
public:
	Factory() {}
	IProduct* create(ProductType prodtype);
};