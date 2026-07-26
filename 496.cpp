#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        stack<int> st;

        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int x : nums1)
            ans.push_back(mp[x]);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}