#include <iostream>
#include "fibonacci.h"

int  main()
{
	for (unsigned index = 0; index <= 50; index++)
	{
		std::cout << index << " : " << fibonacci(index)
			<< "    " << fibonacciTwo(index) << "\n";
	}
}
