#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

using namespace std;

mutex mtx;

void SharedPrint(string s)
{
    lock_guard<mutex> lock(mtx);
    cout << s << endl;
}

void function()
{ 
    for (int i = 0; i < 30; ++i) {
        SharedPrint("function is processing..., thread id: ");
    }
}

class LogFile //klasa do odczytywania plikow
{
public:
    LogFile()//kontruktor otwiera plik
    {
        file.open("log.txt");
    }
    ~LogFile()//destruktor zamyka plik
    {
        file.close();
    }

    void LogString(string log) 
    {
        lock_guard<mutex> lock(mtx);
        file << log << endl;
    }
private:
    ofstream file; //uchwyt na plik
    mutex mtx;
};



int main()
{
    LogFile logFile;

    logFile.LogString("main function call");

    return 0;
}

