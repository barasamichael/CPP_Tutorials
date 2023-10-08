#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> sequence {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	auto output = std::ostream_iterator<int> (std::cout, " ");

	// Display sequence
	std::copy(std::begin(sequence), std::end(sequence), output);
	std::cout << "\n";

	// A function to test for evenness
	auto is_even = [] (int x) { return x % 2 == 0; };
	int even_count = std::count_if(std::begin(sequence), std::end(sequence), 
			is_even);

	// Populate second sequence with even values
	std::vector<int> sequenceTwo(even_count);
	std::copy_if(std::begin(sequence), std::end(sequence), 
			std::begin(sequenceTwo), is_even);
	
	// Display sequence with even numbers
	std::copy(std::begin(sequenceTwo), std::end(sequenceTwo), output);
	std::cout << "\n";
}
