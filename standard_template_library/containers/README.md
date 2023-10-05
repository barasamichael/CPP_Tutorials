# Containers
## __std::array__
The STL provides an equivalent to a static array in its `std::array` class.
```cpp
std::array<int, 10> student_marks;
```

It works similarly to `std::vector` but one is unable to modify it's size 
using/through methods such as _push_back_.

## __std::list__
STL provides the generic `std::list` class and also implements a linked list 
with pointers connecting a node to both its successor node and its predecessor 
node i.e., _doubly linked lists_.

## __std::priority_queue__
A priority queue is a data structure that allows clients to store objects with 
various priorities or rankings. Clients can insert the objects in any order, 
and the priority queue supports very fast insertion and removal operations.

The C++ STL library provides the `std::priority_queue` class.

```cpp
#include <iostream>
#include <queue>

int main()
{
	std::priority_queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(4);
	queue.push(15);
	queue.push(15);
	queue.push(4);
	queue.push(7);

	while (!queue.empty())
	{
		std::cout << queue.top() << " ";
		queue.pop();
	}
	std::cout << std::endl;
}
```

If one wants to change the notion of priority so that lower-valued numbers are 
considered higher priority than larger numbers, the `std::priority_queue` 
class provides the flexibility for them to do so. One must define a special 
class or struct that provides a public method called `operator()`. This method 
must return a _Boolean result_ and accept _two arguments_ of the same type as 
the element held by the priority queue.

```cpp
struct Comparer 
{
	bool operator() (int valueOne, int valueTwo)
	{
		return valueOne < valueTwo;
	}
};
```
This special method is the __function invocation operator__ or __function call 
operator__. It enables the instance of the Comparer class to be used like a 
function.

```cpp
#include <iostream>

struct Comparer 
{
	bool operator() (int valueOne, int valueTwo)
	{
		return valueOne < valueTwo;
	}
};

int main()
{
	Comparer comparer;
	std::cout << std::boolalpha << comparer(2, 3) << std::endl;
	std::cout << std::boolalpha << comparer(3, 2) << std::endl;
	std::cout << std::boolalpha << comparer(3, 3) << std::endl;
}
```

The expression `comparer(2, 3)` looks like a call to the function named `comparer`,
 but it really is just the syntactic sugar for `comparer.operator()(2, 3)`.  
We really are invoking the method named `operator()` on behalf of the object.

By default, the `std::priority_queue` class can store any type of objects that 
can be compared using the `< operator` inclusive of basic numeric types and 
`std::string` objects.

The relational `operators <`, `<=`, `>`, and `>=` have no practical mathematical 
meaning in the context of complex numbers; therefore C++ does not automatically 
support `operator <` comparison between two `std::complex objects`.

Assuming one has a + b _i_ and c + d _i_ to be two complex numbers. One can 
define a + b _i_ to have higher priority than c + d _i_ if the distance 
between a + b _i_ and 0 on the complex plane is less than distance between 
c + d _i_ and 0.

The distance between $a + bi$ and 0 is \sqrt{a^2 + b^2}
The distance between $c + di$ and 0 is \sqrt{c^2 + d^2}

Custom Comparer objects allow one to place items in a priority queue that 
inherently are not numerical themselves. Suppose one is writing part of a 
messaging system that processes text messages. In addition to the text in the 
message, each message has a priority integer in the range 0 ... 10. Lower 
numbered messages have priority over messages with higher numbers.

## Conclusion
__Vectors__, __arrays__, __lists__, and __priority_queues__ are all sequence 
containers i.e., their elements appear in linear ordering from the beginning of 
the data structure to its end.
