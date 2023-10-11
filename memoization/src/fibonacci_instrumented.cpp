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
