#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> dp;

    vector<string> solve(string s, unordered_set<string>& st) {
        if (dp.count(s))
            return dp[s];

        vector<string> ans;

        if (s.empty()) {
            ans.push_back("");
            return ans;
        }

        for (int i = 1; i <= s.size(); i++) {
            string left = s.substr(0, i);

            if (st.count(left)) {
                vector<string> temp = solve(s.substr(i), st);

                for (string x : temp) {
                    if (x == "")
                        ans.push_back(left);
                    else
                        ans.push_back(left + " " + x);
                }
            }
        }

        return dp[s] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(s, st);
    }
};

int main() {
    Solution obj;

    string s;
    int n;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of words in dictionary: ";
    cin >> n;

    vector<string> wordDict(n);

    cout << "Enter dictionary words:\n";
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    vector<string> ans = obj.wordBreak(s, wordDict);

    cout << "\nPossible Sentences:\n";
    for (string x : ans) {
        cout << x << endl;
    }

    return 0;
}