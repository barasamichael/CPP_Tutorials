# Iterators and Iterator Ranges

## Preamble
Developers of the vector class devised a way for programmers to use pointer-like 
objects to access the elements within a vector. These pointer-like objects are 
called `iterators`.

## Iterators
An __iterator__ is an object that allows a client to traverse and access 
elements of a data structure in an implementation independent way.

C++ defines two _global functions_, `std::begin` and `std::end`, that produce 
iterators to the front and back, respectively, of a data structure like a 
vector or a static array.

Containers defined in the STL provide begin and end methods that serve the same 
purpose. Functions in the standard library that accept iterators as arguments 
rather than arrays or vectors work equally well with both vectors and arrays.  
Since they accept iterator arguments, these standard functions additionally are 
able to work with other, more sophiscated data structures.

In order to behave like a pointer, an iterator object provides the following 
methods:
1. `operator *` used to access the element at the iterator's current position; 
	syntax exactly like pointer dereferencing.
2. `operator ++` used to move the iterator to the next element within the data 
	structure; syntax exactly like pointer arithmetic.
3. `operator !=` used to determine whether two iterator objects currently refer to 
	different elements within the data structure.

```cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> values {10, 20, 30, 40, 50};
	std::vector<int>::iterator iter = std::begin(values);

	// Print the element represented by pointer
	std::cout << *iter << "\n";

	// Advance pointer position
	iter++;

	// Print the element represented by pointer
	std::cout << *iter << "\n";
}
```

A simple way is to take advantage of the compiler's ability to infer the variable's
 type from its context:
```cpp
auto iter = std::begin(values);
```
While the `std::begin` function returns an iterator pointing to the first element 
in a data structure, the `std::end` function returns an iterator pointing to the 
element _just past the last element_ in the data structure.
```cpp
auto iter = std::end(values); // Result is not viable
```
Therefore, it is only useful when checking if we are past the end of our data 
structure.

The compiler internally transforms a range-based for construct into its equivalent 
`std::begin`/`std::end` form during the compilation process.
```cpp
// Range-based for construct
for (auto element : values)
{
	std::cout << element << " ";
}

// Equivalent std::begin/std::end form by the compiler
for (auto _i = std::begin(values); _i != std::end(values); _i++)
{
	std::cout << *_i << " ";
}
```

The STL supports various kinds of iterators. The kind of iterator available to 
`std::vector` objects is known as __random access__ iterator. Random access 
iterators behave like pointers. If `p` points to the _first element_ of an array:
* `p + 5` points to the _sixth element_ in the array
* `p + 0` points to the _first element_ in the array
* `p++` points to the _next element_ in the array
* `p--` moves p _backwards one position_

## Iterator Ranges
Iterators are valuable for specifying ranges over sequences. We can specify a 
range with a pair of iterators. One iterator points to the _first element_ in the 
sequence and the other iterator points to the position _just past the end_ of the 
sequence.

Suppose `values` is a vector. The two iterators `std::begin(values)` and 
`std::end(values)` span the complete range of values in `values`:
```cpp
auto beginning = std::begin(values), end = beginning + 1;
```
The range of the two iterators `beginning` and `end` includes just the first 
element in `values`.

```cpp
auto beginning = std::begin(values), end = beginning + 10;
```
The range of the two iterators `beginning` and `end` includes just first 10 
elements of `values`.

```cpp
auto end = std::end(values), beginning = end - 5;
```
The range of the two iterators `beginning` and `end` includes just last 5 
elements of `values`.  
Since iterator objects behave like pointers, we can write truly generic code 
that can process both arrays and vectors.

```cpp
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
```

### A Application Example
```cpp
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
```
This code is truly generic:
- Clients may use vectors, arrays or any other sequence type that overloads the 
	begin and end functions.
- Clients may work with sequences that contain elements of any type that supports 
	the < and = operators.
- Clients may customize the element ordering.
- Clients may customize the behaviour of the comparison and swapping procedures.
