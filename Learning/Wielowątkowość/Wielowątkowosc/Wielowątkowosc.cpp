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

/*
using namespace std;

mutex mtx;
mutex mtx2;

void SharedPrint(string s)
{

    unique_lock<mutex> lock(mtx);
    //  lock_guard<mutex> lock2(mtx);

    cout << s;

    lock.unlock();


    cout << "to juz nie jest chronione";

    lock.lock();

    cout << "to jest znowu chronione";
}


void SharedPrint2(string s)
{
    cout << s;
}


class LogFile // RAII
{
public:
    LogFile()
    {
        file.open("log.txt");
    }

    ~LogFile()
    {
        file.close();
    }

    void LogString(string log) const
    {
        lock_guard<mutex> lock(mtx);

        file << log << endl;
    }

private:
    mutable ofstream file;
    mutable mutex mtx;

};



LogFile logFile;

void function()
{
    for (int i = 0; i < 100; ++i)
    {
        SharedPrint("processing 1");
    }

}

void function2()
{
    for (int i = 0; i < 100; ++i)
    {
        SharedPrint2("processing 2");
    }
}

int main()
{
    std::thread t1(function);
    std::thread t2(function2);

    //cout << t1.get_id() << endl;
    //cout << t2.get_id() << endl;


    //cout << "Cores: " << thread::hardware_concurrency() << endl;
      /*  for (int i = 0; i < 100; ++i)
        {

            cout << "main is processing" << endl;
        }

    t1.join();
    t2.join();

    //  logFile.LogString("main function call");


    return 0;
}*/
using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void Wait()
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, []() { return ready; }); // spurious wake
    cout << "Waken up! " << endl;
}


void Notify()
{
    this_thread::sleep_for(chrono::seconds(5));

    {
        lock_guard<mutex> lock(mtx);
        ready = true;
    }

    cv.notify_all();
}


int main()
{
    cout << "Starting..." << endl;
    std::thread t1([]() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() { return ready; }); // spurious wake
        cout << "Waken up! " << endl;

        });

    std::thread t2(Wait);
    std::thread t3(Wait);
    std::thread t4(Wait);
    std::thread t5(Notify);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();



    // sortowanie lambdą
    vector<int> array = { 1,8,0,3,6,1,7,-9 };

    sort(array.begin(), array.end(), [](int a, int b) {

        return a > b;
        });

    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << " ";
    }

    return 0;
}
