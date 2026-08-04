#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {

        int x = start ^ goal;
        int count = 0;

        while (x) {
            x = x & (x - 1);
            count++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    int start, goal;

    cout << "Enter start: ";
    cin >> start;

    cout << "Enter goal: ";
    cin >> goal;

    cout << "Minimum Bit Flips = " << obj.minBitFlips(start, goal) << endl;

    return 0;
}