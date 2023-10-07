#include <iostream>
#include <vector>


void print(const std::vector<int>& values, int increment)
{
	for (auto iter = std::begin(values); iter != std::end(values); 
			iter += increment)
	{
		std::cout << *iter << "\n";
	}
	std::cout << "\n";
}


void print_reverse(const std::vector<int>& values, int decrement)
{
	auto iter = std::end(values);
	while (iter != std::begin(values))
	{
		iter -= decrement;
		std::cout << *iter << " ";
	}
	std::cout << "\n";
}


int main()
{
	std::vector<int> values(20);
	for (int index = 0; index < 20; index++)
	{
		values[index] = index;
	}

	print(values, 1);
	print(values, 2);
	print(values, 3);
	//print(values, 5); /* RESULTED IN SEGMENTATION FAULT: "INVESTIGATING" */

	std::cout << "\n";
	print_reverse(values, 4);
	print_reverse(values, 1);
	print_reverse(values, 2);
}
