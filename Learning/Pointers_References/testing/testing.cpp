#include <iostream>
using namespace std;

//project do testów/nauki/follow the course

int main()
{   // Wskaźniki
    cout << "WSKAZNIKI" << endl;
    cout << endl;
    int i = 10;
    int* wsk = &i;

    cout << "Adres zmiennej: "<< wsk << endl; // wyświetli adres
    cout << "Zawartosc: "<< *wsk << endl; // wyświetli 10
    cout << "Wielkosc w bitach: " << sizeof(*wsk) << endl; //wyswietla wielkosc adresu
    //4 = system 32 bo 4* 8 bajtow
    //8 = system 64 bo 8*8 bajtow

    // & - operator adresu, zwraca adres zmiennej
    // * - operator wysłuskania, zwraca zmienną, na którą
    // wskazuje wskaźnik
    cout << endl;
    // Referencje
    cout << "REFERENCJE" << endl;
    cout << endl;
    //referencja do zmiennej jest jej aliasem, inną nazwą już istniejącej zmiennje
    int x = 10;
    int& ref = x;

    cout << x << endl; //wyświetli 10
    cout << ref << endl;//wyświetli 10


    
}

