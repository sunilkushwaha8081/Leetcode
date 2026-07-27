#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
    int cap, minFreq;

    unordered_map<int, pair<int, int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIter;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValFreq.find(key) == keyValFreq.end())
            return -1;

        int value = keyValFreq[key].first;
        int freq = keyValFreq[key].second;

        // Remove from current frequency list
        freqList[freq].erase(keyIter[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        // Increase frequency
        keyValFreq[key].second++;
        freqList[freq + 1].push_front(key);
        keyIter[key] = freqList[freq + 1].begin();

        return value;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            get(key);   // Update frequency
            return;
        }

        // Cache full: remove LFU key
        if (keyValFreq.size() == cap) {
            int evict = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyValFreq.erase(evict);
            keyIter.erase(evict);
        }

        // Insert new key
        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};

int main() {
    LFUCache obj(2);

    obj.put(1, 1);
    obj.put(2, 2);

    cout << obj.get(1) << endl; // 1

    obj.put(3, 3);              // Evicts key 2
    cout << obj.get(2) << endl; // -1
    cout << obj.get(3) << endl; // 3

    obj.put(4, 4);              // Evicts key 1
    cout << obj.get(1) << endl; // -1
    cout << obj.get(3) << endl; // 3
    cout << obj.get(4) << endl; // 4

    return 0;
}