#include <iostream>
#include <queue>
#include <vector>


struct Comparer
{
	bool operator()(int valueOne, int valueTwo)
	{
		return valueTwo < valueOne;
	}
};


int main()
{
	/**
	 * int              - Type of items priority queue holds
	 * std::vector<int> - Type of container that holds the items in queue
	 * Comparer         - Custom comparer class to override default ordering 
	 */
	std::priority_queue<int, std::vector<int>, Comparer> queue;
	queue.push(3);
	queue.push(12);
	queue.push(11);
	queue.push(55);
	queue.push(2);
	queue.push(4);

	while (!queue.empty())
	{
		std::cout << queue.top() << " ";
		queue.pop();
	}
	std::cout << "\n";
}
