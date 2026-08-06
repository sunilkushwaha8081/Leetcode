#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        vector<bool> prime(right + 1, true);

        prime[0] = false;
        if (right >= 1)
            prime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= right; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<int> ans = {-1, -1};

        int prev = -1;
        int minDiff = INT_MAX;

        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                if (prev != -1) {
                    if (i - prev < minDiff) {
                        minDiff = i - prev;
                        ans[0] = prev;
                        ans[1] = i;
                    }
                }
                prev = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int left = 10;
    int right = 30;

    vector<int> ans = sol.closestPrimes(left, right);

    cout << "Closest primes: ";
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}