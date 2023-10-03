#include <iostream>
#include "linked_list.h"

int main()
{
	bool done = false;
	char command;
	int value;

	/**
	 * Instantiates an actual class where each instance of Type becomes an 
	 * integer. Also declares int to be an oject to this instantiated class
	 */
	LinkedList<int> list;
	while (!done)
	{
		print_separator();
		std:: cout << "|                              |" << std::endl;
		std:: cout << "|           MAIN MENU          |" << std::endl;
		std:: cout << "|                              |" << std::endl;
		print_separator();
		std::cout << std::endl;
		std::cout << "I)nsert <item> " << std::endl;
		std::cout << "D)elete <item> " << std::endl;
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
					list.insert(value);
				}
				else
				{
					done = true;
				}
				break;

			case 'D':
			case 'd':
				std::cout << "Enter the value to removed: ";
				if (std::cin >> value)
				{
					if (list.remove(value))
					{
						std::cout << value 
							<< " has been removed from the list" 
							<< std::endl;
					}
					else
					{
						std::cout << value 
							<< " was not found in the list" 
							<< std::endl;
					}
				}
				else
				{
					done = true;
				}
				break;

			case 'P':
			case 'p':
				list.print();
				break;

			case 'E':
			case 'e':
				list.clear();
				break;

			case 'Q':
			case 'q':
				done = true;
				break;
		}
	}
}
