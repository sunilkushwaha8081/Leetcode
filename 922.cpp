#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());

        int even = 0;
        int odd = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans[even] = nums[i];
                even += 2;
            } else {
                ans[odd] = nums[i];
                odd += 2;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {4, 2, 5, 7};

    vector<int> result = obj.sortArrayByParityII(nums);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}