#include <iostream>

using namespace std;

//Napisz kalkulator :D

int main()
{
    while (true)
    {
        // kontrola uzytkownika
        char i;
        float x, y;
        cout << "Podaj pierwsza liczbe: " << endl;
        cin >> x; //pierwsza zmienna
        cout << "Podaj druga liczbe: " << endl;
        cin >> y; //druga zmienna

        cout << "Wybierz dzialanie (+,-,*,/), 'x' by zakonczyc. " << endl;
        cin >> i;
        //polecenia
        switch (i)
        {
        case '+':
            cout << "Wybrano dodawanie" << endl;
            cout << "Suma: " << x + y << endl;
            break;

        case '-':
            cout << "Wybrano odejmowanie" << endl;
            cout << "Roznica: " << x - y << endl;
            break;

        case '*':
            cout << "Wybrano mnozenie" << endl;
            cout << "Iloczyn: " << x * y << endl;
            break;

        case '/':
            cout << "Wybrano dzielenie" << endl;
            cout << "Iloraz: " << x / y << endl;
            break;

        case 'x':
        case 'X':
            return 0;

        default:
            cout << "Podano niepoprawny symbol" << endl;
            break;
        }
    }
}
