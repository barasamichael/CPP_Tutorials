#include <iostream>

struct Comparer 
{
	bool operator() (int valueOne, int valueTwo)
	{
		return valueOne < valueTwo;
	}
};

int main()
{
	Comparer comparer;
	std::cout << std::boolalpha << comparer(2, 3) << std::endl;
	std::cout << std::boolalpha << comparer(3, 2) << std::endl;
	std::cout << std::boolalpha << comparer(3, 3) << std::endl;
}
