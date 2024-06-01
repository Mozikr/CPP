#include <iostream>

using namespace std;
//Napisz funkcję szablonową max, która przyjmuje dwa argumenty dowolnego typu i zwraca większy z nich.

template<typename T>
T maxNumber(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;
    cout << "Podaj pierwszy argument funkcji: " << endl;
    cin >> a;
    system("cls");
    cout << "Podaj drugi argument funkcji: " << endl;
    cin >> b;
    system("cls");
    cout << maxNumber(a,b);
}