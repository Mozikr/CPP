#include <iostream>

using namespace std;

//Napisz funkcję która przyjmuje przez wskaźnik tablicę typu int i dodaje do każdego elementu danę liczbę.

void AddToArray(int* tab, int size, int number)
{
    for (int i = 0; i < size; ++i)
    {
        tab[i] += number;
    }
}

int main()
{
    int TAB[5] = { 1,2,3,4,5 };

    AddToArray(TAB, 5, 2);

    for (int i = 0; i < 5; ++i)
    {
        cout << TAB[i] << " ";
    }

    return 0;
}
