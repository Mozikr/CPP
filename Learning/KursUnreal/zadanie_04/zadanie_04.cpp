#include <iostream>

using namespace std;

//Napisz funkcję która w tablicy znakowej zamienia małe litery na wielkie i na odwrót

void ToggleChar(char tab[], int size)
{
    int gap = 'a' - 'A';

    for(int i = 0; i < size; ++i)
    {
        if(tab[i] >= 'a' && tab[i] <= 'z')
        {
            tab[i] -= gap;
        }
        else if(tab[i] >= 'A' && tab[i] <= 'Z'){
            tab[i] += gap;
        }
    }


}

int main()
{
    char tab[] = "aaalFAbeTt";
    
    cout << "napis przed: " << tab << endl;

    ToggleChar(tab, 10);

    cout << "napis po: " << tab << endl;
    return 0;
}

