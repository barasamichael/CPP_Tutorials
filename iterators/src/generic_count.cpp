#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>

using Iterator = std::vector<int>::iterator;

/**
 * Count the elements in a vactor of integers that match seek
 * Type Iterator is an iterator type working with a container that contains
 * elements of type Type. Type Type elements must be compatible with
 * operator==
 */
	template <typename Iterator, typename Type>
int count_value(Iterator iterator_begin, Iterator iterator_end, const Type& seek)
{
	int count = 0;
	for (auto cursor = iterator_begin; cursor != iterator_end;
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
	std::cout << "----------------- Vector of Integers  ------------------\n";
	std::vector<int> values {34, 5, 12, 5, 8, 5, 11, 2};
	std::cout << count_value(std::begin(values), std::end(values), 5) << "\n";
	values = {};
	std::cout << count_value(std::begin(values), std::end(values), 5) << "\n";
	std::cout << count_value(std::begin(values), std::end(values), 8) << "\n";

	std::cout << "---------------- STL array of integers -----------------\n";
	std::array<int, 8> ages {34, 5, 12, 5, 8, 5, 11, 2};
	std::cout << count_value(std::begin(ages), std::end(ages), 5) << "\n";
	ages = {};
	std::cout << count_value(std::begin(ages), std::end(ages), 5) << "\n";
	std::cout << count_value(std::begin(ages), std::end(ages), 8) << "\n";

	std::cout << "------------- Primitive C array of integers ------------\n";
	int apples[] = {34, 5, 12, 5, 8, 5, 11, 2};
	std::cout << count_value(std::begin(apples), std::end(apples), 5) << "\n";

	std::cout << "----------------- Vector of Strings --------------------\n";
	std::vector<std::string> tokens {"mae", "al", "pat", "mel", "al", "ray",
		"al"};
	std::cout << count_value(std::begin(tokens), std::end(tokens), "al")
		<< "\n";

	std::cout << "--------------- Linked List of Strings ----------------\n";
	std::list<std::string> words {"mae", "al", "pat", "mel", "al", "ray",
		"al"};
	std::cout << count_value(std::begin(words), std::end(words), "al")
		<< "\n";
	
	std::cout << "------------ Primitive C array of Points ---------------\n";
	struct Point
	{
		int x;
		int y;

		bool operator==(const Point& other)
		{
			return x == other.x && y == other.y;
		}
	};

	Point points[] = {{5, 3}, {0, 0}, {3, 5}, {5, 3}, {2, 1}};
	std::cout << count_value(std::begin(points), std::end(points), 
			Point {5, 3}) << "\n";
	std::cout << count_value(std::begin(points), std::end(points), 
			Point {3, 5}) << "\n";
	std::cout << count_value(std::begin(points), std::end(points), 
			Point {5, 3}) << "\n";

}
