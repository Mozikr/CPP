#include <iostream>
using namespace std;

//Napisz funkcję która przyjmuje jako parametr tablicę typu int i zwróci za pomocą referencji 3 największe wartośc tej tablicy (WHAAAT)
//referencje moga sluzyc do zwracania wiecej niz jeden element z funckji

void ThreeBigest(int tab[], int size, int& max1, int& max2, int& max3)
{
    max1 = max2 = max3 = INT_MIN;

    for (int i = 0; i < size; ++i)
    {
        const int& current = tab[i];

        if (current > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = current;
        }
        else if (current > max2)
        {
            max3 = max2;
            max2 = current;
        }
        else if (current > max3)
        {
            max3 = current;
        }
    }
}

int main()
{
    int TAB[10] = { 1, 2, 4, 6, 7, 9, 0, 22, 100, 76 };

    int a, b, c;

    ThreeBigest(TAB, 10, a, b, c);

    cout << a << " " << b << " " << c;
}

