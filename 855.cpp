#include <iostream>
#include <set>
#include <iterator>

using namespace std;

class ExamRoom {
public:
    int n;
    set<int> seats;

    ExamRoom(int N) {
        n = N;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int dist = *seats.begin();
        int ans = 0;

        auto prev = seats.begin();
        auto it = next(prev);

        while (it != seats.end()) {
            int d = (*it - *prev) / 2;
            if (d > dist) {
                dist = d;
                ans = *prev + d;
            }
            prev = it;
            ++it;
        }

        if (n - 1 - *seats.rbegin() > dist) {
            ans = n - 1;
        }

        seats.insert(ans);
        return ans;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

int main() {
    ExamRoom room(10);

    cout << room.seat() << endl;   // 0
    cout << room.seat() << endl;   // 9
    cout << room.seat() << endl;   // 4
    cout << room.seat() << endl;   // 2

    room.leave(4);

    cout << room.seat() << endl;   // 5

    return 0;
}