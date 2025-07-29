#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    
    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        if(node->prev) node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;
        if(node == head) head = node->next;
        if(node == tail) tail = node->prev;
    }

    void addToHead(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if(head) head->prev = node;
        head = node;
        if(tail == nullptr) tail = node;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = tail = nullptr;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            if(cache.size() == capacity) {
                cache.erase(tail->key);
                removeNode(tail);
                delete tail;
            }
            Node* newNode = new Node(key, value);
            addToHead(newNode);
            cache[key] = newNode;
        }
    }
};


int main() {
    
    return 0;
}