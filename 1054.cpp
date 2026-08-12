#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();

        // Frequency count
        unordered_map<int, int> mp;

        for (int x : barcodes) {
            mp[x]++;
        }

        // Find maximum frequency element
        int maxFreq = 0;
        int maxElement = 0;

        for (auto &x : mp) {
            if (x.second > maxFreq) {
                maxFreq = x.second;
                maxElement = x.first;
            }
        }

        vector<int> ans(n);
        int index = 0;

        // Place maximum frequency element first
        while (mp[maxElement] > 0) {
            ans[index] = maxElement;
            mp[maxElement]--;

            index += 2;

            if (index >= n) {
                index = 1;
            }
        }

        // Place remaining elements
        for (auto &x : mp) {
            while (x.second > 0) {
                ans[index] = x.first;
                x.second--;

                index += 2;

                if (index >= n) {
                    index = 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> barcodes = {1, 1, 1, 2, 2, 2};

    vector<int> ans = obj.rearrangeBarcodes(barcodes);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}