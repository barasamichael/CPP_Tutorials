# Algorithms of the Standard Library

## Preamble
The flexible design of the STL containers and their iterators make possible the STL's generic algorithms.  
The algorithms provided by the STL are powerful and flexible, but they are somewhat arcane and can be difficult to use for casual C++ programmers. 
The STL algorithms are best viewed as the building blocks for more specific tasks required by applications.  

In order to use the STL algorithms one must include the following preprocessor directive:
```cpp
#include <algorithm>
```

## Tabular Summary of Common Standard Library Algorithms
Here's a table grouping the functions by their respective libraries, along with the header file to be imported and an explanation of each function:

**Algorithm Library:**

| Function Name      | Header File         | Explanation                                                                                    |
|--------------------|---------------------|------------------------------------------------------------------------------------------------|
| for_each           | `<algorithm>`       | `std::for_each(Iterator first, Iterator last, UnaryFunction f)` - Applies the given function `f` to each element in the range `[first, last)`.             |
| iota               | `<numeric>`         | `std::iota(ForwardIterator first, ForwardIterator last, T value)` - Fills a range with a series of incrementing values starting from `value`.             |
| find               | `<algorithm>`       | `std::find(Iterator first, Iterator last, const T& value)` - Searches for the first occurrence of `value` in the range `[first, last)`.                |
| copy               | `<algorithm>`       | `std::copy(InputIterator first, InputIterator last, OutputIterator result)` - Copies elements from one range to another.                                  |
| transform          | `<algorithm>`       | `std::transform(InputIterator first1, InputIterator last1, InputIterator first2, OutputIterator result, BinaryOperation binary_op)` - Applies a binary operation to corresponding elements in two ranges and stores the result in a third range. |
| accumulate         | `<numeric>`         | `std::accumulate(InputIterator first, InputIterator last, T init)` - Computes the sum of elements in the given range, optionally with an initial value.   |

**Iterator Library:**

| Function Name      | Header File         | Explanation                                                                                    |
|--------------------|---------------------|------------------------------------------------------------------------------------------------|
| ostream_iterator   | `<iterator>`        | `std::ostream_iterator<T>` - An iterator that writes elements to an output stream. Used with `std::copy` or `std::transform` for output.              |

**Numeric Library:**

| Function Name      | Header File         | Explanation                                                                                    |
|--------------------|---------------------|------------------------------------------------------------------------------------------------|
| count              | `<algorithm>`       | `std::count(InputIterator first, InputIterator last, const T& value)` - Counts the occurrences of `value` in the range `[first, last)`.            |
| count_if           | `<algorithm>`       | `std::count_if(InputIterator first, InputIterator last, UnaryPredicate pred)` - Counts the elements in the range `[first, last)` that satisfy the given predicate. |
| accumulate         | `<numeric>`         | (Already mentioned in Algorithm Library)                                                     |
| partial_sum        | `<numeric>`         | `std::partial_sum(InputIterator first, InputIterator last, OutputIterator result)` - Computes the partial sum of elements in the given range.     |
| inner_product      | `<numeric>`         | `std::inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init)` - Computes the inner product of two ranges.        |

**Container Library:**

| Function Name      | Header File         | Explanation                                                                                    |
|--------------------|---------------------|------------------------------------------------------------------------------------------------|
| copy_if            | `<algorithm>`       | `std::copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred)` - Copies elements from one range to another, but only if they satisfy the given predicate. |
| shuffle            | `<algorithm>`       | `std::shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator&& g)` - Randomly shuffles the elements in the range `[first, last)`. |
| generate           | `<algorithm>`       | `std::generate(ForwardIterator first, ForwardIterator last, Generator g)` - Generates values for a range using a generator function `g`.             |
| partition          | `<algorithm>`       | `std::partition(BidirectionalIterator first, BidirectionalIterator last, UnaryPredicate pred)` - Divides a range into two groups based on a predicate.    |
| remove             | `<algorithm>`       | `std::remove(ForwardIterator first, ForwardIterator last, const T& value)` - Removes all occurrences of `value` from the range `[first, last)`.        |
| remove_if          | `<algorithm>`       | `std::remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)` - Removes elements from the range `[first, last)` that satisfy the given predicate. |
| reverse            | `<algorithm>`       | `std::reverse(BidirectionalIterator first, BidirectionalIterator last)` - Reverses the order of elements in the range `[first, last)`.                |

