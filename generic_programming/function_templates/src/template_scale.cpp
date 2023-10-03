#include <iostream>

using namespace std;

template <int N>
int scale(int value)
{
	return value * N;
}

int main()
{
	cout << scale<3>(5) << endl;
	cout << scale<4>(10) << endl;
}
