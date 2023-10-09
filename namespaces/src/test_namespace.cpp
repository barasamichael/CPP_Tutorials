#include <iostream>
#include "vecutils.h"

int main()
{
	std::cout << std::boolalpha << vecutils::is_sorted({1, 2, 3, 4, 5})
		<< "\n";
	std::cout << std::boolalpha << vecutils::is_sorted({5, 4, 3, 2, 1})
		<< "\n";
	std::cout << "---------------\n";
	std::cout << vecutils::max({1, 2, 3, 4, 5}) << "\n";
	std::cout << vecutils::max({5, 5, 5, 5, 5}) << "\n";
}
