#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    bool isValid(const string &s, int l, int r) {
        if (l > r) return false;

        // leading zero check
        if (s[l] == '0' && l != r) return false;

        int num = 0;
        for (int i = l; i <= r; i++) {
            num = num * 10 + (s[i] - '0');
            if (num > 255) return false;
        }

        return true;
    }

    void backtrack(string &s, int idx, int dots, string current) {
        if (dots == 4 && idx == s.size()) {
            current.pop_back(); // remove last '.'
            result.push_back(current);
            return;
        }

        if (dots >= 4) return;

        for (int len = 1; len <= 3; len++) {
            if (idx + len > s.size()) break;

            if (isValid(s, idx, idx + len - 1)) {
                backtrack(s, idx + len, dots + 1,
                          current + s.substr(idx, len) + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtrack(s, 0, 0, "");
        return result;
    }
};

int main() {
    Solution sol;

    string s = "25525511135";

    vector<string> ips = sol.restoreIpAddresses(s);

    for (auto &ip : ips) {
        cout << ip << endl;
    }

    return 0;
}