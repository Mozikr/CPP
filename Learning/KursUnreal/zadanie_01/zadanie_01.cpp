#include <iostream>

using namespace std;

//Napisz program, który oblicza silnię podanej przez użytkownika liczby całkowitej.

int Silnia(int n)
{

    int sum = 1;

    for (int i = 1; i <= n; ++i) {
        sum *= i;
    }
    return sum;
}

int main()
{
    int x;
    cout << "Podaj liczbe do stworzenia silni: ";
    cin >> x;

    cout << "Twoja silnia to: " << Silnia(x);

    
}

