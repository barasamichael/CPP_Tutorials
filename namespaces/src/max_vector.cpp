#include <iostream>
#include <vector>

using namespace std;


/**
 * Counts the number of occurences of the max value in a non-empty vector,
 *	sequence
 */
int max(const vector<int>& sequence)
{
	// p points to the first element
	auto p = std::begin(sequence);

	// Determine the maximum value
	// Set m to first element and move p
	int m = *p++;
	while (p != std::end(sequence))
	{
		if (*p > m)
		{
			m = *p;
		}
		p++;
	}

	// Count the number of times the maximum appears
	int count = 0;
	for (auto element : sequence)
	{
		if (element == m)
		{
			count++;
		}
	}
	return count;
}

/**
 * Return true if all the elements in vector, sequence appear in a non-decreasing
 * order; otherwise, return false
 */
bool is_sorted(const vector<int>& sequence)
{
	for (unsigned index = 0; index < sequence.size() - 1; index++)
	{
		if (sequence[index] > sequence[index + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << boolalpha << is_sorted({1, 2, 3, 4, 5}) << "\n";
	cout << boolalpha << is_sorted({5, 4, 3, 2, 1}) << "\n";
	cout << boolalpha << is_sorted({5, 5, 5, 5, 5}) << "\n";
	cout << "---------------\n";
	cout << max({1, 2, 3, 4, 5}) << "\n";
	cout << max({5, 4, 3, 2, 1}) << "\n";
	cout << max({5, 5, 5, 5, 5}) << "\n";
}
