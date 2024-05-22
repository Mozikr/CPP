#include <iostream>

using namespace std;
// Napisz funkcję która przyjmuje dwie zmienne typu int przez wskaznik i zamienia je miejscami.
void MySwapPointers(int* a, int*b) //wkaznik
{
	if (a && b) 
	{
		int temp = *a; //operujemy na adresach, wyłuskując mamy dostep do oryginalnych zmiennych bo mamy ich adresy
		*a = *b;	//wyłuskiwanie
		*b = temp;
	}
}

void MySwapRef(int& a, int& b)
{
	if (a && b) 
	{
		int temp = a;
		a = b;
		b = temp;
	}
}


int main()
{
	int A = 10;
	int B = 15;

	int C = 200;
	int D = 400;

	MySwapPointers(&A, &B);

	MySwapRef(C, D);

	cout << A << " " << B;
	cout << "\n";
	cout << C << " " << D;
}

