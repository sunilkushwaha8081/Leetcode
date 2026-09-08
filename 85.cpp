#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {

            // Build histogram heights
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangle(height));
        }

        return ans;
    }

    int largestRectangle(vector<int>& h) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= h.size(); i++) {

            int curr = (i == h.size()) ? 0 : h[i];

            while (!st.empty() && h[st.top()] > curr) {

                int height = h[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                ans = max(ans, height * width);
            }

            // Don't push the extra sentinel index
            if (i < h.size())
                st.push(i);
        }

        return ans;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    Solution obj;

    cout << "Maximum rectangle area: "
         << obj.maximalRectangle(matrix) << endl;

    return 0;
}
