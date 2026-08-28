#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // isPal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || isPal[i + 1][j - 1])) {

                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts for s[0...i]
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {

            // Whole substring is palindrome
            if (isPal[0][i]) {
                dp[i] = 0;
            }
            else {
                dp[i] = i;

                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};