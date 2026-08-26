class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void addNode(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            moveToHead(node);
        } else {
            if (mp.size() == cap) {
                Node* lru = popTail();
                mp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addNode(newNode);
        }
    }
};