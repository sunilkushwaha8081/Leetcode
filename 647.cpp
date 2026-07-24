#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int expand(string &s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            ans += expand(s, i, i);       // Odd length palindromes
            ans += expand(s, i, i + 1);   // Even length palindromes
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Number of palindromic substrings: "
         << obj.countSubstrings(s) << endl;

    return 0;
}