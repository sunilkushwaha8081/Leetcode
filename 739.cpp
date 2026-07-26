#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> results(temps.size(), 0);
        stack<int> st; // Stores indices

        for (int i = 0; i < temps.size(); i++) {

            while (!st.empty() && temps[st.top()] < temps[i]) {
                results[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return results;
    }
};

int main() {
    Solution obj;

    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = obj.dailyTemperatures(temps);

    cout << "Result: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}