#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroinFirstCol = false;

        // Use first row and first column as markers
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][0] == 0)
                zeroinFirstCol = true;

            for (int col = 1; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        // Update the matrix in reverse order
        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = matrix[0].size() - 1; col >= 1; col--) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }

            if (zeroinFirstCol) {
                matrix[row][0] = 0;
            }
        }
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    for (auto &row : matrix) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    obj.setZeroes(matrix);

    cout << "\nMatrix After Setting Zeroes:\n";
    for (auto &row : matrix) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}