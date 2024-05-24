#include <iostream>

using namespace std;

//Napisz funkcję która przyjmuje dwie tablice znaków przez wskaźnik i zamienia je miejscami.

void SwapCharArray(char* tab1, char* tab2, int size)
{
    for (int i = 0; i < size; ++i)
    {
        char temp = tab1[i];
        tab1[i] = tab2[i];
        tab2[i] = temp;
    }
}

int main()
{
    char TAB1[] = "tutaj";
    char TAB2[] = "slowo";

    SwapCharArray(TAB1, TAB2, 5);

    cout << TAB1 << endl << TAB2;
}
