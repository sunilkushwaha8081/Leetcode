#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                continue;

            int slow = i, fast = i;
            bool forward = nums[i] > 0;

            while (true) {
                int nextSlow = nextIndex(nums, slow);
                int nextFast = nextIndex(nums, fast);

                if ((nums[nextSlow] > 0) != forward ||
                    (nums[nextFast] > 0) != forward)
                    break;

                nextFast = nextIndex(nums, nextFast);

                if ((nums[nextFast] > 0) != forward)
                    break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    if (slow == nextIndex(nums, slow))
                        break;
                    return true;
                }
            }

            // Mark visited
            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == forward) {
                int next = nextIndex(nums, curr);
                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    // Example 1
    vector<int> nums = {2, -1, 1, 2, 2};

    if (obj.circularArrayLoop(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}