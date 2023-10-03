#include <iostream>
#include "linked_list.h"

int main()
{
	LinkedList<int> intListOne, intListTwo, intListThree;
	for (int i = 10; i < 50; i += 10)
	{
		intListOne.insert(i);
	}

	for (int i = 100; i < 500; i += 100)
	{
		intListTwo.insert(i);
	}

	for (int i = 5; i < 25; i += 5)
	{
		intListThree.insert(i);
	}

	/* Build a list that contains lists of integers */
	LinkedList<LinkedList<int>> listOfLists;
	listOfLists.insert(intListOne);
	listOfLists.insert(intListTwo);
	listOfLists.insert(intListThree);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << listOfLists << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}
