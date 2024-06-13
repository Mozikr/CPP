#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <ctime>

const int MAX_BUFFER_SIZE = 10;
std::vector<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void producer() {
    std::srand(std::time(nullptr)); // Initialize random number generator
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < MAX_BUFFER_SIZE; });

        int num = std::rand() % 100; // Generate random number
        buffer.push_back(num);
        std::cout << "Produced: " << num << std::endl;

        cv.notify_all();

        if (done) break; // Exit condition for demonstration purposes
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });

        int num = buffer.back();
        buffer.pop_back();
        std::cout << "Consumed: " << num << std::endl;

        cv.notify_all();

        if (done && buffer.empty()) break; // Exit condition for demonstration purposes
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    std::this_thread::sleep_for(std::chrono::seconds(5)); // Run for a certain time
    {
        std::unique_lock<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();

    prod.join();
    cons.join();

    return 0;
}
