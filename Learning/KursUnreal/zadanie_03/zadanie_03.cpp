#include <iostream>

using namespace std;

//Napisz funkcję która obliczy średnia arytmetyczną z wartości w tablicy typu int.

int Srednia(int tab[], int size) 
{
    int sum = 0;

    for (int i = 0; i < size; ++i)
    {
        sum += tab[i];
    }
    cout << "Suma: " << sum << endl;

    return sum / size;
}


int main()
{
    int tab[] = { 1, 2, 3, 4, 5 };

    cout << "Srednia: " << Srednia(tab, 5);

    return 0;
}

