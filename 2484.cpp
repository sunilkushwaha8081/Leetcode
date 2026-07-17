#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1000000007;
        int n = s.size();

        vector<vector<vector<long long>>> pre(n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        vector<vector<vector<long long>>> suf(n, vector<vector<long long>>(10, vector<long long>(10, 0)));

        vector<long long> cnt(10, 0);

        // Prefix pairs
        for (int i = 0; i < n; i++) {
            if (i > 0)
                pre[i] = pre[i - 1];

            int d = s[i] - '0';

            for (int x = 0; x < 10; x++)
                pre[i][x][d] += cnt[x];

            cnt[d]++;
        }

        fill(cnt.begin(), cnt.end(), 0);

        // Suffix pairs
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1)
                suf[i] = suf[i + 1];

            int d = s[i] - '0';

            for (int x = 0; x < 10; x++)
                suf[i][d][x] += cnt[x];

            cnt[d]++;
        }

        long long ans = 0;

        for (int i = 2; i <= n - 3; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + pre[i - 1][a][b] * suf[i + 1][b][a]) % MOD;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.countPalindromes(s) << endl;

    return 0;
}