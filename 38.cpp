#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string cas(int n) {
        if (n == 1)
            return "1";

        string prev = cas(n - 1);
        string ans = "";
        int count = 1;

        for (int i = 0; i < prev.size(); i++) {
            while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                count++;
                i++;
            }

            ans += to_string(count);
            ans += prev[i];
            count = 1;
        }

        return ans;
    }

    string countAndSay(int n) {
        return cas(n);
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.countAndSay(n) << endl;

    return 0;
}