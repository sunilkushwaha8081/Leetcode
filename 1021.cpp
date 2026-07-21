#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        for (char ch : s) {
            if (ch == '(') {
                if (!st.empty()) {
                    ans += ch;
                }
                st.push(ch);
            } else {
                st.pop();
                if (!st.empty()) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.removeOuterParentheses(s) << endl;

    return 0;
}