#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {

        stack<int> st;
        st.push(n);
        n--;

        int op = 0;

        while (n > 0) {

            if (op == 0) {
                int x = st.top();
                st.pop();
                st.push(x * n);
            }
            else if (op == 1) {
                int x = st.top();
                st.pop();
                st.push(x / n);
            }
            else if (op == 2) {
                st.push(n);
            }
            else {
                st.push(-n);
            }

            op = (op + 1) % 4;
            n--;
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution s;

    int n = 10;

    cout << s.clumsy(n) << endl;

    return 0;
}