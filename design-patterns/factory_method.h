#pragma once

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

class IFactory {
public:
	IProduct* create(void);
	virtual void prepareProduct(void) = 0;
	virtual IProduct* createProduct(void) = 0;
	virtual void saveProductInfo(void) = 0;
};

class FactoryA : public IFactory {
	void prepareProduct(void);
	IProduct* createProduct(void);
	void saveProductInfo(void);
};

class FactoryB : public IFactory {
	void prepareProduct(void);
	IProduct* createProduct(void);
	void saveProductInfo(void);
};