**Predicate Library:**

| Function Name      | Header File         | Explanation                                                                                    |
|--------------------|---------------------|------------------------------------------------------------------------------------------------|
| all_of             | `<algorithm>`       | `std::all_of(InputIterator first, InputIterator last, UnaryPredicate pred)` - Checks if all elements in the range `[first, last)` satisfy the given predicate. |
| none_of            | `<algorithm>`       | `std::none_of(InputIterator first, InputIterator last, UnaryPredicate pred)` - Checks if none of the elements in the range `[first, last)` satisfy the given predicate. |
| any_of             | `<algorithm>`       | `std::any_of(InputIterator first, InputIterator last, UnaryPredicate pred)` - Checks if at least one element in the range `[first, last)` satisfies the given predicate. |
| find_if            | `<algorithm>`       | (Already mentioned in Algorithm Library)                                                     |


## Standalone Overview of Standard Library Algorithms
**Algorithm:** for_each  
```cpp
template <class InputIterator, class Function>
Function std::for_each(InputIterator first, InputIterator last, Function func);
```
**Explanation:** `for_each` applies the function `func` to each element in the range [first, last). It can be used to perform an operation on each element in a container without the need for an explicit loop.

---

**Algorithm:** iota  
```cpp
template <class ForwardIterator, class T>
void std::iota(ForwardIterator first, ForwardIterator last, T value);
```
**Explanation:** `iota` assigns consecutive values to a range of elements, starting from the given `value` and incrementing it for each element in the range. It is useful for initializing sequences with incremental values.

---

**Algorithm:** find  
```cpp
template <class InputIterator, class T>
InputIterator std::find(InputIterator first, InputIterator last, const T& value);
```
**Explanation:** `find` searches for the first occurrence of `value` in the range [first, last) and returns an iterator to that element. If the element is not found, it returns `last`.

---

**Algorithm:** copy  
```cpp
template <class InputIterator, class OutputIterator>
OutputIterator std::copy(InputIterator first, InputIterator last, OutputIterator result);
```
**Explanation:** `copy` copies elements from the input range [first, last) to the output range starting from `result`. It is often used to duplicate or transfer elements between containers.

---

**Algorithm:** transform  
```cpp
template <class InputIterator, class OutputIterator, class UnaryOperation>
OutputIterator std::transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op);
```
**Explanation:** `transform` applies the unary operation `op` to each element in the input range [first1, last1) and stores the results in the output range starting from `result`. It is used for element-wise transformations.

---

**Algorithm:** ostream_iterator  
```cpp
template <class T, class CharT = char, class Traits = std::char_traits<CharT>>
class std::ostream_iterator;
```
**Explanation:** `ostream_iterator` is an output iterator that writes values of type `T` to an output stream (e.g., `std::cout`) using the `<<` operator. It is often used for easy output to streams.

---

**Algorithm:** count  
```cpp
template <class InputIterator, class T>
typename std::iterator_traits<InputIterator>::difference_type
std::count(InputIterator first, InputIterator last, const T& value);
```
**Explanation:** `count` counts the number of occurrences of `value` in the range [first, last) and returns the count as a result.

---

