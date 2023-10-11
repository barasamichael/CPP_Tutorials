# Memoization
An associative container provides an opportunity to create an arbitrary amount of 
new storage during a program's execution.

```cpp
int fibonacci(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}
```
The function above returns the nth Fibonacci number but _does not scale well_ 
i.e., its execution time grows significantly as its parameter, n, increases.

```cpp
#include <iostream>
#include <map>

std::map<int, int> call_counter;

int fibonacci(int n)
{
	call_counter[n]++;
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}


int main()
{
	std::cout << "fibonacci(35) = " << fibonacci(35) << "\n\n";
	// Report the total number of calls to the fibonacci function
	std::cout << "Argument Calls" << "\n";
	std::cout << "---------------------" << "\n";
	for (auto& counts : call_counter)
	{
		std::cout << " " << counts.first << "        " 
			<< counts.second << "\n";
	}
}
```
```txt
fibonacci(35) = 9227465

Argument Calls
---------------------
 0        5702887
 1        9227465
 2        5702887
 3        3524578
 4        2178309
 5        1346269
 ...
 31        5
 32        3
 33        2
 34        1
 35        1
```
As the `nth` element increases, recursive calls to lower `nth` values increases 
dramatically. We can improve the performance of our `fibonacci` function using a 
technique known as `memoization`.
> __Memoization__ is an algorithm design technique that records the result of a 
specific computation so that result can be used as needed at a later time during 
the algorithm's execution.

It is as if the executing program _makes a note to itself_ or _stores the result 
in a memo_. When this program needs the result of an identical computation in the 
future, it simply reads the memo with the answer it stored earlier.  
In this way, the program avoids repeating the work. 

Memoization is especially useful for problems that consist of subproblems that 
overlap and appear to require multiple computations with identical input.

The following function uses an unordered map to cache the previously computed 
Fibonacci numbers.
```cpp
int fibonacciTwo(int n)
{
	static unordered_map<int, int> memo{{0, 0}, {1, 1}};
	if (n > 1 && memo[n] == 0)
	{
		memo[n] = fibonacciTwo(n - 2) + fibonacciTwo(n - 1);
	}
	return memo[n];
}
```
The `fibonacciTwo` function uses an unordered map as a cache for stored values 
that persist for the duration of the program's execution. Since the `memo` local 
variable is `static`, the runtime environment _creates and initiates it with keys 
0 and 1 before executing the main function_.
```txt
Time: fibonacci = 103478565 msec, fibonacciTwo = 166 msec
```
