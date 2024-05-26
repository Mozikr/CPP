#include <iostream>
using namespace std;

//Stworzyc klasę Car z polem speed typu int i metodami Drive(), Stop(), Accelerate().

class Car
{
public: 

    void Drive()
    {
        cout << "Brum Brum" << endl;
    }

    void Stop()
    {
        speed = 0;
        cout << "Stop" << endl;
    }

    void Accelerate(float a)
    {
        speed += a;
        cout << "Accelerate by: " << a << endl;
    }

private:
    float speed = 0;
};

int main()
{
    Car car;

    car.Accelerate(15);
    car.Drive();
    car.Stop();
}