**Algorithm:** count_if  
```cpp
template <class InputIterator, class UnaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type
std::count_if(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `count_if` counts the number of elements in the range [first, last) that satisfy the unary predicate `pred` and returns the count as a result.

---

**Algorithm:** copy_if  
```cpp
template <class InputIterator, class OutputIterator, class UnaryPredicate>
OutputIterator std::copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred);
```
**Explanation:** `copy_if` copies elements from the input range [first, last) to the output range starting from `result` if they satisfy the unary predicate `pred`. It is used to selectively copy elements based on a condition.

---

**Algorithm:** shuffle  
```cpp
template <class RandomAccessIterator, class RandomNumberGenerator>
void std::shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator&& g);
```
**Explanation:** `shuffle` randomly reorders elements in the range [first, last) using the provided random number generator `g`. It is useful for generating random permutations of elements.

---

**Algorithm:** generate  
```cpp
template <class ForwardIterator, class Generator>
void std::generate(ForwardIterator first, ForwardIterator last, Generator gen);
```
**Explanation:** `generate` assigns values generated by the `gen` function to each element in the range [first, last). It is used to fill a range with generated values.

---

**Algorithm:** accumulate  
```cpp
template <class InputIterator, class T>
T std::accumulate(InputIterator first, InputIterator last, T init);
```
**Explanation:** `accumulate` computes the sum of all elements in the range [first, last) starting from an initial value `init` and returns the result.

---

**Algorithm:** partition  
```cpp
template <class ForwardIterator, class UnaryPredicate>
ForwardIterator std::partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
```
**Explanation:** `partition` reorders the elements in the range [first, last) in such a way that all elements for which the unary predicate `pred` returns `true` come before those for which it returns `false`. It returns an iterator to the first element of the second partition.

---

**Algorithm:** remove  
```cpp
template <class ForwardIterator, class T>
ForwardIterator std::remove(ForwardIterator first, ForwardIterator last, const T& value);
```
**Explanation:** `remove` removes all elements with the value `value` from the range [first, last) by shifting the remaining elements to fill the removed positions. It returns an iterator to the new end of the range.

---

**Algorithm:** remove_if  
```cpp
template <class ForwardIterator, class UnaryPredicate>
ForwardIterator std::remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
```
**Explanation:** `remove_if` removes all elements from the range [first, last) that satisfy the unary predicate `pred` by shifting the remaining elements to fill the removed positions. It returns an iterator to the new end of the range.

---

**Algorithm:** reverse  
```cpp
template <class BidirectionalIterator>
void std::reverse(BidirectionalIterator first, BidirectionalIterator last);
```
**Explanation:** `reverse` reverses the order of elements in the range [first, last). It is used to reverse the contents of a container or a portion of it.

---

**Algorithm:** all_of  
```cpp
template <class InputIterator, class UnaryPredicate>
bool std::all_of(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `all_of` checks if the unary predicate `pred` returns `true` for all elements in the range [first, last). It returns `true` if all elements satisfy the predicate

; otherwise, it returns `false`.

---

**Algorithm:** none_of  
```cpp
template <class InputIterator, class UnaryPredicate>
bool std::none_of(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `none_of` checks if the unary predicate `pred` returns `false` for all elements in the range [first, last). It returns `true` if none of the elements satisfy the predicate; otherwise, it returns `false`.

---

**Algorithm:** any_of  
```cpp
template <class InputIterator, class UnaryPredicate>
bool std::any_of(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `any_of` checks if the unary predicate `pred` returns `true` for at least one element in the range [first, last). It returns `true` if any element satisfies the predicate; otherwise, it returns `false`.

---

**Algorithm:** find_if  
```cpp
template <class InputIterator, class UnaryPredicate>
InputIterator std::find_if(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `find_if` searches for the first element in the range [first, last) for which the unary predicate `pred` returns `true` and returns an iterator to that element. If no such element is found, it returns `last`.


### Personal Notes With Examples
The `std::for_each` algorithm applies a unary function to each element in the 
container. It uses an iterator ti drive a loop behind the scenes.  
The following statement prints each element in a `std::list` object called 
`sequence` holding integers:
```cpp
std::for_each(std::begin(sequence), std::end(sequence),
		[] (int x) {std::cout << x << " ";});
```

If `sequence` were instead a `std::vector` of integers, this statement would work 
equally well with no changes. Many STL algorithms work seamlessly on a variety of 
the different containers provided by the STL.

```cpp
#include <iostream>
#include <list>
#include <algorithm>


int main()
{
	std::list<int> sequence {5, 22, 6, -3, 8, 4};
	
	// Display the vector
	std::for_each(std::begin(sequence), std::end(sequence), 
			[] (int x) { std::cout << x << " ";});
	std::cout << "\n";

	// Increase each element in the vector by 1
	std::for_each(std::begin(sequence), std::end(sequence), 
			[] (int& x) { x++;});

	// Redisplay the vector
	std::for_each(std::begin(sequence), std::end(sequence), 
			[] (int x) { std::cout << x << " ";});
	std::cout << "\n";
}
```
In the example above, the lambda function passes the parameter `x` by reference; 
this allows the function to modify each element in the sequence.

```cpp
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
```

The `std::iota` function declared in the `<numerics>` header, is a simple but 
handy function that fills a container with ascending numbers. It allows one to 
replace the following code:
```cpp
std::vector<int> sequence(1000);
int count = 0;
for (auto& element : element)
{
	element = count++;
}

```

with 
```cpp
std::vector<int> sequence(1000);
std::iota(std::begin(sequence), std::end(sequence), 0);
```

The `std::find` algorithm locates the element within a container. Given a range 
within a container specified with iterators, the find function returns an iterator
 to the sought object.  
If the object is not present in the container, the function returns the iterator 
object just past the end of the container.
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	std::vector<int> sequence(1000, 0);
	std::iota(std::begin(sequence), std::end(sequence), 0);

	// Look for 567
	auto iter = std::find(std::begin(sequence), std::end(sequence), 567);
	if (iter != std::end(sequence))
	{
		std::cout << *iter << " is present" << "\n";
	}
	else
	{
		std::cout << "567 is not present" << "\n";
	}

	// Look for -200
	iter = std::find(std::begin(sequence), std::end(sequence), -200);
	if (iter != std::end(sequence))
	{
		std::cout << *iter << " is present" << "\n";
	}
	else
	{
		std::cout << "-200 is not present" << "\n";
	}
}
```

The `std::copy` function copies elements from one container to another.  
The `std::transform` function works like `std::copy` except it expects a function 
that may modify the copied elements.  
Both functions require the begin and end iterators from the source container 
and the begin iterator of the destination container.
```cpp
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
```
---

```cpp
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
```

The `std::transform` function is mainly handy in operating the letters in a string.
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main()
{
	std::string name = "Kamau", str = "abcDEF-GHIjkl345qw";
	std::cout << "Before: " << name << "	" << str << "\n";

	std::transform(std::begin(name), std::end(name), std::begin(name),
			[] (unsigned char c) {return std::toupper(c);});
	
	std::transform(std::begin(str), std::end(str), std::begin(str),
			[] (unsigned char c) {return std::toupper(c);});
	
	std::cout << "After: " << name << "	" << str << "\n";
}
```

The standard library provides an special iterator `std::ostream_iterator` that 
enables `std::copy` function to copy the contents of a container to the output 
stream instead of another container.
```cpp
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
```
The `std::ostream_iterator` is a generic class parameterized by the type of object 
the output stream should receive and the delimiter. There the following will work 
equally well:
```cpp
std::copy(std::begin(sequence), std::end(sequence), 
		std::ostream_iterator<int> (fout, " "));
```

The `std::count` counts the number of elements in a container.  
The `std::count_if` counts the number of elements in a container that posses a 
certain property.
```cpp
std::cout << std::count_if(std::begin(sequence), std::end(sequence), 
		[] (int x) { return x % 2 == 0; });
```

A function that returns a boolean result is known as a __predicate__. Some STL 
algorithms, like `std::count_if`, expect a predicate to allow them to process only 
elements from one container to another that satisfy a given predicate. Another 
function is `std::copy_if`.
```cpp
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
```
Predicated do not have to be lambda functions; they can be global named functions 
as well, but lambda functions are often more convenient.
