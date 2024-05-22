#include <iostream>

using namespace std;
/*
● Napisz klasę reprezentującą liczbę zespoloną
● Klasa powinna zawierać:
    ○ Konstruktory: domyślny, parametryczny i kopiujący
    ○ Destruktor
    ○ Przeładowane operatory: +, -, *, /, =
    ○ metodę Print() służącą do wyświetlania liczby
● W funkcji main() przeprowadź testy zaimplementowanych operacji
*/

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber() : real(0), imaginary(0) {}
    ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}
    ComplexNumber(const ComplexNumber& other) : real(other.real), imaginary(other.imaginary) {}

    ~ComplexNumber() {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber((real * other.real) - (imaginary * other.imaginary),
            (real * other.imaginary) + (imaginary * other.real));
    }

    ComplexNumber operator/(const ComplexNumber& other) const {
        double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
        double realPart = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
        double imaginaryPart = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
        return ComplexNumber(realPart, imaginaryPart);
    }

    ComplexNumber& operator=(const ComplexNumber& other) {
        if (this != &other) {
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }

    void Print() const {
        if (imaginary == 0) {
            cout << real << endl;
        }
        else if (imaginary > 0) {
            cout << real << " + " << imaginary << "i" << endl;
        }
        else {
            cout << real << " - " << -imaginary << "i" << endl;
        }
    }

};

int main() {
    ComplexNumber num1(3, 4);
    ComplexNumber num2(1, -2);
    ComplexNumber result;

    result = num1 + num2;
    cout << "Suma: ";
    result.Print();

    result = num1 - num2;
    cout << "Różnica: ";
    result.Print();

    result = num1 * num2;
    cout << "Iloczyn: ";
    result.Print();

    result = num1 / num2;
    cout << "Iloraz: ";
    result.Print();

    return 0;
}
