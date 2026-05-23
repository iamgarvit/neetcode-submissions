struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove_node(Node* node_to_remove) {
        Node* prevNode = node_to_remove->prev;
        Node* nextNode = node_to_remove->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert_node(Node* node_to_insert) {
        Node* temp = head->next;
        node_to_insert->next = temp;
        node_to_insert->prev = head;
        head->next = node_to_insert;
        temp->prev = node_to_insert;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())   return -1;

        Node* temp = cache[key];
        remove_node(temp);
        insert_node(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* to_remove = cache[key];
            remove_node(to_remove);
            cache.erase(to_remove->key);
            delete to_remove;
        }
        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            remove_node(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        insert_node(newNode);
        cache[key] = newNode;
    }
};
