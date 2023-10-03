#include <iostream>

using namespace std;

template <typename T, int N>
T scale(const T& value)
{
	return value * N;
}

int main()
{
	cout << scale<double, 3>(5.3) << endl;
	cout << scale<int, 4>(10) << endl;
}
