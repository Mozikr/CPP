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

void function()
{
    lock_guard<mutex> lock(mtx);
    //mtx.lock(); //od teraz cały ten mutex jest dostępny tylko dla jednego wątku. Jak jeden wejdzie do funkcji to drugi czeka przed
    for (int i = 0; i < 30; ++i) {
        cout << "function is processing..., thread id: " <<this_thread::get_id()<<"process.." << endl;
    }
   //mtx.unlock();// tutaj konczy się mutex
}

int main()
{
    thread t1(function);
    thread t2(function);
    
    cout << thread::hardware_concurrency() << endl;

    //cout << "main is processing" << endl;

    t1.join();
    t2.join();
    return 0;
}

