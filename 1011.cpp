#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool possible(vector<int>& weights, int days, int capacity) {

        int day = 1;
        int load = 0;

        for (int w : weights) {

            if (load + w <= capacity) {
                load += w;
            }
            else {
                day++;
                load = w;
            }
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (possible(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main() {

    Solution s;

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << s.shipWithinDays(weights, days) << endl;

    return 0;
}