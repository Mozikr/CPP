#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "hello world";
    cout << str << endl;
    cout << "Dlugosc: " << str.length() << endl;
    string str2 = " how is your day?";
    str += str2;
    cout << str << endl;
    string substr = str.substr(0, 5);
    cout << substr << endl;
    
    if (string::npos == str.find("hello")) //npos komunikuje ze nie znaleziono czegos
    {
        cout << "Not found" << endl;
    }
    else cout << "Found it" << endl;
}
