#include <iostream>
#include <string>

using namespace std;

template <typename T>
bool less_than(T a, T b)
{
	return a < b;
}

int main()
{
	cout << less_than(2, 3) << endl;
	cout << less_than(2.2, 2.7) << endl;
	cout << less_than(2.7, 2.2) << endl;

	string word_two = "ABC", word_one = "XYZ";
	cout << less_than(word_one, word_two) << endl;
	cout << less_than(word_two, word_one) << endl;
}
