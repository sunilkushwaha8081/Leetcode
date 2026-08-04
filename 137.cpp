#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        for (auto i : mp) {
            if (i.second == 1)
                return i.first;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 2, 1};

    cout << "Single Number = " << obj.singleNumber(nums) << endl;

    return 0;
}