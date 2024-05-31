#include <iostream>
using namespace std;

struct Point
{
	float x = 0;
	float y = 0;
};

Point MovePoint(Point point, Point vector)
{
	Point result;
	result.x = point.x + vector.x;
	result.y = point.y + vector.y;
	return result;
}

enum Animal : char
{
	Cat,
	Dog,
	Lion,
};

enum class Mammal
{
	Cat,
	Dog,
	Lion,
};

int main()
{
	/*Point p;
	p.x = 10.2;
	p.y = 21.2;

	Point result = MovePoint(p, Point{ 5,5 });

	cout << result.x << " " << result.y << endl;*/

	Animal animal = Cat;
	cout << sizeof(Cat);
	return 0;
}
