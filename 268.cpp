#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int sum = 0;
        int n = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        for (int i = 0; i < n; i++) {
            total += i;
        }

        return total - sum;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 0, 1};

    cout << "Missing Number: " << obj.missingNumber(nums) << endl;

    return 0;
}