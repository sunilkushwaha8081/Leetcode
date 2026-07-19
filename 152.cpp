#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {

            int product = 1;

            for (int j = i; j < n; j++) {

                product *= nums[j];
                ans = max(ans, product);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2, 3, -2, 4};

    int result = obj.maxProduct(nums);

    cout << "Maximum Product Subarray = " << result << endl;

    return 0;
}