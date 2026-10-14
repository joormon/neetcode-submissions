class process {
    int key;
    int value;
    int count;
    process* next;
    process* prev;
    friend class LFUCache; // Give LRUCache access to private members
public:
    process(int key, int value) {
        this->key = key;
        this->value = value;
        count = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class LFUCache {
    unordered_map<int, process*> mp;
    process* dh;
    process* dt;
    int capacity;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        dh = new process(-1, -1);
        dt = new process(-1, -1);
        dh->next = dt;
        dt->prev = dh;
    }

    process* minFreq(process* head, process* tail) {
        process* minfreq = nullptr;
        int minValue = INT_MAX;
        head = head->next;
        while (head != tail) {
            if (head->count <= minValue) {
                minfreq = head;
                minValue = head->count;
            }
            head = head->next;
        }
        return minfreq;
    }

    void remove(process* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtFront(process* node) {
        node->next = dh->next;
        node->prev = dh;
        dh->next->prev = node;
        dh->next = node;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        process* node = mp[key];
        node->count++;
        remove(node);
        insertAtFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
            
        if (mp.count(key)) {
            process* node = mp[key];
            node->value = value;
            node->count++;
            remove(node);
            insertAtFront(node);
            return;
        }

        if (mp.size() == capacity) {
            process* node = minFreq(dh, dt);
            mp.erase(node->key);
            remove(node);
            delete node;
        }

        process* node = new process(key, value);
        mp[key] = node;
        insertAtFront(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */