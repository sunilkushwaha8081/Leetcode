#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n > 0) {
            count = count + (n % 2);
            n = n / 2;
        }

        return count;
    }
};

int main() {
    Solution obj;

    uint32_t n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Number of 1 bits = " << obj.hammingWeight(n) << endl;

    return 0;
}