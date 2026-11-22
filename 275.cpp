
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count = 0;
        int n = citations.size();

        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());

        for (int i = 0; i < n; i++) {
            if (citations[i] >= i + 1) {
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> citations = {3, 0, 6, 1, 5};

    cout << obj.hIndex(citations) << endl;

    return 0;
}
