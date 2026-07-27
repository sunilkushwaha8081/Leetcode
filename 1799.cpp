#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int dp[1 << 14];

    int solve(vector<int>& nums, int mask, int op) {
        int n = nums.size();

        if (mask == (1 << n) - 1)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                continue;

            for (int j = i + 1; j < n; j++) {
                if (mask & (1 << j))
                    continue;

                int newMask = mask | (1 << i) | (1 << j);

                ans = max(ans,
                          op * gcd(nums[i], nums[j]) +
                          solve(nums, newMask, op + 1));
            }
        }

        return dp[mask] = ans;
    }

    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 1);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5, 6};

    int result = obj.maxScore(nums);

    cout << "Maximum Score: " << result << endl;

    return 0;
}