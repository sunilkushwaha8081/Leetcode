#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> arr;

        // Store 32 bits
        for (int i = 0; i < 32; i++) {
            arr.push_back(n % 2);
            n /= 2;
        }

        uint32_t ans = 0;

        // Build reversed number
        for (int i = 0; i < 32; i++) {
            ans = ans * 2 + arr[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;

    uint32_t n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Reversed bits value = " << obj.reverseBits(n) << endl;

    return 0;
}