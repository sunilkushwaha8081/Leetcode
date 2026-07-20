#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();

        if (n < 2)
            return 0;

        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 1; i < n; i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 6, 9, 1};

    cout << "Maximum Gap: " << obj.maximumGap(nums) << endl;

    return 0;
}