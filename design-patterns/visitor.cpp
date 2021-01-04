#include <iostream>
#include "visitor.h"

double Liquor::accept(Visitor *v)
{
	return v->visit(*this);
}

double Tobacco::accept(Visitor *v)
{
	return v->visit(*this);
}

double Necessity::accept(Visitor *v)
{
	return v->visit(*this);
}

double TaxVisitor::visit(Liquor &item)
{
	std::cout << "Liquor: Price with Tax" << std::endl;
	return 0.18 * item.getPrice() + item.getPrice();
}

double TaxVisitor::visit(Tobacco &item)
{
	std::cout << "Tabacco: Price with Tax" << std::endl;
	return 0.32 * item.getPrice() + item.getPrice();
}

double TaxVisitor::visit(Necessity &item)
{
	std::cout << "Necessity: Price with Tax" << std::endl;
	return 0.0 * item.getPrice() + item.getPrice();
}

double TaxHolidayVisitor::visit(Liquor &item)
{
	std::cout << "Liquor: Price with Tax" << std::endl;
	return 0.10 * item.getPrice() + item.getPrice();
}

double TaxHolidayVisitor::visit(Tobacco &item)
{
	std::cout << "Tabacco: Price with Tax" << std::endl;
	return 0.30 * item.getPrice() + item.getPrice();
}

double TaxHolidayVisitor::visit(Necessity &item)
{
	std::cout << "Necessity: Price with Tax" << std::endl;
	return 0.0 * item.getPrice() + item.getPrice();
}

void visitor_client(void) {
	TaxVisitor *taxCalc = new TaxVisitor;
	TaxHolidayVisitor *taxHolidayCalc = new TaxHolidayVisitor;

	Necessity *milk = new Necessity(3.47);
	Liquor *vodka = new Liquor(11.99);
	Tobacco *cigar = new Tobacco(19.99);

	std::cout << milk->accept(taxCalc) << std::endl;
	std::cout << vodka->accept(taxCalc) << std::endl;
	std::cout << cigar->accept(taxCalc) << std::endl;

	std::cout << "TAX HOLIDAY PRICES" << std::endl;
	std::cout << milk->accept(taxHolidayCalc) << std::endl;
	std::cout << vodka->accept(taxHolidayCalc) << std::endl;
	std::cout << cigar->accept(taxHolidayCalc) << std::endl;
}