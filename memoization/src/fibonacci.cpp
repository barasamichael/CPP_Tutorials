#include <unordered_map>
#include "fibonacci.h"


Integer fibonacci(unsigned n)
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


Integer fibonacciTwo(unsigned n)
{
	static std::unordered_map<unsigned, Integer> memo{{0, 0}, {1, 1}};
	if (n > 1 && memo[n] == 0)
	{
		memo[n] = fibonacciTwo(n - 2) + fibonacciTwo(n - 1);
	}
	return memo[n];
}


