#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        // Count frequency
        for (string word : words)
            freq[word]++;

        vector<pair<string, int>> arr;

        for (auto it : freq)
            arr.push_back(it);

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first < b.first;   // Lexicographical order
            return a.second > b.second;     // Higher frequency first
        });

        vector<string> ans;

        for (int i = 0; i < k; i++)
            ans.push_back(arr[i].first);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> words = {
        "i", "love", "leetcode", "i", "love", "coding"
    };
    int k = 2;

    vector<string> result = obj.topKFrequent(words, k);

    cout << "Top " << k << " frequent words:\n";
    for (const string &word : result)
        cout << word << " ";

    cout << endl;
    return 0;
}