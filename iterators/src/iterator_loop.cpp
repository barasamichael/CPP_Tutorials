#include <iostream>
#include <vector>

int main()
{
	std::vector<int> values {10, 20, 30, 40, 50};

	for (auto iter = std::begin(values); iter != std::end(values); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}
