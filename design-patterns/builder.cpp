#include <iostream>
#include "builder.h"

using namespace std;

IComponent* Builder::build(ComponentType compType)
{
	IComponent *comp = nullptr;
	switch (compType) {
	case COMP_A:
		comp = new ComponentA;
		break;
	case COMP_B:
		comp = new ComponentB;
		break;
	}
	return comp;
}

void ComponentA::Display(void)
{
	std::cout << "ComponentA::Display\n";
}

void ComponentB::Display(void)
{
	std::cout << "ComponentB::Display\n";
}

void builder_client(void)
{
	IComponent *comp;
	Builder build;
	comp = build.build(ComponentType::COMP_A);
	comp->Display();
	delete comp;
	comp = build.build(ComponentType::COMP_B);
	comp->Display();
	delete comp;
}