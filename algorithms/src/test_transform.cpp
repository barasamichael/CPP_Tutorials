#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	const int SIZE = 20;
	std::vector<int> sequence(SIZE);

	// Populate the vector with 0, 1, 2, 3, ..., SIZE - 1
	std::iota(std::begin(sequence), std::end(sequence), 0);

	// Display the vector
	std::for_each(std::begin(sequence), std::end(sequence), 
			[] (int x) {std::cout << x << " ";});
	std::cout << "\n";

	// Make a vector large enough to hold the copied values
	std::vector<int> sequenceTwo(SIZE);
	std::copy(std::begin(sequence), std::end(sequence), 
			std::begin(sequenceTwo));

	// Display sequenceTwo
	std::for_each(std::begin(sequenceTwo), std::end(sequenceTwo), 
			[] (int x) {std::cout << x << " ";});
	std::cout << "\n";

	std::vector<int> sequenceThree(SIZE);
	// Copy sequence to sequenceThree
	std::transform(std::begin(sequence), std::end(sequence), 
			std::begin(sequenceThree), 
			[] (int x) {return 2 * x;});
	
	// Display sequenceThree
	std::for_each(std::begin(sequenceThree), std::end(sequenceThree), 
			[] (int x) {std::cout << x << " ";});
	std::cout << "\n";

}
