#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> sequence {2, 3, 4, 5, 6};
	std::for_each(std::begin(sequence), std::end(sequence),
			[] (int x) {std::cout << x << " ";});
	std::cout << "\n";

	// Make a copy of sequence with the first and last elements trimmed off
	if (sequence.size() >= 2)
	{
		std::vector<int> sequenceTwo(sequence.size() - 2);
		std::copy(std::begin(sequence) + 1, std::end(sequence) - 1,
				std::begin(sequenceTwo));

		std::for_each(std::begin(sequenceTwo), std::end(sequenceTwo),
				[] (int x) {std::cout << x << " ";});
		std::cout << "\n";
	}
}
