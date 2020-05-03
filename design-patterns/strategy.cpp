#include <iostream>
#include "strategy.h"

using namespace std;
void StrategyImplA::Display(void)
{
	cout << "ImpleA" << endl;
}

void StrategyImplB::Display(void)
{
	cout << "ImpleB" << endl;
}

StrategyContainer::StrategyContainer()
{
	m_ifstr = NULL;
}

void StrategyContainer::SetStrategy(class IStrategy *i)
{
	m_ifstr = i;
}

void StrategyContainer::Display(void)
{
	if (NULL == m_ifstr) {
		cout << "No Impl" << endl;
		return;
	}
	m_ifstr->Display();
}