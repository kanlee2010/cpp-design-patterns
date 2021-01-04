// design-patterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

extern void strategy_client(void);
extern void adaptor_client(void);
extern void template_method_client(void);
extern void factory_method_client(void);
extern void builder_client(void);
extern void abstract_factory_client(void);
extern void bridge_client(void);
extern void composite_client(void);
extern void decorator_client(void);
extern void visitor_client(void);

int main()
{
	strategy_client();
	adaptor_client();
	template_method_client();
	factory_method_client();
	builder_client();
	abstract_factory_client();
	bridge_client();
	composite_client();
	decorator_client();
	visitor_client();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
