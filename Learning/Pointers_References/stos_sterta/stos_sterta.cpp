#include <iostream>
using namespace std;

int main()
{
    // new zawsze zwraca adres czyli wsk
    // raw pointer, smart pointery

    int k = 10; //alokowanie na stosie - statyczne
    int* d = new int; // alokowanie na stercie - dynamiczne

    delete d; // zwolnienie pamieci zmiennej d

    // memory leak

    int size;
    cout << "Podaj wielkosc tablicy wskaznikow: ";
    cin >> size;

    int** tab = new int* [size];

    for (int i = 0; i < size; ++i)
    {
        tab[i] = new int[size];
    }

    tab[0][0] = 21;
    cout << tab[0][0];

    for (int i = 0; i < size; ++i)
    {
        delete[] tab[i];
    }delete[] tab;
}// zwolnienie pamieci zmiennej k



