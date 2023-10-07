#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>


template <typename Type>
class Comparer
{
	int compareCount;
	int swapCount;

	bool (*comparer) (const Type&, const Type&);

	protected:
	virtual bool compareImplementation(const Type& valueOne, 
			const Type& valueTwo);
	virtual void swapImplementation(Type& valueOne, Type& valueTwo);

	public:
	Comparer(bool (*comparer) (const Type&, const Type&));
	void reset();
	bool compare(const Type& valueOne, const Type& valueTwo);
	void swap(Type& valueOne, Type& valueTwo);
	int getComparisons () const;
	int getSwaps() const;
};


template <typename Type>
bool Comparer<Type>::compareImplementation(const Type& valueOne, 
		const Type& valueTwo)
{
	return comparer(valueOne, valueTwo);
}


template <typename Type>
void Comparer<Type>::swapImplementation(Type& valueOne, Type& valueTwo)
{
	Type temp = valueOne;
	valueOne = valueTwo;
	valueTwo = temp;
}


template <typename Type>
Comparer<Type>::Comparer(bool (*comparer) (const Type&, const Type&)) :
	compareCount(0), swapCount(0), comparer(comparer){}


template <typename Type>
void Comparer<Type>::reset()
{
	compareCount = swapCount = 0;
}


template <typename Type>
void Comparer<Type>::swap(Type& valueOne, Type& valueTwo)
{
	compareCount++;
	return swapImplementation(valueOne, valueTwo);
}


template <typename Type>
bool Comparer<Type>::compare(const Type& valueOne, const Type& valueTwo)
{
	compareCount++;
	return compareImplementation(valueOne, valueTwo);
}


template <typename Type>
int Comparer<Type>::getSwaps() const 
{
	return swapCount;
}


template <typename Type>
int Comparer<Type>::getComparisons() const 
{
	return compareCount;
}


template <typename Type, typename Vype>
void selection_sort(const Type begin, const Type end, Comparer<Vype>& comparer)
{
	for (auto index = begin; index != end; index++)
	{
		// small is the position of the smallest value we have seen
		auto small = index;
		for (auto j = index + 1; j != end; j++)
		{
			if (comparer.compare(*j, *small))
			{
				// We just found a smaller value
				small = j;
			}
		}

		// Swap a[index] and a[small], if smaller value was found
		if (index != small)
		{
			comparer.swap(*index, *small);
		}
	}
}


template <typename Type>
void print(const Type begin, const Type end)
{
	std::cout << "{ ";
	if (begin != end)
	{
		Type iterator = begin;
		std::cout << *iterator;
		iterator++;
		while (iterator != end)
		{
			std::cout << ", " << *iterator;
			iterator++;
		}
	}
	std::cout << " }";
}


template <typename Type>
bool less_than(const Type& valueOne, const Type& valueTwo)
{
	return valueOne < valueTwo;
}


template <typename Type>
bool greater_than(const Type& valueOne, const Type& valueTwo)
{
	return valueOne > valueTwo;
}


template<typename Type>
class LogComparer : public Comparer<Type>
{
	std::ofstream fout;

	protected:
	bool compareImplementation(const Type& valueOne, const Type& valueTwo) 
		override;
	void swapImplementation(Type& valueOne, Type& valueTwo) override;

	public:
	LogComparer(bool (*comparer) (const Type&, const Type&), 
			const std::string& filename);
	~LogComparer();
};


template <typename Type>
bool LogComparer<Type>::compareImplementation(const Type& valueOne, 
		const Type& valueTwo)
{
	fout << "Comparing " << valueOne << " to " << valueTwo << "\n";
	return Comparer<Type>::compareImplementation(valueOne, valueTwo);
}


template <typename Type>
void LogComparer<Type>::swapImplementation(Type& valueOne, Type& valueTwo)
{
	fout << "Swapping " << valueOne << " and " << valueTwo << "\n";
	Comparer<Type>::swapImplementation(valueOne, valueTwo);
}


template <typename Type>
LogComparer<Type>::LogComparer(bool (*comparer)(const Type&, const Type&), 
		const std::string& filename) : 
	Comparer<Type> (comparer)
{
	fout.open(filename);
	if (!fout.good())
	{
		std::cout << "Could not open log file " << filename << 
			" for working\n";
		exit(1);
	}
	/**
	 * NOTE:
	 * 	`fout` is an instance variable, not a local variable
	 * 	So the file stays open when the constructor finishes
	 */
}

template <typename Type>
LogComparer<Type>::~LogComparer(){}

int main()
{
	// Vector of integers
	std::vector<int> values = {23, -3, 10, 4, 215, 0, -3, 2};
	
	std::cout << "======================================================\n";
	std::cout << "Before: ";
	print(std::begin(values), std::end(values));
	std::cout << "\n";

	std::cout << "------------------------------------------------------\n";
	LogComparer<int> lt(less_than<int>, "upsort.log");
	selection_sort(std::begin(values), std::end(values), lt);
	std::cout << "Ascending: ";
	print(std::begin(values), std::end(values));
	std::cout << "\n";
	std::cout << "(" << lt.getComparisons() << " comparisons," 
		<< lt.getSwaps() << " swaps)\n";
	
	std::cout << "------------------------------------------------------\n";
	LogComparer<int> gt(greater_than<int>, "downsort.log");
	selection_sort(std::begin(values), std::end(values), gt);
	std::cout << "Descending: ";
	print(std::begin(values), std::end(values));
	std::cout << "\n";
	std::cout << "(" << gt.getComparisons() << " comparisons," 
		<< gt.getSwaps() << " swaps)\n";
	std::cout << "======================================================\n";

	// Vector of strings
	std::vector<std::string> words {"tree", "girl", "boy", "dog", "cat", 
		"girl", "bird"};
	std::cout << "Before: ";
	print(std::begin(words), std::end(words));
	std::cout << "\n";

	std::cout << "------------------------------------------------------\n";
	LogComparer<std::string> words_lt(less_than<std::string>, "upwords.log");
	selection_sort(std::begin(words), std::end(words), words_lt);
	std::cout << "Ascending: ";
	print(std::begin(words), std::end(words));
	std::cout << "\n";
	std::cout << "( " << words_lt.getComparisons() << " comparisons," 
		<< words_lt.getSwaps() << " swaps)\n";
	
	std::cout << "------------------------------------------------------\n";
	LogComparer<std::string> words_gt(greater_than<std::string>, 
			"downwords.log");
	selection_sort(std::begin(words), std::end(words), words_gt);
	std::cout << "Descending: ";
	print(std::begin(words), std::end(words));
	std::cout << "\n";
	std::cout << "( " << words_gt.getComparisons() << " comparisons," 
		<< words_gt.getSwaps() << " swaps)\n";
	std::cout << "======================================================\n";
}
