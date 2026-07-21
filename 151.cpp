#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        string ans = "";

        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];

            if (i != 0)
                ans += " ";
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    getline(cin, s);   // Reads the entire line including spaces

    cout << obj.reverseWords(s) << endl;

    return 0;
}