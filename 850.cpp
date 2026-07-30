class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {

        const int mod = 1000000007;

        vector<int> x;

        for (auto &r : rectangles) {
            x.push_back(r[0]);
            x.push_back(r[2]);
        }

        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());

        unordered_map<int, int> x_i;

        for (int i = 0; i < x.size(); i++)
            x_i[x[i]] = i;

        vector<int> count(x.size(), 0);

        vector<vector<int>> events;

        for (auto &r : rectangles) {
            events.push_back({r[1], r[0], r[2], 1});
            events.push_back({r[3], r[0], r[2], -1});
        }

        sort(events.begin(), events.end());

        long long area = 0;
        long long curY = events[0][0];
        long long curX = 0;

        for (auto &e : events) {

            long long y = e[0];

            area = (area + (y - curY) * curX) % mod;

            curY = y;

            for (int i = x_i[e[1]]; i < x_i[e[2]]; i++)
                count[i] += e[3];

            curX = 0;

            for (int i = 0; i < x.size() - 1; i++) {
                if (count[i] > 0)
                    curX += x[i + 1] - x[i];
            }
        }

        return area % mod;
    }
};