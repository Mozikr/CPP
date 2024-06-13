#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_BUFFER_SIZE = 10;
vector<int> buffer;
mutex mtx;
condition_variable cv;
bool done = false;

void producer() {
    srand(time(nullptr));
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(100));
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < MAX_BUFFER_SIZE; });

        int num = rand() % 100;
        buffer.push_back(num);
        cout << "Produced: " << num << endl;

        cv.notify_all();

        if (done) break;
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });

        int num = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << num << endl;

        cv.notify_all();

        if (done && buffer.empty()) break;
    }
}

int main() {
    thread prod(producer);
    thread cons(consumer);

    this_thread::sleep_for(chrono::seconds(5));
    {
        unique_lock<mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();

    prod.join();
    cons.join();

    return 0;
}
