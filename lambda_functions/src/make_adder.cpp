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
