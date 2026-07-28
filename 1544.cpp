#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans;

        for (char c : s) {
            if (!ans.empty() && abs(ans.back() - c) == 32)
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.makeGood(s) << endl;

    return 0;
}