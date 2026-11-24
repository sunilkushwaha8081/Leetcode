#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {

        stack<int> st1;
        stack<string> st2;

        string ans = "";
        int num = 0;

        for(int i = 0; i < s.length(); i++) {

            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {
                st1.push(num);
                st2.push(ans);

                num = 0;
                ans = "";
            }

            else if(s[i] == ']') {

                int k = st1.top();
                st1.pop();

                string temp = st2.top();
                st2.pop();

                while(k--) {
                    temp += ans;
                }

                ans = temp;
            }

            else {
                ans += s[i];
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;
    cin >> s;

    cout << obj.decodeString(s) << endl;

    return 0;
}