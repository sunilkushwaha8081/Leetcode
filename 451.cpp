#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Sort according to frequency
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freq[a] == freq[b])
                return a < b;          // Alphabetical order if same frequency
            return freq[a] > freq[b];  // Higher frequency first
        });

        return s;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = obj.frequencySort(s);

    cout << "String after frequency sort: " << result << endl;

    return 0;
}