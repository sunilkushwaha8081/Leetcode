#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int peakIndex = obj.findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element: " << nums[peakIndex] << endl;

    return 0;
}
