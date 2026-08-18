#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }

        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int index = mp[val];
        int last = nums.back();

        nums[index] = last;
        mp[last] = index;

        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

int main() {
    RandomizedSet rs;

    cout << rs.insert(1) << endl;     // 1
    cout << rs.insert(2) << endl;     // 1
    cout << rs.insert(1) << endl;     // 0

    cout << rs.remove(1) << endl;     // 1
    cout << rs.remove(3) << endl;     // 0

    cout << rs.getRandom() << endl;   // 2

    return 0;
}