#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {

        vector<int> ans;

        for (auto &q : queries) {

            int k = q[0];
            int trim = q[1];

            vector<pair<string, int>> temp;

            for (int i = 0; i < nums.size(); i++) {

                string s = nums[i].substr(nums[i].size() - trim);

                temp.push_back({s, i});
            }

            sort(temp.begin(), temp.end());

            ans.push_back(temp[k - 1].second);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> nums = {"102", "473", "251", "814"};
    vector<vector<int>> queries = {
        {1, 1},
        {2, 3},
        {4, 2},
        {1, 2}
    };

    vector<int> result = obj.smallestTrimmedNumbers(nums, queries);

    cout << "Answer: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}