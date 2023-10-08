#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int sum = 0;
	std::vector<int> elements {5, 22, 6, -3, 8, 4};
	std::for_each(std::begin(elements), std::end(elements), 
			[&sum] (int x) { sum += x;});
	std::cout << "The sum is " << sum << "\n";
}
