#include <iostream>

using namespace std;

//Napisz funkcje która sprawdzi czy dana tablica znaków jest palindromem.

bool isPalindrom(char tab[])
{
    int size = strlen(tab);

    int range = size / 2;

    for(int i =0; i < range; ++i)
    {
        if (tab[i] != tab[size - i - 1])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    char tab[255];
    cin >> tab;

    cout << "IsPalindrom: " << isPalindrom(tab);

    return 0;
}
