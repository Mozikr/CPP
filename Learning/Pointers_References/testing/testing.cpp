#include <iostream>
using namespace std;

//project do testów/nauki/follow the course

int main()
{
    int i = 10;
    int* wsk = &i;

    cout << wsk; // wyświetli adres
    cout << *wsk; // wyświetli 10

    // & - operator adresu, zwraca adres zmiennej
    // * - operator wysłuskania, zwraca zmienną, na którą
    // wskazuje wskaźnik
    //testowanie
}

