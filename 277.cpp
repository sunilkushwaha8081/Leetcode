#include <iostream>
#include <vector>
using namespace std;

// Adjacency matrix representing who knows whom
vector<vector<int>> graph = {
    //0 1 2
    {0, 1, 1}, // Person 0 knows 1 and 2
    {0, 0, 1}, // Person 1 knows 2
    {0, 0, 0}  // Person 2 knows nobody (celebrity)
};

// Simulated LeetCode API
bool knows(int a, int b) {
    return graph[a][b];
}

class Solution {
public:
    int findCelebrity(int n) {
        int celebrity = 0;

        // Find a possible celebrity
        for (int i = 1; i < n; i++) {
            if (knows(celebrity, i))
                celebrity = i;
        }

        // Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i == celebrity)
                continue;

            if (knows(celebrity, i) || !knows(i, celebrity))
                return -1;
        }

        return celebrity;
    }
};

int main() {
    Solution obj;

    int n = 3;

    int ans = obj.findCelebrity(n);

    if (ans == -1)
        cout << "No Celebrity" << endl;
    else
        cout << "Celebrity is Person " << ans << endl;

    return 0;
}