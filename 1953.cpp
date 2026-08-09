#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        long long mx = 0;

        for (int x : milestones) {
            sum += x;
            mx = max(mx, (long long)x);
        }

        long long rest = sum - mx;

        if (mx <= rest + 1)
            return sum;

        return 2 * rest + 1;
    }
};