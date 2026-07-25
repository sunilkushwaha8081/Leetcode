#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        if (n < 0) {
            x = 1 / x;
        }

        long long num = llabs((long long)n);

        double power = 1;

        while (num) {
            if (num & 1) {
                power *= x;
            }

            x *= x;
            num >>= 1;
        }

        return power;
    }
};

int main() {
    Solution sol;

    cout << sol.myPow(2.0, 10) << endl;    // 1024
    cout << sol.myPow(2.0, -2) << endl;    // 0.25
    cout << sol.myPow(2.1, 3) << endl;     // 9.261
    cout << sol.myPow(5.0, 0) << endl;     // 1

    return 0;
}