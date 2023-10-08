# Algorithms of the Standard Library

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


**Algorithm:** for_each  
**Library:** Standard Library
```cpp
template <class InputIterator, class Function>
Function std::for_each(InputIterator first, InputIterator last, Function func);
```
**Explanation:** `for_each` applies the function `func` to each element in the range [first, last). It can be used to perform an operation on each element in a container without the need for an explicit loop.

---

**Algorithm:** iota  
**Library:** Standard Library
```cpp
template <class ForwardIterator, class T>
void std::iota(ForwardIterator first, ForwardIterator last, T value);
```
**Explanation:** `iota` assigns consecutive values to a range of elements, starting from the given `value` and incrementing it for each element in the range. It is useful for initializing sequences with incremental values.

---

**Algorithm:** find  
**Library:** Standard Library
```cpp
template <class InputIterator, class T>
InputIterator std::find(InputIterator first, InputIterator last, const T& value);
```
**Explanation:** `find` searches for the first occurrence of `value` in the range [first, last) and returns an iterator to that element. If the element is not found, it returns `last`.

---

**Algorithm:** copy  
**Library:** Standard Library
```cpp
template <class InputIterator, class OutputIterator>
OutputIterator std::copy(InputIterator first, InputIterator last, OutputIterator result);
```
**Explanation:** `copy` copies elements from the input range [first, last) to the output range starting from `result`. It is often used to duplicate or transfer elements between containers.

---

**Algorithm:** transform  
**Library:** Standard Library
```cpp
template <class InputIterator, class OutputIterator, class UnaryOperation>
OutputIterator std::transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op);
```
**Explanation:** `transform` applies the unary operation `op` to each element in the input range [first1, last1) and stores the results in the output range starting from `result`. It is used for element-wise transformations.

---

**Algorithm:** ostream_iterator  
**Library:** Standard Library
```cpp
template <class T, class CharT = char, class Traits = std::char_traits<CharT>>
class std::ostream_iterator;
```
**Explanation:** `ostream_iterator` is an output iterator that writes values of type `T` to an output stream (e.g., `std::cout`) using the `<<` operator. It is often used for easy output to streams.

---

**Algorithm:** count  
**Library:** Standard Library
```cpp
template <class InputIterator, class T>
typename std::iterator_traits<InputIterator>::difference_type
std::count(InputIterator first, InputIterator last, const T& value);
```
**Explanation:** `count` counts the number of occurrences of `value` in the range [first, last) and returns the count as a result.

---

**Algorithm:** count_if  
**Library:** Standard Library
```cpp
template <class InputIterator, class UnaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type
std::count_if(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `count_if` counts the number of elements in the range [first, last) that satisfy the unary predicate `pred` and returns the count as a result.

---

**Algorithm:** copy_if  
**Library:** Standard Library
```cpp
template <class InputIterator, class OutputIterator, class UnaryPredicate>
OutputIterator std::copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred);
```
**Explanation:** `copy_if` copies elements from the input range [first, last) to the output range starting from `result` if they satisfy the unary predicate `pred`. It is used to selectively copy elements based on a condition.

---

**Algorithm:** shuffle  
**Library:** Standard Library
```cpp
template <class RandomAccessIterator, class RandomNumberGenerator>
void std::shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator&& g);
```
**Explanation:** `shuffle` randomly reorders elements in the range [first, last) using the provided random number generator `g`. It is useful for generating random permutations of elements.

---

**Algorithm:** generate  
**Library:** Standard Library
```cpp
template <class ForwardIterator, class Generator>
void std::generate(ForwardIterator first, ForwardIterator last, Generator gen);
```
**Explanation:** `generate` assigns values generated by the `gen` function to each element in the range [first, last). It is used to fill a range with generated values.

---

**Algorithm:** accumulate  
**Library:** Standard Library
```cpp
template <class InputIterator, class T>
T std::accumulate(InputIterator first, InputIterator last, T init);
```
**Explanation:** `accumulate` computes the sum of all elements in the range [first, last) starting from an initial value `init` and returns the result.

---

**Algorithm:** partition  
**Library:** Standard Library
```cpp
template <class ForwardIterator, class UnaryPredicate>
ForwardIterator std::partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
```
**Explanation:** `partition` reorders the elements in the range [first, last) in such a way that all elements for which the unary predicate `pred` returns `true` come before those for which it returns `false`. It returns an iterator to the first element of the second partition.

---

**Algorithm:** remove  
**Library:** Standard Library
```cpp
template <class ForwardIterator, class T>
ForwardIterator std::remove(ForwardIterator first, ForwardIterator last, const T& value);
```
**Explanation:** `remove` removes all elements with the value `value` from the range [first, last) by shifting the remaining elements to fill the removed positions. It returns an iterator to the new end of the range.

---

**Algorithm:** remove_if  
**Library:** Standard Library
```cpp
template <class ForwardIterator, class UnaryPredicate>
ForwardIterator std::remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
```
**Explanation:** `remove_if` removes all elements from the range [first, last) that satisfy the unary predicate `pred` by shifting the remaining elements to fill the removed positions. It returns an iterator to the new end of the range.

---

**Algorithm:** reverse  
**Library:** Standard Library
```cpp
template <class BidirectionalIterator>
void std::reverse(BidirectionalIterator first, BidirectionalIterator last);
```
**Explanation:** `reverse` reverses the order of elements in the range [first, last). It is used to reverse the contents of a container or a portion of it.

---

**Algorithm:** all_of  
**Library:** Standard Library
```cpp
template <class InputIterator, class UnaryPredicate>
bool std::all_of(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `all_of` checks if the unary predicate `pred` returns `true` for all elements in the range [first, last). It returns `true` if all elements satisfy the predicate

; otherwise, it returns `false`.

---

**Algorithm:** none_of  
**Library:** Standard Library
```cpp
template <class InputIterator, class UnaryPredicate>
bool std::none_of(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `none_of` checks if the unary predicate `pred` returns `false` for all elements in the range [first, last). It returns `true` if none of the elements satisfy the predicate; otherwise, it returns `false`.

---

**Algorithm:** any_of  
**Library:** Standard Library
```cpp
template <class InputIterator, class UnaryPredicate>
bool std::any_of(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `any_of` checks if the unary predicate `pred` returns `true` for at least one element in the range [first, last). It returns `true` if any element satisfies the predicate; otherwise, it returns `false`.

---

**Algorithm:** find_if  
**Library:** Standard Library
```cpp
template <class InputIterator, class UnaryPredicate>
InputIterator std::find_if(InputIterator first, InputIterator last, UnaryPredicate pred);
```
**Explanation:** `find_if` searches for the first element in the range [first, last) for which the unary predicate `pred` returns `true` and returns an iterator to that element. If no such element is found, it returns `last`.
