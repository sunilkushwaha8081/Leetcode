#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long left = 1, right = 1000000;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            long long apples = 2LL * mid * (mid + 1) * (2 * mid + 1);

            if (apples >= neededApples)
                right = mid;
            else
                left = mid + 1;
        }

        return 8LL * left;
    }
};