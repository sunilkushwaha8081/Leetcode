#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                depth++;
                ans = max(ans, depth);
            }
            else if (ch == ')') {
                depth--;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    int result = obj.maxDepth(s);

    cout << "Maximum Depth = " << result << endl;

    return 0;
}