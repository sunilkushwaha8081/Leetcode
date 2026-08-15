#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& current, int i) {

        // Current subset ko answer mein add karo
        ans.push_back(current);

        for (int j = i; j < nums.size(); j++) {

            // Same level par duplicate skip karo
            if (j > i && nums[j] == nums[j - 1])
                continue;

            // Include
            current.push_back(nums[j]);

            solve(nums, ans, current, j + 1);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        // Duplicates ko paas-paas lane ke liye
        sort(nums.begin(), nums.end());

        solve(nums, ans, current, 0);

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = s.subsetsWithDup(nums);

    for (auto subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}