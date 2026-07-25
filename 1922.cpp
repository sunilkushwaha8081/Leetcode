#include <iostream>
using namespace std;

class Solution {
public:
    const int M = 1000000007;

    long long power(long long b, long long e, long long ans) {
        if (e == 0)
            return ans;

        if (e & 1)
            return power(b, e - 1, (ans * b) % M);
        else
            return power((b * b) % M, e / 2, ans);
    }

    int countGoodNumbers(long long n) {
        long long temp = power(20, n / 2, 1);

        if (n & 1)
            return (temp * 5) % M;

        return temp;
    }
};

int main() {
    Solution sol;

    cout << sol.countGoodNumbers(1) << endl;   // 5
    cout << sol.countGoodNumbers(4) << endl;   // 400
    cout << sol.countGoodNumbers(50) << endl;  // Large value modulo 1e9+7

    return 0;
}