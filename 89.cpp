#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;

        for (int i = 0; i < (1 << n); i++) {
            ans.push_back(i ^ (i >> 1));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> result = sol.grayCode(n);

    cout << "Gray Code sequence: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}