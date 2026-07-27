#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        // Move accessed node to the front
        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }
        else if (cache.size() == capacity) {
            int lastKey = cache.back().first;
            mp.erase(lastKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

int main() {
    LRUCache obj(2);

    obj.put(1, 1);
    obj.put(2, 2);

    cout << obj.get(1) << endl; // 1

    obj.put(3, 3);              // Evicts key 2
    cout << obj.get(2) << endl; // -1

    obj.put(4, 4);              // Evicts key 1
    cout << obj.get(1) << endl; // -1
    cout << obj.get(3) << endl; // 3
    cout << obj.get(4) << endl; // 4

    return 0;
}