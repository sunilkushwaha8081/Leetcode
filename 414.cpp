#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> arr;

        for (int i : nums) {
            arr.insert(i);
        }

        int n = arr.size();

        if (n < 3)
            return *arr.rbegin();

        auto it = arr.rbegin();
        it++;
        it++;

        return *it;
    }
};