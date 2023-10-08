#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> sequence {10, 20, 30, 35, 40, 45, 50, 55};

	// copy the contents of the container to std::cout separating elements
	// with a single space
	auto stream = std::ostream_iterator<int> (std::cout, " ");
	std::copy(std::begin(sequence), std::end(sequence), stream);
	std::cout << "\n";
}
