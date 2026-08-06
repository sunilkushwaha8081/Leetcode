#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];

        // Compute prefix XOR array
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] ^ arr[i];
        }

        vector<int> res(queries.size());

        // Answer each query
        for (int k = 0; k < queries.size(); ++k) {
            int i = queries[k][0];
            int j = queries[k][1];

            if (i == 0)
                res[k] = pre[j];
            else
                res[k] = pre[j] ^ pre[i - 1];
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {
        {0, 1},
        {1, 2},
        {0, 3},
        {3, 3}
    };

    vector<int> ans = sol.xorQueries(arr, queries);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}