class LRUCache {
   public:
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator>mp;
    int capacity;
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
       if (mp.find(key) == mp.end())
            return -1;
        
        auto nodeIt = mp[key];
        int nodeValue = nodeIt->second;

        // Move accessed node to front (MRU)
        dll.splice(dll.begin(), dll, nodeIt);

        return nodeValue;
    }

    void put(int key, int value) {
       // Case 1: Key already exists -> Update value and move to front
        if (mp.find(key) != mp.end()) {
            auto nodeIt = mp[key];
            nodeIt->second = value;
            dll.splice(dll.begin(), dll, nodeIt);
            return;
        }

        // Case 2: Cache full -> Evict LRU element BEFORE inserting new one
        if (dll.size() == capacity) {
            int lruKey = dll.back().first;
            mp.erase(lruKey);
            dll.pop_back();
        }

        // Case 3: Insert new element at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
