# Lambda Functions

## Preamble
There are two ways of invoking a function:
1. Using its name
2. As a parameter of another function

```cpp
int evaluate(int (*function)(int, int), int x, int y)
{
	return function(x, y);
}
```
The `evaluate` function calls `function`. It invoked the function passed in from 
the caller. C++ supports the definition of anonymous functions via __lambda 
functions__.

The general form of a lambda expression is 
```cpp
[capture_list] (parameter_list) -> return type {statements}
```

where:
* `capture list` specifies the calling context to which the function has 
	access.
* `parameter list`is a comma-separated list of parameters as in any function 
	definition.
* `return type` is the type of result the function returns.
* `statements` are the statements as one would find in any function definition.

One can use a lambda function in a call to the evaluation function 

```cpp
int val = evaluate([] (int x, int y) -> int {return x * y;}, 3, 2);
```
The first argument is a function that takes two integer parameters.  
When the compiler can deduce the type of the result of a lambda function, one can 
omit the result type:
```cpp
// Results to 600
int val = evaluate([] (int x, int y) {return 3*x*y;}, 10, 20);

// Results to 6
int val = evaluate([] (int x, int y) {return x * y}, 2, 3);

// Prints 10 20
[](int x, int y) {std::cout << x << " " << y << "\n";} (10, 20);
```

The following two statements:
```cpp
auto function = [] (int x) {return 5 * x;};
std::cout << function(10) << "\n";
```
shows how we can assign a lambda function to a variable and invoke it through 
that variable at a later time.

Lambda functions can be used to create __closures__.  
A __closure__ is a unit of code that can capture variables from its sorrounding 
context. These captured variables then can be used outside of their original 
context.

## Exploring Function Objects
A `std::function` object works like a __function pointer__. The `std::function` 
class is a generic class parameterized by function's types specification.  
A function object representing a function that accepts two integer parameters and 
returns an integer result can be declared as 
```cpp
std::function<int (int, int)> function;
```
Function objects take the place of function pointers, which are available in 
both C and C++, with function objects absent in C. Function objects provide the 
capabilities  above simple function pointers, including the ability to manage 
closures.

```cpp
#include <iostream>
#include <functional>

int evaluate2(std::function<int (int, int)> function, int value_x, int value_y)
{
	return function(value_x, value_y);
}


int main()
{
	int value_a;
	std::cout << "Enter an integer value: ";
	std::cin >> value_a;
	std::cout << evaluate2([value_a] (int value_x, int value_y)
		{
			if (value_x == value_a)
			{
				value_x = 0;
			}
			else
			{
				value_y++;
			}
			return value_x + value_y;
		}, 2, 3) << "\n";
}
```
In this case, the `evaluate2` function can see `value_a's` value even though `value_a` is a local to `main` and is not passed to `evaluate2` as an explicit parameter.

One can say the lambda function __captures__ the variable `value_a`. When 
`evaluate2` invokes the function sent by the caller, `evaluate2` has no access to 
a variable named `value_a`. The `value_a` involved in the conditional expression 
is captured from `main`. This is an example of a _closure transporting a captured 
variable into a function call_.

```cpp
#include <iostream>
#include <functional>

std::function <int (int)> make_adder()
{
	int local_value = 2;
	return [local_value] (int value_x) {return value_x + local_value;};
}

int main()
{
	auto function = make_adder();
	std::cout << function(10) << "\n";
	std::cout << function(2) << "\n";
}
```
Ordinarily when a function returns, all of its local variables disappear. This 
means that after the following statement in the main function executes: 
```cpp
auto function = make_adder();
```
`make_adder's` `local_value` variable should no longer exist. The function that 
`make_adder`, however, returns forms a closure that captures `make_adder's` 
local variable `local_value`.

C++'s lambda capture mechanism provides capabilities that go beyond examples given.
For example, the expression `&value` within square brackets would capture variable 
`value` by reference, allowing an external context to modify the variable.  
When a closure captures a variable by reference, _the variable must exist in its 
original context as long as the closure is viable_ i.e., one should not attempt to 
capture a local non-static variable of a function by reference __by a closure__ to 
be returned by that function.  
Local variables disappear when the function returns, and so the references will 
refer to garbage values.

We can assign a variable to a lambda function:
```cpp
auto function = [] (int value_y) { return 2 * value_y;};
std::cout << function(10) << "\n";
```
The function is roughly equivalent to:
```cpp
int function(value_y)
{
	return 2 * value_y;
}
```
While not a particularly useful application of a lambda function, to demonstrate 
the regularity of the C++ language, we can define an anonymous function and 
invoke it immediately; for example, the statement:
```cpp
std::cout << [] (int value_y, int value_x) { return value_x * value_y;} (2, 3);
```

similarly to:
```cpp
std::cout << 2 * 3 << "\n";
std::cout << 6 << "\n";
```

As a more practical example using a lambda function and a closure, consider the 
calculation of a derivative.
 
$$
f'(a) = \lim_{h \to 0} \frac{f(a + h) - f(a)}{h}
$$

Based on the mathematical definition, we can define a C++ function that computes 
the derivative of another function:

```cpp
std::function <double (double)> derivative(
		std::function<double (double)> f, double h)
{
	return [f, h] (double x) { return (f(x + h) - f(x))/h;};
}
```
##### NOTE:
The derivative function returns a function, as a lambda expression is a simple 
function definition. The function that derivative returns is a closure because it 
captures the function parameters `f` and `h`.

Our derivative function allows us to compute the derivative of a function at a given value. This is known as __numerical differentiation__. Another approach is 
__symbolic differentiation__ which transforms the formula for a function into a 
different formula.

$$
f(x) = 3x^2 + 5
$$
$$
f'(x) = 6x
$$

```cpp
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
		std::cout << x << " " << function(x) << " " << h << " "
			<< derivative(x) << " " << answer(x) << "\n";
		x += 0.01;
	}
}
```

In order for `derivative` to compute its answer, it must have access to function, 
`function`. It has this access because `derivative` is a lambda function and `h` 
during  the call to `derivative`.
