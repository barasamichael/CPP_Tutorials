#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main()
{
	std::string name = "Kamau", str = "abcDEF-GHIjkl345qw";
	std::cout << "Before: " << name << "	" << str << "\n";

	std::transform(std::begin(name), std::end(name), std::begin(name),
			[] (unsigned char c) {return std::toupper(c);});
	
	std::transform(std::begin(str), std::end(str), std::begin(str),
			[] (unsigned char c) {return std::toupper(c);});
	
	std::cout << "After: " << name << "	" << str << "\n";
}
