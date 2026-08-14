#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; i++) {
            // Update from right to left
            for (int j = i - 1; j >= 1; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};

int main() {
    Solution s;

    int rowIndex;
    cin >> rowIndex;

    vector<int> result = s.getRow(rowIndex);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}