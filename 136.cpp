#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Single Number = " << obj.singleNumber(nums) << endl;

    return 0;
}