#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string s1, string s2) {
        if (s1 == s2)
            return true;

        if (s1.size() != s2.size())
            return false;

        string key = s1 + " " + s2;
        if (dp.count(key))
            return dp[key];

        int n = s1.size();

        // Character frequency check
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return dp[key] = false;

        for (int i = 1; i < n; i++) {

            // Without Swap
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i)))
                return dp[key] = true;

            // With Swap
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};

int main() {
    Solution obj;

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    if (obj.isScramble(s1, s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}