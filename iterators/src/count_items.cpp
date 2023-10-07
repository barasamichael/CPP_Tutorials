#include <iostream>
#include <vector>

using Iterator = std::vector<int>::iterator;

/**
 * Count the elements in a vactor of integers that match seek
 */
int count_value(Iterator iterator_begin, Iterator iterator_end, int seek)
{
	int count = 0;
	for (Iterator cursor = iterator_begin; cursor != iterator_end; 
			cursor++)
	{
		if (*cursor == seek)
		{
			count++;
		}
	}
	return count;
}


int main()
{
	std::vector<int> values {34, 5, 12, 5, 8, 11, 2};
	std::cout << count_value(std::begin(values), std::end(values), 5) << "\n";
	std::cout << count_value(std::begin(values), std::end(values), 12) << "\n";
	std::cout << count_value(std::begin(values), std::end(values), 13) << "\n";
	std::cout << count_value(std::begin(values), std::end(values), 5) << "\n";
}
