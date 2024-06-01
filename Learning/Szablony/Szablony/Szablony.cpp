#include <iostream>
using namespace std;

namespace my
{
	template<typename T>
	T max(T a, T b)
	{
		return (a > b) ? a : b;
	}

	template<typename T>
	class Container
	{
	public:
		T array[10];
		int size = 10;
	};

	template<>
	class Container<float>
	{
	public:
		float array[20];
		int size = 20;
	};

}


int main()
{
	cout << my::max(4, 5) << endl;

	my::Container<int> pojemnik;

	for (int i = 0; i < pojemnik.size; ++i)
	{
		pojemnik.array[i] = i;
		cout << pojemnik.array[i] << " ";
	}
	
	cout << endl;
	my::Container<char> pojemnik_char;

	for (int i = 0; i < pojemnik_char.size; ++i)
	{
		pojemnik_char.array[i] = 'a' + i;
		cout << pojemnik_char.array[i] << " ";
	}

	cout << endl;
	my::Container<float> pojemnik_float;

	for (int i = 0; i < pojemnik_float.size; ++i)
	{
		pojemnik_float.array[i] = i + 0.3f;
		cout << pojemnik_float.array[i] << " ";
	}
	return 0;
}
