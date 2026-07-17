#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        // Mark invalid parentheses
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = '*';
            }
        }

        // Mark extra '('
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        // Build the final answer
        string ans;
        for (char ch : s) {
            if (ch != '*')
                ans += ch;
        }

        return ans;
    }
};