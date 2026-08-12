#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {

        int n = arr.size();

        // Step 1: Find the first decreasing point from the right
        int i = n - 2;

        while (i >= 0 && arr[i] <= arr[i + 1]) {
            i--;
        }

        // No smaller permutation exists
        if (i < 0) {
            return arr;
        }

        // Step 2: Find the largest element on the right
        // that is smaller than arr[i]
        int j = n - 1;

        while (arr[j] >= arr[i]) {
            j--;
        }

        // Handle duplicates:
        // move left to the first occurrence of this value
        while (j > 0 && arr[j] == arr[j - 1]) {
            j--;
        }

        // Step 3: Swap
        swap(arr[i], arr[j]);

        return arr;
    }
};