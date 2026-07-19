#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy nums2 into the extra space at the end of nums1
        for (int j = 0, i = m; j < n; j++, i++) {
            nums1[i] = nums2[j];
        }

        // Sort the merged array
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}