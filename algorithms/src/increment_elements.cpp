#include <iostream>
#include <list>
#include <algorithm>


int main()
{
	std::list<int> sequence {5, 22, 6, -3, 8, 4};
	
	// Display the vector
	std::for_each(std::begin(sequence), std::end(sequence), 
			[] (int x) { std::cout << x << " ";});
	std::cout << "\n";

	// Increase each element in the vector by 1
	std::for_each(std::begin(sequence), std::end(sequence), 
			[] (int& x) { x++;});

	// Redisplay the vector
	std::for_each(std::begin(sequence), std::end(sequence), 
			[] (int x) { std::cout << x << " ";});
	std::cout << "\n";
}
