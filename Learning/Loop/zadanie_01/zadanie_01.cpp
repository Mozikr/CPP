#include <iostream>

using namespace std;

// Napisz program wyświetlający liczby całkowite z przedziału <0,y> (wartość y podaje użytkownik)

int main()
{
	int x;
	cout << "Podaj koniec przedzialu: ";
	cin >> x;

	for (int i = 0; i <= x; i++) {
		cout << i << " ";
	}
	return 0;
}