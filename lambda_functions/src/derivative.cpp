#include <iostream>
#include <iomanip>
#include <functional>


/**
 * Approximates the derivative of a function, f given an h value
 * The closer h is to zero, the better the estimate
 */
std::function <double (double)> get_derivative (
		std::function<double (double)> f, double h)
{
	return [f, h] (double x) { return (f(x + h) - f(x))/h; };
}

/**
 * The function we wish to differentiate
 */
double function(double x)
{
	return 3 * x * x + 5;
}


/**
 * The known derivative of function, function
 */
double answer(double x)
{
	return 6 * x;
}


int main()
{
	// Difference: Approximation better as h -> 0
	double h = 0.0000001;

	// Compute the function representing an approximation of the derivative of
	// the function
	auto derivative = get_derivative(function, h);

	// Compare the computed derivative to the exact derivative derived 
	// symbolically
	double x = 5.0;
	std::cout << "------------------------------------------------------\n";
	std::cout << "                                   Approx.     Actual \n";
	std::cout << "    x        f(x)         h         f\'(x)      f\'(x)\n";
	std::cout << "------------------------------------------------------\n";

	while (x < 5.1)
	{
		std::cout << std::fixed << std::showpoint << std::setprecision(5);
		std::cout << x << "    " << function(x) << "    " << h << "    "
			<< derivative(x) << "    " << answer(x) << "\n";
		x += 0.01;
	}
}
