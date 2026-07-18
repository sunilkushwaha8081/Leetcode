#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos;
        vector<int> neg;

        // Separate positive and negative numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        vector<int> ans;

        int p = 0, q = 0;

        // Arrange alternately: positive, negative
        while (p < pos.size() && q < neg.size()) {
            ans.push_back(pos[p++]);
            ans.push_back(neg[q++]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> result = obj.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}