#include <iostream>
#include <vector>
#include <string>

#include "generic_comparer.h"

template <typename Type>
void selection_sort(std::vector<Type>& values, Comparer<Type>& comparer)
{
	int size = values.size();
	for (int i = 0; i < size - 1; i++)
	{
		int small = i;
		for (int j = i + 1; j < size; j++)
		{
			if (comparer.compare(values[j], values[small]))
			{
				small = j;
			}
		}

		if (i != small)
		{
			comparer.swap(values[i], values[small]);
		}
	}
}

template<typename Type>
std::ostream& operator<<(std::ostream& os, const std::vector<Type>& values)
{
	int size = values.size();
	os << "{ ";
	if (size > 0)
	{
		os << values[0];
		for (int i = 1; i < size; i++)
		{
			os << ", " << values[i];
		}
	}
	os << " }";
	return os;
}


template <typename Type>
bool greater_than(const Type& value_one, const Type& value_two)
{
	return value_one > value_two;
}


template <typename Type>
bool less_than(const Type& value_one, const Type& value_two)
{
	return value_one < value_two;
}


int main()
{
	Comparer<int> less_than_comparer(less_than<int>);
	Comparer<int> greater_than_comparer(greater_than<int>);
	std::vector<int> original {23, -3, 4, 215, 0, -3, 2, 23, 100, 88, -10};
	
	/* Make a copy of the original vector */
	std::vector<int> working = original;
	std::cout << "Before: ";
	std::cout << working << std::endl;

	selection_sort(working, less_than_comparer);
	std::cout << "Ascending: ";
	std::cout << working << std::endl;
	std::cout << "( " << less_than_comparer.comparisons() << " comparisons, "
		<< less_than_comparer.swaps() << " swaps)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	/* Make another copy of the original vector */
	working = original;
	std::cout << "Before: ";
	std::cout << working << std::endl;

	selection_sort(working, greater_than_comparer);
	std::cout << "Ascending: ";
	std::cout << working << std::endl;
	std::cout << "( " << greater_than_comparer.comparisons() << " comparisons, "
		<< greater_than_comparer.swaps() << " swaps)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
}
