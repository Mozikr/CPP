#include <iostream>
using namespace std;

//deklaracja klasy
class Car //nazwa klasy
{

public: //modyfikator dostepu
	Car() //kontruktor
	{
		speed = 0;
		ownersIDS = new int[5] {1, 2, 3, 4, 5};

		cout << "Car is created" << endl;
	}

	Car(float s) : speed(s)//kontruktor inicjalizujący/parametryczny
	{
		//speed = s;
		cout << "Parametric contructor" << endl;
	}

	Car(const Car& other) //kontruktor kopiujący
	{
		speed = other.speed;

		//przepisanie wskaznika/kopiowanie plytkie jak zmienie w jednym to zmieni sie w kazdym (shallow copy)
		//ownersIDS = other.ownersIDS;

		////kopiowanie głębokie (deep copy) zeby usunac wrzucasz delete do destruktora
		//ownersIDS = new int[5];
		//for (int i = 0; i < 5; ++i)
		//{
		//	ownersIDS[i] = other.ownersIDS[i];
		//}

		cout << "Copy contructor is created" << endl;
	}

	~Car()//destruktor
	{
		cout << "Car is destroyed" << endl;
	}


	void Drive()//metoda
	{
		cout << "Brum Brum" << endl;
	}

	float GetSpeed() //getter, pobiera wartości prywatne
	{
		return speed;
	}

	void
		SetSpeed(float s) //setter, ustawia wartości prywatne
	{
		speed = s;
	}

private:
	float speed = 10;//pole
	int* ownersIDS;
};

class Vector
{
public:

	Vector() = default;

	Vector(float x, float y) : m_x(x), m_y(y) {};

	Vector(const Vector& other)
	{
		cout << "copy contructor" << endl;
	}

	Vector operator+(const Vector& other)
	{
		Vector result;
		result.m_x = m_x + other.m_x;
		result.m_y = m_y + other.m_y;

		return result; 
	}

	Vector& operator=(const Vector& other)
	{
		m_x = other.m_x;
		m_y = other.m_y;

		cout << "operator= called" << endl;

		return *this;
	}

	void Print()
	{
		cout << "x: " << m_x << " ";
		cout << "y: " << m_y;
		cout << endl;
	}




private:
	float m_x = 0.0f;
	float m_y = 0.0f;
};

int main()
{
	//Car car; //utworzenie instancji klasy(obiektu)
	//car.Drive();//wywołanie metody klasy
	//car.SetSpeed(20);//odwołanie się do pola klasy
	//cout << car.GetSpeed() << endl;

	//Car car2(car);
	//cout << car2.GetSpeed() << endl;

	Vector a(1, 2);
	Vector b(3, 4);

	Vector c;
	c = a + b;
	a.Print();
	b.Print();
	c.Print();
}
