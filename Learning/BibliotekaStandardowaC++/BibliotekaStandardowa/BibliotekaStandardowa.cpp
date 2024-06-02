#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


//lepiej przekazywac stringi poprzez referencje, unikamy wtedy kopiowania. A string to tablica wiec
//musiała by się cała kopiować. Optymalizujemy to. A jeśli nie chcemy go modyfikować
//to możemy go oznaczyć poprzez const - > const string& s
//void Fun(string& s)
//{
//
//}

int main()
{
    map<int, string> MAP;

    MAP[123] = "Szymon";
    MAP.emplace(125, "Piotr");
    MAP[234] = "Wojtek";
    MAP.insert(make_pair(236, "Stefan"));

    cout << MAP.size() << endl;

    cout << MAP[125] << endl;
    cout << MAP.at(123) << endl;
    cout << MAP.find(234)->second << endl;


    //string str = "hello world";
    //cout << str << endl;
    //cout << "Dlugosc: " << str.length() << endl;
    //string str2 = " how is your day?";
    //str += str2;
    //cout << str << endl;
    //string substr = str.substr(0, 5);
    //cout << substr << endl;
    //
    //if (string::npos == str.find("hello")) //npos komunikuje ze nie znaleziono czegos
    //{
    //    cout << "Not found" << endl;
    //}
    //else cout << "Found it" << endl;

    //vector<int> numbers; //= { 1,2,3,4,5,6,7,8,9,10 };
    //numbers.reserve(100); //jak wiemy ile bedzie elementow to od razu ustawi capacity na 100
    //
    //for (int i = 0; i < 100; ++i) //i<number.size()
    //{
    //    numbers.push_back(i);
    //    cout << numbers[i] << " ";
    //}

    ////iterator struktura do przechodzenia po kolekcji
    //vector<int>::iterator it = numbers.begin(); //begin początek, rbegin od tyłu
    //while (it != numbers.end()) //sprawdzamy czy iterator nie doszedl do end
    //{
    //    cout << *it << endl;
    //    ++it;
    //}

    ////foreach
    //for (auto& number : numbers)
    //{
    //    cout << number << endl;
    //}

    //cout << endl;
    //cout << numbers.size() << " " << numbers.capacity() << endl; //size - elementy, 
    ////capacity - Zwraca maksymalną liczbę elementów jaką 
    ////może pomieścić kontener bez wykonywania realokacji pamięci.
    //numbers.shrink_to_fit(); // zmniejsza jego capacity(maksymalną liczbę elementów)
    ////przydatne jak wiemy ze vector nie bedzie zmienial swoich wielkosci

    ////usuwanie
    //vector<int>::iterator it2 = numbers.begin();
    //while (it2 != numbers.end())
    //{
    //    if (*it2 == 10)
    //    {
    //        it2 = numbers.erase(it2);
    //    }
    //    else {
    //        cout << *it2 << endl;
    //        ++it2;
    //    }
    //}
    return 0;
    
}
