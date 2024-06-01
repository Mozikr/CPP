#include <iostream>
using namespace std;

namespace my
{
	template<typename T>
	T max(T a, T b)
	{
		return (a > b) ? a : b;
	}
}


int main()
{
	cout << my::max(4, 5);

	return 0;
}
