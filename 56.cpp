#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto &it : intervals) {

            if (ans.empty() || ans.back()[1] < it[0]) {
                ans.push_back(it);
            } else {
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result = obj.merge(intervals);

    cout << "Merged Intervals:\n";
    for (auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}