#include <iostream>
#include <list>

void print_separator()
{
	std::cout << "--------------------------------"<< std::endl;
}


int main()
{
	bool done = false;
	char command;
	int value;

	/**
	 * Instantiates an actual class where each instance of Type becomes an 
	 * integer. Also declares int to be an oject to this instantiated class
	 */
	std::list<int> myList;
	while (!done)
	{
		print_separator();
		std:: cout << "|                              |" << std::endl;
		std:: cout << "|           MAIN MENU          |" << std::endl;
		std:: cout << "|                              |" << std::endl;
		print_separator();
		std::cout << std::endl;
		std::cout << "I)nsert <item> " << std::endl;
		std::cout << "L)ength        " << std::endl;
		std::cout << "P)rint         " << std::endl;
		std::cout << "E)rase         " << std::endl;
		print_separator();

		std::cout << "Select an action from the menu: ";
		std::cin >> command;
		switch(command)
		{
			case 'I':
			case 'i':
				std::cout << "Enter the value to insert: ";
				if (std::cin >> value)
				{
					myList.push_back(value);
				}
				else
				{
					done = true;
				}
				break;

			case 'P':
			case 'p':
				for (const auto& element : myList)
				{
					std::cout << element << " ";
				}
				std::cout << std::endl;
				break;

			case 'L':
			case 'l':
				std::cout << "Number of elements: "
					<< myList.size() << std::endl;
				break;

			case 'E':
			case 'e':
				myList.clear();
				break;

			case 'Q':
			case 'q':
				done = true;
				break;
		}
	}
}
