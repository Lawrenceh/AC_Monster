class LRUCache {
private:
    list<int> seq; // list of keys, ordered by latest to least recent
    pair<int, list<int>::iterator > p; // <value, iter> pairs in cache
    unordered_map<int, pair<int, list<int>::iterator > > cache; // cache storing keys and their corresponding pairs
    
    int _cap;
    
    void touch(unordered_map<int, pair<int, list<int>::iterator > >::iterator it) {
        seq.erase(it->second.second);
        seq.push_front(it->first);
        it->second.second = seq.begin();
    }
    
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.first = value;
            touch(it);
        } else {
            if (cache.size() == _cap) {
                auto pk = seq.back();
                seq.pop_back();
                cache.erase(pk);
            }
            seq.push_front(key);
        }
        // after touching update the value
        cache[key] = make_pair(value, seq.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
