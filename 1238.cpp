#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;

        for (int i = 0; i < (1 << n); i++) {
            ans.push_back((i ^ (i >> 1)) ^ start);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n, start;
    cout << "Enter n and start: ";
    cin >> n >> start;

    vector<int> result = sol.circularPermutation(n, start);

    cout << "Circular Permutation: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}