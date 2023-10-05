#include <iostream>
#include <queue>

int main()
{
	std::priority_queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(4);
	queue.push(15);
	queue.push(15);
	queue.push(4);
	queue.push(7);

	while (!queue.empty())
	{
		std::cout << queue.top() << " ";
		queue.pop();
	}
	std::cout << std::endl;
}
