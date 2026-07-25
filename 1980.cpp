#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    string ans = "";

    void solve(int i, int n, string s, unordered_set<string> &st) {
        if (!ans.empty()) return;

        if (i == n) {
            if (st.find(s) == st.end())
                ans = s;
            return;
        }

        solve(i + 1, n, s + '0', st);
        solve(i + 1, n, s + '1', st);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());

        solve(0, nums.size(), "", st);

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of binary strings: ";
    cin >> n;

    vector<string> nums(n);

    cout << "Enter the binary strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Different Binary String: "
         << sol.findDifferentBinaryString(nums) << endl;

    return 0;
}