#include <iostream>
using namespace std;

//deklaracja klasy
class Car //nazwa klasy
{

public: //modyfikator dostepu
	Car() //kontruktor
	{
		speed = 0;
		cout << "Car is created" << endl;
	}

	Car(float s) //kontruktor inicjalizujący
	{
		speed = s;
		cout << "Car is created with speed" << endl;
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
};

int main()
{
	Car car; //utworzenie instancji klasy(obiektu)
	car.Drive();//wywołanie metody klasy
	car.SetSpeed(20);//odwołanie się do pola klasy
	cout << car.GetSpeed() << endl;
}
