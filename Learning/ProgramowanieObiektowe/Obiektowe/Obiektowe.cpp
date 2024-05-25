#include <iostream>
using namespace std;

//deklaracja klasy
class Car //nazwa klasy
{
public: //modyfikator dostepu
    void Drive()//metoda
    {
        cout << "Brum Brum" << endl;
    }
    float speed = 10;//pole
};

int main()
{
    Car car; //utworzenie instancji klasy(obiektu)
    car.Drive();//wywołanie metody klasy
    car.speed = 21;//odwołanie się do pola klasy
    cout << car.speed << endl;
}
