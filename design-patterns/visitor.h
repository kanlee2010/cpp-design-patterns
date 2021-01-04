#pragma once

class Visitor;

class Element
{
protected:
	double price;
public:
	Element(double price)
	{
		this->price = price;
	}
	double getPrice(void)
	{
		return price;
	}
	virtual double accept(Visitor * v) = 0;
};

class Liquor : public Element
{
public:
	Liquor(double price) : Element(price) {}
	double accept(Visitor * v) override;
};

class Tobacco : public Element
{
public:
	Tobacco(double price) : Element(price) {}
	double accept(Visitor * v) override;
};

class Necessity : public Element
{
public:
	Necessity(double price) : Element(price) {}
	double accept(Visitor * v) override;
};

class Visitor
{
public:
	virtual double visit(Liquor &item) = 0;
	virtual double visit(Tobacco &item) = 0;
	virtual double visit(Necessity &item) = 0;
};

class TaxVisitor : public Visitor
{
public:
	double visit(Liquor &item) override;
	double visit(Tobacco &item) override;
	double visit(Necessity &item) override;
};

class TaxHolidayVisitor : public Visitor
{
public:
	double visit(Liquor &item) override;
	double visit(Tobacco &item) override;
	double visit(Necessity &item) override;
};
