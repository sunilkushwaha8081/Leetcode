#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (color[i] != 0) continue;

            color[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int neighbor : graph[cur]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[cur];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[cur]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph = {
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };

    cout << sol.isBipartite(graph) << endl;

    return 0;
}