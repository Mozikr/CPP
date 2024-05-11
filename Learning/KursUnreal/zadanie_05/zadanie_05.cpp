#include <iostream>

using namespace std;

//Napisz funkcję która obliczy sumę cyfr liczby całkowitej

int SumOfDigits(int number)
{
    int result = 0;

    while (number > 0)
    {
        result += number % 10;
        number /= 10;
    }
    return result;
}

int main()
{
    int x;
    cin >> x;

    cout << "Suma cyfr liczby: " << SumOfDigits(x);
}

