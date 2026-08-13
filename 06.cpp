#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;

        vector<string> a(n);
        int r = 0, d = 1;

        for (char c : s) {
            a[r] += c;

            if (r == 0) d = 1;
            if (r == n - 1) d = -1;

            r += d;
        }

        string ans = "";
        for (auto x : a)
            ans += x;

        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    int n;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Converted string: " << sol.convert(s, n) << endl;

    return 0;
}