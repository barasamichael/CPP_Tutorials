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
