#include <iostream>
#include <queue>
#include <complex>

using Complex = std::complex<double>;


struct ComplexComparer
{
	bool operator()(Complex valueOne, Complex valueTwo)
	{
		double a = valueOne.real(), b = valueOne.imag();
		double c = valueTwo.real(), d = valueTwo.imag();

		return sqrt((a*a + b*b) < (c*c + d*d));
	}
};


int main()
{
	std::priority_queue <Complex, std::vector<Complex>, ComplexComparer> queue;
	
	queue.push({3, 2});
	queue.push({12, 3});
	queue.push({11, 5});
	queue.push({5, 45});
	queue.push({2, 1});
	queue.push({2.4, 5.4});

	while (!queue.empty())
	{
		std::cout << queue.top() << " ";
		queue.pop();
	}
	std::cout << "\n";
}
