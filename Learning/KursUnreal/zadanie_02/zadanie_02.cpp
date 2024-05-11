#include <iostream>

using namespace std;

//Napisz funkcję, która znajdzie największy element w tablicy typu int.

int MaxInt(int tab[], int size) 
{
    if (size < 1) {
        return INT_MIN; 
    }

    int max = tab[0];

    for (int i = 0; i < size; i++) {
        if (max < tab[i]) {
            max = tab[i];
        }
    }

    return max;
}

int main()
{
    int tab[] = { 1, 3, 4, 6, 21, 44, 23, 7, 10, 9, 17 };

    cout << "Najwiekszy element: " << MaxInt(tab, 10);

    return 0;
}
