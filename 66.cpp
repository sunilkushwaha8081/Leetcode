#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;      // Add 1 and return
                return digits;
            }
            digits[i] = 0;        // Carry forward
        }

        // If all digits were 9 (e.g., 999 -> 1000)
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    vector<int> digits = {9, 9, 9};

    Solution obj;
    vector<int> result = obj.plusOne(digits);

    cout << "Result: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}