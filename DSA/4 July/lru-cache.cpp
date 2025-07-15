class LRUCache {
public:
    unordered_map<int, int> mpp;
    vector<int> recent;
    int s;

    LRUCache(int capacity) {
        s = capacity;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            updateRecent(key);
            return mpp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.size() >= s && mpp.find(key) == mpp.end()){
            int lru = recent.front();
            recent.erase(recent.begin());
            mpp.erase(lru);
        }
        mpp[key] = value;
        updateRecent(key);
    }

   void updateRecent(int key) {
        for (auto it = recent.begin(); it != recent.end(); ++it) {
            if (*it == key) {
                recent.erase(it);
                break;
            }
        }
        recent.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */