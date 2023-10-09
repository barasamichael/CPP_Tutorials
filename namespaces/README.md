# Namespaces

## Preamble
The disadvantages of using the blanket `using` directive
```cpp
using namespace std;
```
outweighs its occassional convenience.

Using it can present problems at times because the `std` namespace contains 
hundreds of type and function names, and it is too easy for a programmer to 
accidentally reuse for another purpose a name already claimed by the `std` 
namespace.

Such name conflicts lead to problems during software development, and since the 
development process generally has enough other challenges to address; best practice
 is to avoid the blanket `using` directive.
```cpp
#include <iostream>
#include <vector>

using namespace std;


/**
 * Counts the number of occurences of the max value in a non-empty vector,
 *	sequence
 */
int max(const vector<int>& sequence)
{
	// p points to the first element
	auto p = std::begin(sequence);

	// Determine the maximum value
	// Set m to first element and move p
	int m = *p++;
	while (p != std::end(sequence))
	{
		if (*p > m)
		{
			m = *p;
		}
		p++;
	}

	// Count the number of times the maximum appears
	int count = 0;
	for (auto element : sequence)
	{
		if (element == m)
		{
			count++;
		}
	}
	return count;
}

/**
 * Return true if all the elements in vector, sequence appear in a non-decreasing
 * order; otherwise, return false
 */
bool is_sorted(const vector<int>& sequence)
{
	for (unsigned index = 0; index < sequence.size() - 1; index++)
	{
		if (sequence[index] > sequence[index + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << boolalpha << is_sorted({1, 2, 3, 4, 5}) << "\n";
	cout << boolalpha << is_sorted({5, 4, 3, 2, 1}) << "\n";
	cout << boolalpha << is_sorted({5, 5, 5, 5, 5}) << "\n";
	cout << "---------------\n";
	cout << max({1, 2, 3, 4, 5}) << "\n";
	cout << max({5, 4, 3, 2, 1}) << "\n";
	cout << max({5, 5, 5, 5, 5}) << "\n";
}
```

The C++ standard library contains a function named `is_sorted`, declared in the 
`<algorithm>` header. It performs the same task as our custom made `is_sorted`, 
except that the std function striving to be as generic as possible, accepts two 
iterators instead of the container itself.

The compiler in our case automatically uses the intiator list to create a vector 
object and sends it off to the `max` function for processing.  
When the compiler matches a function call to its corresponding definition, it 
always seeks the best match for the arguments passed.

Since the `std::max` accepts an initiator list, it better matches the calls to 
the main function. To avoid the danger, avoid the `using` directive. Because of the
 missing `std::` prefix the compiler knows that the calls to max cannot be calls 
to std::max.

Ideally, any code meant for widespread use should be part of a namespace. This 
allows for simultaneous and effective management of code within a software system.

To put the functions and types to be part of a namespace is fairly simple.
```cpp
#include <vector>

namespace vecutils {
	int max (const std::vector<int>& sequence);
	bool is_sorted(const std::vector<int>& sequence);
}
```
---
```cpp
#include "vecutils.h"

namespace vecutils{
	int max(const std::vector<int>& sequence)
	{
		auto p = std::begin(sequence);
		int m = *p++;
		while (p != std::end(sequence))
		{
			if (*p > m)
			{
				m = *p;
			}
			p++;
		}
		int count = 0;
		for (auto element : sequence)
		{
			if (element == m)
			{
				count++;
			}
		}
		return count;
	}

	bool is_sorted(const std::vector<int>& sequence)
	{
		for (unsigned index = 0; index < sequence.size() - 1; index++)
		{
			if (sequence[index] > sequence[index + 1])
			{
				return false;
			}
		}
		return true;
	}
}
```
---
```cpp
#include <iostream>
#include "vecutils.h"

int main()
{
	std::cout << std::boolalpha << vecutils::is_sorted({1, 2, 3, 4, 5})
		<< "\n";
	std::cout << std::boolalpha << vecutils::is_sorted({5, 4, 3, 2, 1})
		<< "\n";
	std::cout << "---------------\n";
	std::cout << vecutils::max({1, 2, 3, 4, 5}) << "\n";
	std::cout << vecutils::max({5, 5, 5, 5, 5}) << "\n";
}
```
One should avoid the blanket `using` directive for custom namespaces too.

C++ permits namespaces to be nested, as in
```cpp
namespace utils
{
	namespace graphics
	{
		namespace math
		{
			double function(double value)
			{
				/* Details omitted ... */
			}
		}
	}
}
```

Absent of any using directives, we can call function, function as 
```cpp
std::cout << utils::graphics::math::function(9.4) << "\n";
```

C++ supports namespace aliases, as in:
```cpp
namespace ugm = utils::graphics::math;
```

One can call the function, function with the more compact statements
```cpp
std::cout << ugm::f(9.4) << "\n";
```

Nesting allows developers to organize better the components within libraries: for 
example, a company may have an outer namespace derived from the company's name 
and nested namespaces that correspond to departments or divisions within the 
company.
```sh
g++ -Wall -std=c++17 -o simple simple.cpp
```
