#include <iostream>
#include "adaptor.h"


void adaptor_client(void)
{
	IAdaptor *adapt = new AdaptorImpl();

	std::cout << "twiceOf: " << adapt->twiceOf(100) << std::endl;
	std::cout << "half: " << adapt->halfOf(100) << std::endl;
}