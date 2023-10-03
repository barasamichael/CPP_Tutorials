#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
bool less_than(const T& a, const T& b)
{
	return a < b;
}

template <typename T>
bool greater_than(const T& a, const T& b)
{
	return a > b;
}

template <typename T>
void selection_sort(vector<T>& vec, bool(*compare)(const T&, const T&))
{
	int n = vec.size();
	for (int i = 0; i < n - 1; i++)
	{
		int small = i;
		for (int j = i + 1; j < n; j++)
		{
			if (compare(vec[j], vec[small]))
			{
				small = j;
			}
		}
		if (i != small)
		{
			// Swap function provided by the utility library
			swap(vec[i], vec[small]);
		}
	}
}

template <typename T>
void print(const vector<T>& vec)
{
	int n = vec.size();
	cout << "{ ";
	if (n > 0)
	{
		cout << vec[0];
		for (int i = 1; i < n; i++)
		{
			cout << ", " << vec[i];
		}
	}
	cout << " }";
}

int main()
{
	vector<int> list {23, -3, 4, 215, 0, -3, 2, 23, 100, 88, -10};
	cout << "Original: ";
	print(list);
	cout << endl;

	selection_sort(list, less_than<int>);
	cout << "Ascending: ";
	print(list);
	cout << endl;

	selection_sort(list, greater_than<int>);
	cout << "Descending: ";
	print(list);
	cout << endl;
	cout << "----------------------------------------------------------" << endl;

	vector<string> words {"tree", "girl", "boy", "apple", "dog", "cat", "bird"};
	cout << "Original: ";
	print(words);
	cout << endl;

	selection_sort(words, less_than<string>);
	cout << "Ascending: ";
	print(words);
	cout << endl;

	selection_sort(words, greater_than<string>);
	cout << "Descending: ";
	print(words);
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
}
