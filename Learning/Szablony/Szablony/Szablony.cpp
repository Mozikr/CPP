#include <iostream>
using namespace std;


namespace myprogram
{
    template<typename T>
    T max(T a, T b)
    {
        return (a > b) ? a : b;
    }


    int main()
    {
        cout << myprogram::max(4, 5);

        return 0;
    }
}