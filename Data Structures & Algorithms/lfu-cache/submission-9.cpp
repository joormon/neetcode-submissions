class process {
    int key;
    int value;
    int freq;
    process* next;
    process* prev;

    friend class LFUCache;
    friend class DoubleLinkedList;

   public:
    process(int key, int value) {
        this->key = key;
        this->value = value;
        freq = 1;
        next = nullptr;
        prev = nullptr;
    }
    ~process() = default;
};

class DoubleLinkedList {
    process* head;
    process* tail;
    int size;
    friend class LFUCache;

   public:
    DoubleLinkedList() {
        head = new process(-1, -1);
        tail = new process(-1, -1);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    void insertAtFront(process* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }

    void remove(process* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        if (size) size--;
    }

    process* removeLRU() {
        if (size == 0) return nullptr;
        process* node = tail->prev;
        remove(node);
        return node;
    }

    ~DoubleLinkedList() {
        delete head;
        delete tail;
    };
};

class LFUCache {
    unordered_map<int, process*> keyMap;
    unordered_map<int, DoubleLinkedList*> freqMap;
    int minFreq = 1;
    int capacity;

   public:
    LFUCache(int capacity) { this->capacity = capacity; }

    void updateList(process* node, unordered_map<int, DoubleLinkedList*>& freqMap) {
        // Removing the node from the freqency list with older freq
        int freq = node->freq;
        DoubleLinkedList* list = freqMap[freq];
        list->remove(node);

        // if a freq has an empty list then minfreq becomes exactly next freq
        if (freq == minFreq && list->size == 0) minFreq++;

        // Inserting the node in a list with updated frequency
        node->freq++;
        freq = node->freq;
        if (freqMap.count(freq))
            list = freqMap[freq];
        else {
            list = new DoubleLinkedList();
            freqMap[freq] = list;
        }

        list->insertAtFront(node);
    }

    int get(int key) {
        if (!keyMap.count(key)) return -1;
        process* node = keyMap[key];
        updateList(node, freqMap);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyMap.count(key)) {
            process* node = keyMap[key];
            node->value = value;
            updateList(node, freqMap);
            return;
        }

        if (keyMap.size() == capacity) {
            DoubleLinkedList* list = freqMap[minFreq];
            process* lru = list->removeLRU();
            keyMap.erase(lru->key);
            delete lru;
        }

        process* node = new process(key, value);
        keyMap[key] = node;
        if (!freqMap.count(node->freq)) freqMap[node->freq] = new DoubleLinkedList();
        freqMap[node->freq]->insertAtFront(node);
        minFreq = 1;
    }

    ~LFUCache() {
        for (auto& entry : keyMap) {
            delete entry.second;
        }

        for (auto& entry : freqMap) {
            delete entry.second;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */