#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> first;
        first[0] = -1;   // Empty prefix

        int mask = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            // Toggle the bit corresponding to current digit
            mask ^= (1 << (s[i] - '0'));

            // Case 1: All digits have even count
            if (first.count(mask))
                ans = max(ans, i - first[mask]);
            else
                first[mask] = i;

            // Case 2: Exactly one digit has odd count
            for (int b = 0; b < 10; b++) {
                int newMask = mask ^ (1 << b);
                if (first.count(newMask))
                    ans = max(ans, i - first[newMask]);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.longestAwesome(s) << endl;

    return 0;
}