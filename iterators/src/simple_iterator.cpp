#include <iostream>
#include <vector>

int main()
{
	std::vector<int> values {10, 20, 30, 40, 50};
	std::vector<int>::iterator iter = std::begin(values);

	// Print the element represented by pointer
	std::cout << *iter << "\n";

	// Advance pointer position
	iter++;

	// Print the element represented by pointer
	std::cout << *iter << "\n";
}
