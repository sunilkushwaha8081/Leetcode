#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans ^= (start + 2 * i);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n, start;
    cout << "Enter n and start: ";
    cin >> n >> start;

    cout << "Result: " << obj.xorOperation(n, start) << endl;

    return 0;
}