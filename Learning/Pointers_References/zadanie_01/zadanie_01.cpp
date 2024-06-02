#include <iostream>

using namespace std;

//Napisz funkcję która przyjmuje dwie zmienne typu int przez wskażnik i zamienia je miejscami.
void MySwapPointers(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MySwapRef(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{
    int first = 10;
    int second = 15;

    int third = 30;
    int fourth = 60;

    cout << first << " " << second << endl;

    MySwapPointers(&first, &second);

    cout << first << " " << second << endl;

    cout << endl;

    cout << third << " " << fourth << endl;

    MySwapRef(third, fourth);

    cout << third << " " << fourth << endl;
}
