#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int a : asteroids) {

            bool destroyed = false;

            // Collision occurs only when stack top is moving right
            // and current asteroid is moving left
            while (!st.empty() && st.top() > 0 && a < 0) {

                if (st.top() < -a) {
                    // Stack asteroid explodes
                    st.pop();
                }
                else if (st.top() == -a) {
                    // Both explode
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid explodes
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
                st.push(a);
        }

        // Convert stack to vector
        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> asteroids = {5, 10, -5};

    vector<int> ans = obj.asteroidCollision(asteroids);

    cout << "Remaining Asteroids: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}