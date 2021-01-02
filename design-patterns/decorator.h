#pragma once

class IBeverage
{
public:
	virtual int getTotalPrice(void) = 0;
};

class Base : public IBeverage
{
public:
	int getTotalPrice(void) { return 0; }
};

class Decorator : public IBeverage
{
private:
	IBeverage *pBase;
public:
	Decorator(IBeverage *pBase);
	int getTotalPrice(void);
};

class Espressor : public Decorator
{
private:
	static int espressoCount;

public:
	Espressor(IBeverage *pBase);
	int getTotalPrice(void) override;
	int getAddPrice(void);
};

class Milk : public Decorator
{
public:
	Milk(IBeverage *pBase);
	int getTotalPrice(void) override;
};