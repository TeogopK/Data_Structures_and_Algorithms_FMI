class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> keysToIters;
    list<pair<int, int>> items;
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto iter = keysToIters.find(key);
        if (iter == keysToIters.end()) {
            return -1;
        }

        int value = iter->second->second;
        items.erase(iter->second);
        items.push_front({ key, value });

        keysToIters.erase(iter);
        keysToIters[key] = items.begin();
        return value;
    }

    void put(int key, int value) {
        auto iterToIter = keysToIters.find(key);
        if (iterToIter != keysToIters.end()) {
            items.erase(iterToIter->second);
            keysToIters.erase(iterToIter);
        }

        items.push_front({ key, value });
        keysToIters[key] = items.begin();

        if (keysToIters.size() > capacity) {
            auto iterToIter = keysToIters.find(items.rbegin()->first);
            keysToIters.erase(iterToIter);
            items.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */