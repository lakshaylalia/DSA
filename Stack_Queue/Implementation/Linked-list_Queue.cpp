#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int val, Node* next = nullptr) {
        this -> val = val;
        this -> next = next;
    }
};

class LinkedListQueue {
private:
    Node* start;
    Node* end;

public:
    LinkedListQueue() {
        start = nullptr;
        end = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (start == nullptr) {
            start = end = newNode;
        } else {
            end->next = newNode;
            end = newNode;
        }
    }

    int pop() {
        if (start == nullptr) {
            cout << "Underflow" << endl;
            return 1e9;
        }
        int result = start->val;
        Node* temp = start;
        start = start->next;
        if (start == nullptr) {
            end = nullptr;
        }
        delete temp;
        return result;
    }

    int front() {
        if (start == nullptr) {
            cout << "Underflow" << endl;
            return 1e9;
        }
        return start->val;
    }

    int size() {
        int count = 0;
        Node* temp = start;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isEmpty() {
        return start == nullptr;
    }
};

int main() {
    
    return 0;
}