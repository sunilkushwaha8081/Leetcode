#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Foo {
public:
    mutex mtx;
    condition_variable cv;

    bool firstDone = false;
    bool secondDone = false;

    void first() {
        {
            lock_guard<mutex> lock(mtx);

            cout << "first";
            firstDone = true;
        }

        cv.notify_all();
    }

    void second() {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this]() {
            return firstDone;
        });

        cout << "second";
        secondDone = true;

        cv.notify_all();
    }

    void third() {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this]() {
            return secondDone;
        });

        cout << "third";
    }
};

int main() {
    Foo obj;

    // Threads kisi bhi order mein start ho sakte hain
    thread t1(&Foo::third, &obj);
    thread t2(&Foo::first, &obj);
    thread t3(&Foo::second, &obj);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}