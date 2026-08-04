#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        for (int mask = 0; mask < (1 << n); mask++) {

            vector<int> temp;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    temp.push_back(nums[i]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.subsets(nums);

    cout << "Subsets are:\n";

    for (auto subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}