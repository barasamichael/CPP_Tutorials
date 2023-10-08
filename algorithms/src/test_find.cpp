#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	std::vector<int> sequence(1000, 0);
	std::iota(std::begin(sequence), std::end(sequence), 0);

	// Look for 567
	auto iter = std::find(std::begin(sequence), std::end(sequence), 567);
	if (iter != std::end(sequence))
	{
		std::cout << *iter << " is present" << "\n";
	}
	else
	{
		std::cout << "567 is not present" << "\n";
	}

	// Look for -200
	iter = std::find(std::begin(sequence), std::end(sequence), -200);
	if (iter != std::end(sequence))
	{
		std::cout << *iter << " is present" << "\n";
	}
	else
	{
		std::cout << "-200 is not present" << "\n";
	}
}
