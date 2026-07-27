#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> st;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (right - left > indexDiff) {
                st.erase(st.find(nums[left]));
                left++;
            }

            auto it = st.lower_bound((long long)nums[right] - valueDiff);

            if (it != st.end() && *it <= (long long)nums[right] + valueDiff)
                return true;

            st.insert(nums[right]);
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 1};
    int indexDiff = 3;
    int valueDiff = 0;

    if (obj.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}