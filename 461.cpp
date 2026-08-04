#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        int count = 0;

        while (ans > 0) {
            if (ans & 1)
                count++;

            ans = ans >> 1;
        }

        return count;
    }
};

int main() {
    Solution obj;

    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "Hamming Distance = " << obj.hammingDistance(x, y) << endl;

    return 0;
}