# Associative Containers
One limitation of vectors and arrays is that retrieval and location of elements 
is based on position(index). At times this is awkward and inefficient.  
In contrast, __associative containers__ permit access based on a key rather than 
an index. Additionally, a key is not restricted to an integer expression.

C++ provides a variety of container classes in the Standard Template Library (STL) 
to store and manage collections of objects. These containers can be categorized 
into the following main types:

1. __Sequence Containers__
   - __std::vector__: A dynamic array that allows efficient random access and 
	dynamic resizing.
   - __std::list__: A doubly-linked list for fast insertions and deletions in the 
	middle.
   - __std::deque__: A double-ended queue, which combines the benefits of arrays 
	and linked lists.

2. __Associative Containers__
   - __std::set__: A sorted container of unique values.
   - __std::multiset__: A sorted container of values allowing duplicates.
   - __std::map__: A sorted container of key-value pairs.
   - __std::multimap__: A sorted container of key-value pairs allowing duplicate 
	keys.
   - __std::unordered_set__: An unordered (hash-based) container of unique values.
   - __std::unordered_multiset__: An unordered container of values allowing 
	duplicates.
   - __std::unordered_map__: An unordered (hash-based) container of key-value 
	pairs.
   - __std::unordered_multimap__: An unordered container of key-value pairs 
	allowing duplicate keys.

3. __Container Adapters__
   - __std::stack__: A container adapter for creating a stack(LIFO) data structure.
   - __std::queue__: A container adapter for creating a queue(FIFO) data structure.
   - __std::priority_queue__: A container adapter for creating a priority queue.

4. __Array Containers__
   - __std::array__: A fixed-size array with a standard interface.
   - __std::bitset__: A container for managing arrays of bits with efficient 
	bitwise operations.

5. __String Class__
   - __std::string__: A container for working with strings of characters. It is a 
	part of the STL and provides string manipulation functions.

6. __Specialized Containers__
   - __std::valarray__: A container for numerical arrays with mathematical 
	operations.
   - __std::forward_list__: A singly-linked list with forward-only traversal.

These containers serve various purposes and have different characteristics. 
Choosing the right container for a specific task is crucial for optimizing 
performance and code readability. Each container type provides a specific 
interface and operations that are best suited for particular use cases.


Here's a summary of when to use various C++ containers and when not to use them, depending on different scenarios:

1. __std::vector__
   - Use when you need a dynamic array with quick random access.
   - Don't use when you frequently insert or remove elements in the middle, as it 
	can be inefficient due to shifting elements.

2. __std::list__
   - Use when you need frequent insertions and removals in the middle of a 
	collection.
   - Don't use when you need fast random access to elements, as it doesn't 
	support direct indexing.

3. __std::deque__
   - Use when you need a double-ended queue with efficient insertions and 
	deletions at both ends.
   - Don't use when you require random access to elements in the middle of the 
	container, as it can be less efficient than `std::vector`.

4. __std::map__ and __std::unordered_map__
   - Use `std::map` when you need a sorted associative container (based on keys).
   - Use `std::unordered_map` when you need a fast key-value lookup, and the 
	order of elements doesn't matter.
   - Don't use when you don't need key-value pairs or when you need a simple 
	array or list.

5. __std::set__ and __std::unordered_set__
   - Use `std::set` when you need a sorted set of unique elements.
   - Use `std::unordered_set` when you need a fast set of unique elements, and 
	the order doesn't matter.
   - Don't use when you need multiple occurrences of the same element.

6. __std::stack__ and __std::queue__
   - Use `std::stack` when you need a last-in, first-out (LIFO) data structure.
   - Use `std::queue` when you need a first-in, first-out (FIFO) data structure.
   - Don't use when the order of elements doesn't matter, or when you need more 
	advanced data structures like a priority queue.

7. __std::priority_queue__
   - Use when you need a priority queue data structure for efficient retrieval of 
	the highest-priority element.
   - Don't use when you don't need prioritization of elements.

8. __std::array__
   - Use when you need a fixed-size array with elements of the same type.
   - Don't use when you require a dynamically resizable container.

9. __std::string__
   - Use when working with strings of characters.
   - Don't use for general-purpose storage of other data types.

10. __Custom Containers__
    - Use when none of the standard containers fit your specific requirements.
    - Don't use if you can achieve your goals with existing standard containers, 
	as custom containers may require more maintenance and testing.

The `std::set` data type models to some extent a mathematical set i.e., are 
unordered and may contain no duplicate values. C++ std::set objects ignore any 
attempt to include duplicate elements but do order their elements internally in a 
particular way. This ordering permits very fast access to elements.
