#include <iostream>

using namespace std;

//Napisz program, który oblicza silnię podanej przez użytkownika liczby całkowitej.

#define uLONG unsigned long long

uLONG Silnia(uLONG n)
{

    uLONG sum = 1;

    for (uLONG i = 1; i <= n; ++i) 
    {
        sum *= i;
    }
    return sum;
}

int main()
{
    uLONG x;
    cout << "Podaj liczbe do stworzenia silni: ";
    cin >> x;

    cout << "Twoja silnia to: " << Silnia(x);

    return 0;
}

