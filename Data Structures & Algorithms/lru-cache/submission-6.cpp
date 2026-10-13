class process {
    int key;
    int val;
    process* next;
    process* prev;
    friend class LRUCache;

   public:
    process(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    unordered_map<int, process*> mp;
    process* head;
    process* tail;
    int capacity;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new process(-1, -1);
        tail = new process(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(process* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtfront(process* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;

        process* node = mp[key];
        remove(node);
        insertAtfront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if(mp.count(key)){
            process* node=mp[key];
            node->val=value;
            mp[key]=node;
            remove(node);
            insertAtfront(node);
            return;
        }

        if (mp.size() == capacity) {
            process* lru = tail->prev;
            process* node = mp[lru->key];
            mp.erase(node->key);
            remove(node);
            delete lru;
        }

        process* node = new process(key, value);
        mp[key] = node;
        insertAtfront(node);
    }
};
