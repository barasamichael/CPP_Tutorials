#include <iostream>
#include <ctime>
#include <functional>

#include "fibonacci.h"

unsigned time_it(const std::function<Integer(unsigned)>& function, 
		unsigned n)
{
	clock_t start_time = clock();
	function(n);
	clock_t end_time = clock();
	return static_cast<unsigned> (end_time - start_time);
}


int main()
{
	auto time_one = time_it(fibonacci, 50);
	auto time_two = time_it(fibonacciTwo, 50);
	std::cout << "Time: fibonacci = " << time_one << " msec, fibonacciTwo = "
		<< time_two << " msec\n";
}
