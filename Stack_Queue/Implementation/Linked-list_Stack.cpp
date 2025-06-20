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

class LinkedListStack {
private:
   Node *head;
public:
    LinkedListStack() {
        head = nullptr;
    }
    
    void push(int x) {
        Node *newNode = new Node(x, head);
        head = newNode;
    }
    
    int pop() {
        if(head == nullptr) {
            cout << "Underflow" << endl;
            return 1e9;
        }
        int result = head -> val;
        Node* temp = head;
        head = head -> next;
        delete temp;
        return result;
    }
    
    int top() {
        if(head == nullptr) {
            cout << "Underflow" << endl;
            return 1e9;
        }
        return head -> val;
    }
    
    int size() {
        if(head == nullptr) {
            return 0;
        }
        int cnt = 0;
        Node* temp = head;
        while(temp) {
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    
    return 0;
}